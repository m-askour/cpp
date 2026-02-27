#include "ScalarConverter.hpp"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <cctype>
#include <stdexcept>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; }
ScalarConverter::~ScalarConverter() {}

int check_int(const std::string &literal, double &d, float &f, int &i)
{
    i = std::atoi(literal.c_str());
    d = static_cast<double>(i);
    f = static_cast<float>(i);
    return 1;
}

int check_float(const std::string &literal, double &d, float &f, int &i)
{
    f = std::atof(literal.c_str());
    d = static_cast<double>(f);
    i = static_cast<int>(f);
    return 1;
}

int check_double(const std::string &literal, double &d, float &f, int &i)
{
    d = std::atof(literal.c_str());
    f = static_cast<float>(d);
    i = static_cast<int>(d);
    return 1;
}

int check_literal(std::string literal)
{
    int count_dot = 0;
    int count_f = 0;

    if (literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "-inf" ||
        literal == "+inff" || literal == "-inff")
        return 2; // special literal

    if (literal.empty())
        return 0;

    for (size_t i = 0; i < literal.length(); i++)
    {
        if (literal[i] == '.')
            count_dot++;
        else if (literal[i] == 'f')
        {
            count_f++;
            if (i != literal.length() - 1) // 'f' must be last
                return 0;
        }
        else if (!std::isdigit(literal[i]) &&
                 !(i == 0 && (literal[i] == '+' || literal[i] == '-')))
            return 0;
    }

    if (count_dot > 1 || count_f > 1)
        return 0;

    return 1;
}

void ScalarConverter::convert(const std::string &literal)
{
    double d = 0.0;
    char c;
    int i = 0;
    float f = 0.0f;

    if (!literal.empty() && literal.length() == 1 && !std::isdigit(literal[0]))
    {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);

        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    try
    {
        int type = check_literal(literal);

        if (type == 0)
            throw std::invalid_argument("Invalid literal");

        if (type == 2)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;

            if (literal.find('f') != std::string::npos)
            {
                std::cout << "float: " << literal << std::endl;
                std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
            }
            else
            {
                std::cout << "float: " << literal << "f" << std::endl;
                std::cout << "double: " << literal << std::endl;
            }
            return;
        }

        if (!literal.empty() &&
            literal[literal.length() - 1] == 'f' &&
            literal.find('.') != std::string::npos)
        {
            check_float(literal, d, f, i);
        }
        else if (literal.find('.') != std::string::npos)
        {
            check_double(literal, d, f, i);
        }
        else
        {
            check_int(literal, d, f, i);
        }

        if (i < 0 || i > 127)
            std::cout << "char: impossible" << std::endl;
        else if (std::isprint(i))
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << i << std::endl;

        if (f == static_cast<int>(f))
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;

        if (d == static_cast<int>(d))
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}