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
std::vector<int> PmergeMe::Ford_Johnson_sortingI(const std::deque<int>& sort)
{
    //1-premier step split the numbers to pair
    std::vector<int> pair;
    pair split_pair(sort);
    //2-sort the pairs the big in right the smal in the left
    std::vector<int> sorting_pair = sort_pair(pair);
    //3- takce the all the right number from the pirse and pic it in the magor number then sort it 
    majour_num = handle_major(pair);
    std::vector<int> sorting  = sort_major(majour_num);
    //4- tack the left numbers and put it in the minor number
    minor_num = handle_minor(pair);
    //5-insert the small numbers one by one
    insert_min_in_maj(sorting,minor_num);
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
        std::vector<int> result;
        result = Ford_Johnson_sortingI(stor);
        return 0;
}