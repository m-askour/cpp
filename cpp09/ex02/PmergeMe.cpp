#include "PmergeMe.hpp"

PmergeMe::PmergeMe():stor(0),digits(0),storVec(0),minor_num(0),majour_num(0)
{
}
PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->stor = other.stor;
    this->digits = other.digits;
    this->storVec = other.storVec;
    this->minor_num = other.minor_num;
    this->majour_num = other.majour_num;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->stor = other.stor;
        this->digits = other.digits;
        this->storVec = other.storVec;
        this->minor_num = other.minor_num;
        this->majour_num = other.majour_num;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}
//i need the jucobsthal sequence to know the order of the insertion of the minor numbers in the major numbers


static std::vector<int> jacobsthal_order(int n)
{
    std::vector<int> order;
    if(n <= 0)
        return order;
    order.reserve(n);
    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    if (n == 1)
        return jacobsthal;
    jacobsthal.push_back(1);
    while (jacobsthal[jacobsthal.size() - 1] < n -1)
    {
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
    std::vector<bool> used(n, false);
    order.push_back(0);
    used[0] = true;
 
    size_t prev = 1;
    for (size_t i = 2; i < jacobsthal.size(); i++)
    {
        size_t cur = jacobsthal[i];
        if (cur > n - 1)
            cur = n - 1;
        if (cur >= prev)
        {
            for (size_t idx = cur; ; idx--)
            {
                if (!used[idx])
                {
                    order.push_back(idx);
                    used[idx] = true;
                }
                if (idx == prev)
                    break;
            }
        }
        if (cur == n - 1)
            break;
        prev = cur + 1;
    }
    for (size_t idx = 1; idx < n; idx++)
    {
        if (!used[idx])
            order.push_back(idx);
    }
    return order;
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

std::vector<int> PmergeMe::handle_major(std::vector<int> pair)
{
    std::vector<int> major;
    for(size_t i = 0; i < pair.size();i += 2)
    {
        major.push_back(pair[i + 1]);
    }
    return major;
}
std::vector<int> PmergeMe::handle_minor(std::vector<int> pair)
{
    std::vector<int> minor;
    for(size_t i = 0; i < pair.size();i += 2)
    {
        minor.push_back(pair[i]);
    }
    return minor;
}

static void insert_min_in_maj(std::vector<int> &major,std::vector<int> minor)
{
    std::vector<int> order = jacobsthal_order(minor.size());
    for(size_t i = 0; i < order.size();i++)
    {
        int value = minor[order[i]];
        major.insert(std::upper_bound(major.begin(),major.end(),value),value);
    }
}
std::vector<int> split_pair(const std::deque<int>& sort,bool &hasStray, int &strayValue)
{
    std::vector<int> sorting_pair;
    for(size_t i = 0; i < sort.size();i += 2)
    {
        if(i + 1 < sort.size())
        {
            if(sort[i] > sort[i + 1])
            {
                sorting_pair.push_back(sort[i + 1]);
                sorting_pair.push_back(sort[i]);
            }
            else
            {
                sorting_pair.push_back(sort[i]);
                sorting_pair.push_back(sort[i + 1]);
            }
        }
        else
        {
            hasStray = true;
            strayValue = sort[i];
        }
    }
    return sorting_pair;
}
std::vector<int> PmergeMe::Ford_Johnson_sortingI(const std::deque<int>& sort)
{
    
    if(sort.size() <= 1)
    return std::vector<int>(sort.begin(), sort.end());
    bool hasStray = false;
    int strayValue = 0;
    //1-premier step split the numbers to pair
    std::vector<int> pair;
    pair = split_pair(sort, hasStray, strayValue);
    //2-sort the pairs the big in right the smal in the left
    std::vector<int> sorting_pair = split_pair(pair, hasStray, strayValue);
    //3- takce the all the right number from the pirse and pic it in the magor number then sort it 
    majour_num = handle_major(pair);
    //std::vector<int> sorting  = sort_major(majour_num);
    //4- tack the left numbers and put it in the minor number
    minor_num = handle_minor(pair);

    //recursive call to sort the major numbers
    std::vector<int> sorting = Ford_Johnson_sortingI(std::deque<int>(majour_num.begin(), majour_num.end()));
    //5-insert the small numbers one by one
    insert_min_in_maj(sorting,minor_num);
    /*FordJohnson(sequence):
    if size <= 1: return sequence
    pair up elements (a0,b0), (a1,b1), ... where ai < bi  (larger goes into "b" chain)
    if odd element left over, set it aside
    mainChain = FordJohnson(all b_i)        // <-- recursive call, not std::sort
    mainChain = [a0] + mainChain            // a0 (paired with the smallest b) seeds the chain
    for i in jacobsthal-order over remaining a_i (and finally the leftover odd element):
    binary-insert a_i into mainChain, searching only up to the position
    of its known-larger pair partner (not the whole chain)
    return mainChain*/
    if(hasStray)
    sorting.insert(std::upper_bound(sorting.begin(), sorting.end(), strayValue), strayValue);
    return sorting;
}
//vector version of the Ford Johnson sorting algorithm
std::vector<int> PmergeMe::split_pair(const std::vector<int>& sort,bool &hasStray, int &strayValue)
{
    std::vector<int> sorting_pair;
    for(size_t i = 0; i < sort.size();i += 2)
    {
        if(i + 1 < sort.size())
        {
            if(sort[i] > sort[i + 1])
            {
                sorting_pair.push_back(sort[i + 1]);
                sorting_pair.push_back(sort[i]);
            }
            else
            {
                sorting_pair.push_back(sort[i]);
                sorting_pair.push_back(sort[i + 1]);
            }
        }
        else
        {
            hasStray = true;
            strayValue = sort[i];
        }
    }
    return sorting_pair;
}
std::vector<int> PmergeMe::Ford_Johnson_sortingII(const std::vector<int>& sort)
{
    /*FordJohnson(sequence):
    if size <= 1: return sequence
    pair up elements (a0,b0), (a1,b1), ... where ai < bi  (larger goes into "b" chain)
    if odd element left over, set it aside
    mainChain = FordJohnson(all b_i)        // <-- recursive call, not std::sort
    mainChain = [a0] + mainChain            // a0 (paired with the smallest b) seeds the chain
    for i in jacobsthal-order over remaining a_i (and finally the leftover odd element):
        binary-insert a_i into mainChain, searching only up to the position
        of its known-larger pair partner (not the whole chain)
    return mainChain*/
    if (sort.size() <= 1)
    {
        return sort;
    }
    bool hasStray = false;
    int strayValue = 0;
    //1-premier step split the numbers to pair
    std::vector<int> pair;
    pair = split_pair(sort, hasStray, strayValue);
    //3- takce the all the right number from the pirse and pic it in the magor number then sort it 
    majour_num = handle_major(pair);
    //std::vector<int> sorting  = sort_major(majour_num);
    //4- tack the left numbers and put it in the minor number
    minor_num = handle_minor(pair);
    //recursive call to sort the major numbers
    std::vector<int> sorting = Ford_Johnson_sortingII(majour_num);
    
    //5-insert the small numbers one by one
    insert_min_in_maj(sorting,minor_num);

    //check if hasStray is true, if yes insert the strayValue in the sorting vector
    if (hasStray)
        sorting.insert(std::upper_bound(sorting.begin(), sorting.end(), strayValue), strayValue);
    return sorting;
}
int PmergeMe::processInput(const std::string &input)
{
    //this for check if the input is a number or not and stor the value in the deque and vector
        //checl the input is it valid
        if(check_value(input))
            return 1;
        //convert the input to int
        unsigned int num = static_cast<unsigned int>(std::atoi(input.c_str()));
        //add the number in deque
        stor.push_back(num);
        storVec.push_back(num);
        return 0;
}
void PmergeMe::run()
{
    // Implementation for run function
    //the input 
    std::cout << "Before: ";
    for(size_t i = 0; i < stor.size();i++)
    {
        std::cout << stor[i] << " ";
    }
    std::cout << std::endl;

    struct timeval start, end;
    //gettimeofday(&start, NULL);
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    //the sorting with the deque and the time of each one
    std::vector<int> result_deque = Ford_Johnson_sortingI(stor);
    clock_gettime(CLOCK_MONOTONIC, &end);
    //double time_taken_deque = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e3; // in microseconds
    double timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0+ (end.tv_nsec - start.tv_nsec) / 1000.0;
    //the sorting with the vector and the time of each one
    clock_gettime(CLOCK_MONOTONIC, &start);
    std::vector<int> result_vector = Ford_Johnson_sortingII(storVec);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;

    
    //print the result
    std::cout << "After: ";
    for(size_t i = 0; i < result_deque.size();i++)
    {
        std::cout << result_deque[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time taken by deque: " << timeDeq << " microseconds" << std::endl;
    std::cout << "Time taken by vector: " << timeVec << " microseconds" << std::endl;
}
