#include "RPN.hpp"
RPN::RPN(/* args */)
{
}
RPN::RPN(const RPN &other)
{
    this->stack = other.stack;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->stack = other.stack;
    }
    return *this;
}

RPN::~RPN()
{
}

void RPN::evaluate(const std::string &expression)
{
}