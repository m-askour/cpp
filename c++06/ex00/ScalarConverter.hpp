#ifndef SCALAR_CONVERTER1_HPP
#define SCALAR_CONVERTER1_HPP
#include <iostream>
#include <string>
class ScalarConverter1
{
private:
    ScalarConverter1(/* args */);
    ScalarConverter1(const ScalarConverter1 &other);
    ScalarConverter1 &operator=(const ScalarConverter1 &other);
    ~ScalarConverter1();
public:
    static void convert(const std::string &literal);
};
#endif