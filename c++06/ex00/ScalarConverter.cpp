#include "ScalarConverter.hpp"
#include <limits>
ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter()
{
}
void convert_char(std::string literal, char c, int i, float f, double d)
{
    if (literal.length() == 1)
        c = literal[0];
    else
        throw std::invalid_argument("not char");
    if (static_cast<unsigned char>(c) > 127)
        throw std::invalid_argument("out of range");
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);
    if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << "" << std::endl;
}
void convert_int(std::string literal, int i, float f, double d)
{
    long l = std::atol(literal.c_str());

    bool overflow = (l > 2147483647 || l < -2147483648);

    i = static_cast<int>(l);
    f = static_cast<float>(l);
    d = static_cast<double>(l);

    if (l < 0 || l > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

    if (overflow)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
void convert_float(std::string literal, int i, float f, double d)
{
    // explicit cast to the other types
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
    if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << "" << std::endl;
}
void convert_double(std::string literal, int i, float f, double d)
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

    // FIX: Check for NaN/Inf BEFORE checking f == static_cast<int>(f)
    if (std::isnan(f) || std::isinf(f))
        std::cout << "float: " << f << "f" << std::endl;
    else if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    // FIX: Check for NaN/Inf BEFORE checking d == static_cast<int>(d)
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
    int count_f = 0;

    if (literal.empty())
        return 0;
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return 2;
    if (literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "-inf" ||
        literal == "+inff" || literal == "-inff")
        return 1;
    for (int i = 0; i < (int)literal.size(); i++)
    {
        if (literal[i] == '.')
            count_point++;
        else if (literal[i] == 'f')
        {
            count_f++;
            if (i != (int)(literal.length() - 1))
                return 0;
        }
        else if (!std::isdigit(literal[i]) &&
                 !(i == 0 && (literal[i] == '+' || literal[i] == '-')))
            return 0;
    }
    if (count_point > 1 || count_f > 1)
        return 0;
    if (count_f == 1)
        return 3;
    if (count_point == 1)
        return 4;
    return 5;
}
void ScalarConverter::convert(std::string &str)
{
    char c = '\0';
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    int type = check_liter(str);

    if (type == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    else if (type == 1)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (str == "+inff" || str == "-inff" || str == "nanf")
        {
            std::cout << "float: " << str << std::endl;
            std::cout << "double: "
                      << str.substr(0, str.length() - 1)
                      << std::endl;
        }
        else if (str == "+inf" || str == "-inf" || str == "nan")
        {
            std::cout << "float: " << str << "f" << std::endl;
            std::cout << "double: " << str << std::endl;
        }
        return;
    }
    else if (type == 2)
    {
        try
        {
            convert_char(str, c, i, f, d);
        }
        catch (const std::exception &e)
        {
            std::cout << "char: impossible" << std::endl;
        }
    }
    else if (type == 3)
    {
        try
        {
            convert_float(str, i, f, d);
        }
        catch (const std::exception &e)
        {
            std::cout << "float: impossible" << std::endl;
        }
    }
    else if (type == 4)
    {
        try
        {
            convert_double(str, i, f, d);
        }

        catch (const std::exception &e)
        {
            std::cout << "double: impossible" << std::endl;
        }
    }
    else if (type == 5) // int
    {
        try
        {
            convert_int(str, i, f, d);
            /* code */
        }
        catch (const std::exception &e)
        {
            std::cout << "int: impossible" << std::endl;
        }
    }
}
