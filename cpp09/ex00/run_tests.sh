#!/bin/bash
# Full test suite for btc (BitcoinExchange)
# Run from the directory containing btc, data.csv, and this script.
# Note: several commands below are EXPECTED to return non-zero (error paths),
# so we don't use `set -e` here.

GREEN='\033[0;32m'; RED='\033[0;31m'; YELLOW='\033[1;33m'; NC='\033[0m'
pass() { echo -e "${GREEN}[PASS]${NC} $1"; }
info() { echo -e "${YELLOW}--- $1 ---${NC}"; }

info "1. Build"
make re > /dev/null && pass "compiles clean with -Wall -Wextra -Werror -std=c++98"

info "2. No argument"
./btc
echo "(expected: Error: Invalid number of arguments)"

info "3. Too many arguments"
./btc a b
echo "(expected: Error: Invalid number of arguments)"

info "4. Nonexistent input file"
./btc does_not_exist.txt
echo "(expected: Error: could not open file.)"

info "5. Missing/renamed data.csv"
if [ -f data.csv ]; then mv data.csv data.csv.bak; fi
echo "date | value" > tmp_empty_db_test.txt
./btc tmp_empty_db_test.txt
echo "(expected: Error: could not open database file.)"
if [ -f data.csv.bak ]; then mv data.csv.bak data.csv; fi
rm -f tmp_empty_db_test.txt

info "6. Empty input file"
> empty.txt
./btc empty.txt
echo "(expected: Error: file is empty.)"

info "7. Wrong header line"
printf "not the right header\n2011-01-03 | 1\n" > bad_header.txt
./btc bad_header.txt
echo "(expected: Error: Invalid headar)"

info "8. Subject's exact sample input"
cat > sample.txt << 'EOF'
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
EOF
./btc sample.txt
echo "(compare line by line to the subject's expected output)"

info "9. Date edge cases (leap years, invalid days, malformed date)"
cat > dates.txt << 'EOF'
date | value
2012-02-29 | 1
2011-02-29 | 1
2012-02-30 | 1
2012-13-01 | 1
2012-00-10 | 1
2012-01-00 | 1
2012-1-1 | 1
20120101 | 1
EOF
./btc dates.txt
echo "(2012-02-29 should pass [leap year], 2011-02-29 should fail [not leap],"
echo " 2012-02-30/13-01/00-10/01-00 should fail, malformed ones should fail)"

info "10. Value edge cases (boundaries, decimals, sign, garbage)"
cat > values.txt << 'EOF'
date | value
2011-01-03 | 0
2011-01-03 | 1000
2011-01-03 | 1000.0001
2011-01-03 | -0.01
2011-01-03 | abc
2011-01-03 | 1.2.3
2011-01-03 | 
2011-01-03 |
EOF
./btc values.txt
echo "(0 and 1000 should pass, >1000 -> too large, negative -> not positive,"
echo " abc/1.2.3/empty -> bad input)"

info "11. Missing separator entirely"
printf "date | value\n2011-01-03 3\n" > nosep.txt
./btc nosep.txt
echo "(expected: Error: bad input .)"

info "12. Date not in database at all (before earliest entry)"
DB_FIRST=$(tail -n +2 data.csv | head -1 | cut -d',' -f1)
echo "First DB date is: $DB_FIRST"
cat > before.txt << EOF
date | value
1990-01-01 | 1
EOF
./btc before.txt
echo "(with no earlier DB date to fall back to, check this prints 0 as the result)"

info "13. Closest-lower-date fallback (date between two DB entries)"
echo "Inspect data.csv manually and pick a date between two consecutive DB rows,"
echo "then run: ./btc <file with that date> and confirm it uses the EARLIER rate, not the later one."

info "14. data.csv sanity"
head -3 data.csv
cat -A data.csv | head -3
echo "(look for ^M at line ends = Windows line endings; check delimiter is really ',')"
tail -n +2 data.csv | awk -F',' 'NF != 2 {print "malformed line " NR+1 ": " $0}'
tail -n +2 data.csv | cut -d',' -f1 | sort -c && echo "data.csv dates are sorted"

info "Done. Review output above against the subject's rules manually."
rm -f empty.txt bad_header.txt sample.txt dates.txt values.txt nosep.txt before.txt
