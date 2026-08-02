#include "RPN.hpp"
#include <climits>
#include <cctype>

RPN::RPN() : stack()
{
}

RPN::RPN(const RPN &other)
{
    stack = other.stack;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        stack = other.stack;
    return *this;
}

RPN::~RPN()
{
}

static int pars_input(const std::string &expression)
{
    for (std::string::size_type i = 0; i < expression.length(); i++)
    {
        if (!std::isdigit(expression[i]) &&
            expression[i] != ' ' &&
            expression[i] != '+' &&
            expression[i] != '-' &&
            expression[i] != '*' &&
            expression[i] != '/')
            return 1;
    }
    return 0;
}

int RPN::evaluate(const std::string &expression)
{
    while (!stack.empty())
        stack.pop();

    if (pars_input(expression))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::string::size_type i = 0;

    while (i < expression.length())
    {
        if (expression[i] == ' ')
        {
            i++;
        }
        else if (std::isdigit(expression[i]))
        {
            // Reject numbers larger than one digit
            if (i + 1 < expression.length() &&
                std::isdigit(expression[i + 1]))
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }

            stack.push(expression[i] - '0');
            i++;
        }
        else
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }

            long num2 = stack.top();
            stack.pop();

            long num1 = stack.top();
            stack.pop();

            long result = 0;

            switch (expression[i])
            {
                case '+':
                    result = num1 + num2;
                    break;

                case '-':
                    result = num1 - num2;
                    break;

                case '*':
                    result = num1 * num2;
                    break;

                case '/':
                    if (num2 == 0)
                    {
                        std::cerr << "Error can't dive by 0" << std::endl;
                        return 1;
                    }
                    result = num1 / num2;
                    break;

                default:
                    std::cerr << "Error " << std::endl;
                    return 1;
            }

            if (result > INT_MAX || result < INT_MIN)
            {
                std::cerr << "Error" << std::endl;
                return 1;
            }

            stack.push(static_cast<int>(result));
            i++;
        }
    }

    if (stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << stack.top() << std::endl;
    return 0;
}