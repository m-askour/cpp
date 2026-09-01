#include "BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange() : Date(""), value(0.0f), exchangeRates()
{
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        exchangeRates = other.exchangeRates;
        value = other.value;
        Date = other.Date;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange()
{
}
static int check_year(long year)
{
    if (year < 1)
        return 1;
    return 0;
}
static int check_month(long month)
{
    if (month < 1 || month > 12)
        return 1;
    return 0;
}
static int is_leap(long year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    return 0;
}
static int check_day(long year, long month, long day)
{
    static const int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12)
        return 1;
    int max_day = days_in_month[month - 1];
    if (month == 2 && is_leap(year))
        max_day = 29;
    if (day < 1 || day > max_day)
        return 1;
    return 0;
}
int check_all_int(const std::string &str)
{
    for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}
int check_all_float(const std::string &str)
{
    int dot_count = 0;
    size_t i = 0;

    if (str.empty())
        return 1;
    if (str[0] == '-' || str[0] == '+')
        i = 1;
    if (i == str.size())
        return 1;
    for (; i < str.size(); ++i)
    {
        if (str[i] == '.')
        {
            dot_count++;
            if (dot_count > 1)
                return 1;
        }
        else if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}

static int is_valid(const std::string &str, int expected_len)
{
    if (static_cast<int>(str.length()) != expected_len)
        return 1;
    return 0;
}
int BitcoinExchange::parsing_Date(std::string Data_stor)
{
    std::string year;
    std::string month;
    std::string day;

    size_t first = Data_stor.find('-');
    size_t second = Data_stor.find('-', first + 1);

    if (first == std::string::npos || second == std::string::npos)
    {
        std::cout << "Error: bad input." << std::endl;
        return 1;
    }
    if (check_all_int(Data_stor.substr(0, first)) || check_all_int(Data_stor.substr(first + 1, second - first - 1)) || check_all_int(Data_stor.substr(second + 1)))
    {
        std::cout << "Error: bad input." << std::endl;
        return 1;
    }
    year = Data_stor.substr(0, first);
    month = Data_stor.substr(first + 1, second - first - 1);
    day = Data_stor.substr(second + 1);
    // check evry thing is it's number befor check is it exist
    if (is_valid(year, 4) || is_valid(month, 2) || is_valid(day, 2))
    {
        std::cout << "Error: bad input." << std::endl;
        return 1;
    }
    long year_int = std::atol(year.c_str());
    long month_int = std::atol(month.c_str());
    long day_int = std::atol(day.c_str());

    if (check_year(year_int) || check_month(month_int) || check_day(year_int, month_int, day_int))
    {
        std::cout << "Error: bad input." << std::endl;
        return 1;
    }

    set_date(Data_stor);

    return 0;
}
int BitcoinExchange::parsing_value(std::string Data_stor)
{
    // convert it from string to float
    if (check_all_float(Data_stor))
    {
        std::cout << "Error: bad input." << std::endl;
        return 1;
    }
    double value_double = strtod(Data_stor.c_str(), NULL);
    float value_float = static_cast<float>(value_double);

    if (value_float < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 1;
    }

    if (value_float > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 1;
    }

    set_value(value_float);
    return 0;
}
int BitcoinExchange::parsing_line(std::string &line)
{
    std::string Date_stor;
    std::string value_stor;
    size_t find = line.find('|');
    if (find == std::string::npos)
    {
        std::cout << "Error: bad input" << " => " << line << std::endl;
        return 1;
    }
    Date_stor = line.substr(0, find);
    size_t last = Date_stor.find_last_not_of(" \t");
    if (last != std::string::npos)
        Date_stor = Date_stor.substr(0, last + 1);
    if (parsing_Date(Date_stor))
        return 1;
    value_stor = line.substr(find + 1);
    size_t first = value_stor.find_first_not_of(" \t");
    if (first != std::string::npos)
        value_stor = value_stor.substr(first);
    if (parsing_value(value_stor))
        return 1;
    return 0;
}
static int first_line(std::string line)
{
    if (line == "date | value")
        return 1;
    return 0;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
    {
        std::cout << "Error: could not open database file." << std::endl;
        return;
    }
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        std::string date = line.substr(0, comma);
        std::string rate = line.substr(comma + 1);
        exchangeRates[date] = static_cast<float>(strtod(rate.c_str(), NULL));//this convert string to const char than to doubel than to float
    }
}

void BitcoinExchange::readFile(const std::string &filename)
{
    loadDatabase("data.csv");
    if (exchangeRates.empty())
    {
        std::cout << "Error: there is no data." << std::endl;
        return;
    }

    std::ifstream file(filename.c_str());
    std::string line;
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    if (!std::getline(file, line))
    {
        std::cout << "Error: file is empty." << std::endl;
        return;
    }
    if (!first_line(line))
    {
        std::cout << "Error: Invalid headar." << std::endl;
        return ;
    }
    while (std::getline(file, line))
    {
        if (parsing_line(line))
            continue;
        std::string Date = get_date();
        float value = get_value();
        float rate = getClosestRate(Date);
        std::cout << Date << " => " << value << " = " << (value * rate) << std::endl;
    }
    if(line.empty())
    {
        std::cout << "Error: there is no data" << std::endl;
        return ;
    }
}
float BitcoinExchange::getClosestRate(const std::string &date)
{
    std::map<std::string, float>::iterator it = exchangeRates.lower_bound(date); // thsis function return an iterator to the first element that is not less than the given key (date), if all elements are lisse than

    if (it != exchangeRates.end() && it->first == date)
        return it->second;
    if (it == exchangeRates.begin())
        return 0.0f;
    --it;
    return it->second;
}
void BitcoinExchange::set_date(std::string data)
{
    this->Date = data;
}
void BitcoinExchange::set_value(float val)
{
    this->value = val;
}
std::string BitcoinExchange::get_date() const
{
    return Date;
}
float BitcoinExchange::get_value() const
{
    return value;
}