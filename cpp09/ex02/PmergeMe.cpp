#include "PmergeMe.hpp"
PmergeMe::PmergeMe(/* args */):stor(0),digits(0)
{
}
PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->stor = other.stor;
    this->digits = other.digits;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->stor = other.stor;
        this->digits = other.digits;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}
static int check_value(std::string input)
{
    if(input.empty())
    {
        std::cout << "Error: it's empty." << std::endl;
        return 1;
    }
    for(size_t i = 0; i < input.size();i++)
    {
        if(!std::isdigit(static_cast<unsigned int > (input[i])))
        {
            std::cout << "Error : this is not digit." << std::endl;
            return 1;
        }
    }
    return 0;    
}
int PmergeMe::processInput(const std::string &input)
{
        //checl the input is it valid
        if(check_value(input))
            return 1;
        //convert the input to int
        unsigned int num = static_cast<unsigned int>(std::atoi(input.c_str()));
        //add the number in deque
        stor.push_back(num);
}