#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
class RPN
{
private:
    std::stack<int> stack;
    /* data */
public:
    RPN(/* args */);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();
    void evaluate(const std::string &expression);
};


