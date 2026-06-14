#include "ScalarConverter1.hpp"
#include <limits>

// FIX 1: pass by reference so changes are visible to the caller
void convert_char(std::string literal, char &c, int &i, float &f, double &d)
{
    // a char literal looks like 'x'
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        c = literal[1];
    }
    else
    {
        // single printable non-digit char without quotes (subject edge case)
        if (literal.length() != 1 || std::isdigit(literal[0]))
            throw std::invalid_argument("not a char");
        c = literal[0];
    }
    if (static_cast<unsigned char>(c) > 127)
        throw std::out_of_range("out of range");
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);

    if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: "    << i << std::endl;
    std::cout << "float: "  << f << (f == static_cast<int>(f) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << d << (d == static_cast<int>(d) ? ".0"  : "")  << std::endl;
}

// FIX 1 + FIX 5: pass by reference, and actually print the results
void convert_int(std::string literal, int &i, float &f, double &d)
{
    long l = std::atol(literal.c_str());
    if (l > INT_MAX || l < INT_MIN)
        throw std::out_of_range("out of range");
    i = static_cast<int>(l);
    f = static_cast<float>(i);
    d = static_cast<double>(i);

    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: "    << i << std::endl;
    std::cout << "float: "  << f << (f == static_cast<int>(f) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << d << (d == static_cast<int>(d) ? ".0"  : "")  << std::endl;
}

// FIX 3 + FIX 6: don't throw on valid values — print them; handle all cases
void convert_float(std::string literal, int &i, float &f, double &d)
{
    f = std::atof(literal.c_str());
    d = static_cast<double>(f);
    i = static_cast<int>(f);

    if (f < 0 || f > 127)
        std::cout << "char: impossible" << std::endl;
    else if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

    if (std::isnan(f) || std::isinf(f))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (std::isnan(f) || std::isinf(f))
        std::cout << "float: " << f << "f" << std::endl;
    else if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    std::cout << "double: " << d << (d == static_cast<int>(d) ? ".0" : "") << std::endl;
}

// FIX 3 + FIX 6: same fix as convert_float
void convert_double(std::string literal, int &i, float &f, double &d)
{
    d = std::atof(literal.c_str());
    f = static_cast<float>(d);
    i = static_cast<int>(d);

    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

    if (std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (std::isnan(f) || std::isinf(f))
        std::cout << "float: " << f << "f" << std::endl;
    else if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    if (std::isnan(d) || std::isinf(d))
        std::cout << "double: " << d << std::endl;
    else if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

int check_liter(std::string literal)
{
    int count_point = 0;
    int count_f = 0; // FIX 4: was uninitialized

    if (literal.empty())
        return 0;
    // char literal 'x'
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return 2; // new type code for char
    if (literal == "nan"  || literal == "nanf" ||
        literal == "+inf" || literal == "-inf" ||
        literal == "+inff"|| literal == "-inff")
        return 1;
    for (int i = 0; i < (int)literal.size(); i++)
    {
        if (literal[i] == '.')
            count_point++;
        else if (literal[i] == 'f')
        {
            count_f++;
            if (i != (int)literal.length() - 1)
                return 0;
        }
        else if (!std::isdigit(literal[i]) &&
                 !(i == 0 && (literal[i] == '+' || literal[i] == '-')))
            return 0;
    }
    if (count_point > 1 || count_f > 1)
        return 0;
    if (count_f == 1)   return 3; // float
    if (count_point == 1) return 4; // double
    return 5; // int
}

void ScalarConverter1::convert(std::string str)
{
    char   c = 0;
    int    i = 0;
    float  f = 0.0f;
    double d = 0.0;

    int type = check_liter(str);

    // FIX 2: handle each type separately instead of throwing after type==1
    if (type == 1) // pseudo-literals: nan, inf variants
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible"  << std::endl;
        if (str == "nanf" || str == "+inff" || str == "-inff")
        {
            std::cout << "float: "  << str << std::endl;
            std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
        }
        else
        {
            std::cout << "float: "  << str << "f" << std::endl;
            std::cout << "double: " << str << std::endl;
        }
        return;
    }

    if (type == 2) // char literal 'x'
    {
        try
        {
            convert_char(str, c, i, f, d);
        }
        catch (const std::exception &e)
        {
            std::cout << "char: impossible" << std::endl;
        }
        return;
    }

    if (type == 5) // int
    {
        try
        {
            convert_int(str, i, f, d);
        }
        catch (const std::out_of_range &)
        {
            // overflows int but still valid as float/double
            double dv = std::atof(str.c_str());
            float  fv = static_cast<float>(dv);
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible"  << std::endl;
            std::cout << "float: "  << fv << "f" << std::endl;
            std::cout << "double: " << dv << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "int: impossible" << std::endl;
        }
        return;
    }

    if (type == 3) // float
    {
        try
        {
            convert_float(str, i, f, d);
        }
        catch (const std::exception &e)
        {
            std::cout << "float: impossible" << std::endl;
        }
        return;
    }

    if (type == 4) // double
    {
        try
        {
            convert_double(str, i, f, d);
        }
        catch (const std::exception &e)
        {
            std::cout << "double: impossible" << std::endl;
        }
        return;
    }
    else// type == 0: nothing matched
        std::cout << "char: impossible"   << std::endl;
        std::cout << "int: impossible"    << std::endl;
        std::cout << "float: impossible"  << std::endl;
        std::cout << "double: impossible" << std::endl;
}