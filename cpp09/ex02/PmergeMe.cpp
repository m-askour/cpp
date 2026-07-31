#include "PmergeMe.hpp"
PmergeMe::PmergeMe(/* args */)
{
}
PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->stack = other.stack;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->stack = other.stack;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::processInput(const std::string &input)
{
}