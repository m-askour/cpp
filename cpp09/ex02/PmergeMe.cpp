#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
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

static std::vector<int> jacobsthal_order(size_t n)
{
    std::vector<int> order;
    if (n == 0)
        return order;
    order.reserve(n);
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    if (n == 1)
    {
        order.push_back(0);
        return order;
    }
    jacobsthal.push_back(1);
    while (jacobsthal[jacobsthal.size() - 1] < n - 1)
        jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);

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
            for (size_t idx = cur;; idx--)
            {
                if (!used[idx])
                {
                    order.push_back(static_cast<int>(idx));
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
        if (!used[idx])
            order.push_back(static_cast<int>(idx));
    return order;
}



std::vector<int> PmergeMe::handle_major(std::vector<int> pair)
{
    std::vector<int> major;
    for (size_t i = 0; i < pair.size(); i += 2)
    {
        major.push_back(pair[i + 1]);
    }
    return major;
}
std::vector<int> PmergeMe::handle_minor(std::vector<int> pair)
{
    std::vector<int> minor;
    for (size_t i = 0; i < pair.size(); i += 2)
    {
        minor.push_back(pair[i]);
    }
    return minor;
}

static void insert_min_in_maj(std::vector<int> &major, std::vector<int> minor)
{
    std::vector<int> order = jacobsthal_order(minor.size());
    for (size_t i = 0; i < order.size(); i++)
    {
        int value = minor[order[i]];
        major.insert(std::upper_bound(major.begin(), major.end(), value), value);
    }
}
std::vector<int> PmergeMe::split_pair(const std::deque<int> &sort, bool &hasStray, int &strayValue)
{
    std::vector<int> sorting_pair;
    for (size_t i = 0; i < sort.size(); i += 2)
    {
        if (i + 1 < sort.size())
        {
            if (sort[i] > sort[i + 1])
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
std::vector<int> PmergeMe::Ford_Johnson_sortingI(const std::deque<int> &sort)
{

    if (sort.size() <= 1)
        return std::vector<int>(sort.begin(), sort.end());
    bool hasStray = false;
    int strayValue = 0;
    std::vector<int> pair;
    pair = split_pair(sort, hasStray, strayValue);
    std::vector<int> sorting_pair = split_pair(pair, hasStray, strayValue);
    std::vector<int> majour_num = handle_major(pair);
    std::vector<int> minor_num = handle_minor(pair);
    std::vector<int> sorting = Ford_Johnson_sortingI(std::deque<int>(majour_num.begin(), majour_num.end()));
    insert_min_in_maj(sorting, minor_num);
    if (hasStray)
        sorting.insert(std::upper_bound(sorting.begin(), sorting.end(), strayValue), strayValue);
    return sorting;
}
std::vector<int> PmergeMe::split_pair(const std::vector<int> &sort, bool &hasStray, int &strayValue)
{
    std::vector<int> sorting_pair;
    for (size_t i = 0; i < sort.size(); i += 2)
    {
        if (i + 1 < sort.size())
        {
            if (sort[i] > sort[i + 1])
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
std::vector<int> PmergeMe::Ford_Johnson_sortingII(const std::vector<int> &sort)
{

    if (sort.size() <= 1)
    {
        return sort;
    }
    bool hasStray = false;
    int strayValue = 0;
    std::vector<int> pair;
    pair = split_pair(sort, hasStray, strayValue);
    std::vector<int> majour_num = handle_major(pair);

    std::vector<int> minor_num = handle_minor(pair);
    std::vector<int> sorting = Ford_Johnson_sortingII(majour_num);

    insert_min_in_maj(sorting, minor_num);

    if (hasStray)
        sorting.insert(std::upper_bound(sorting.begin(), sorting.end(), strayValue), strayValue);
    return sorting;
}
static int check_value(std::string input)
{
    if (input.empty())
    {
        std::cout << "Error: it's empty." << std::endl;
        return 1;
    }
    for (size_t i = 0; i < input.size(); i++)
    {
        if (!std::isdigit(input[i]))
        {
            std::cout << "Error : this is not digit." << std::endl;
            return 1;
        }
    }
    return 0;
}
int PmergeMe::processInput(const std::string &input)
{

    if (check_value(input))
        return 1;
    unsigned int num = static_cast<unsigned int>(std::atoi(input.c_str()));
    stor.push_back(num);
    storVec.push_back(num);
    return 0;
}
void PmergeMe::run(int number)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < stor.size(); i++)
    {
        std::cout << stor[i] << " ";
    }
    std::cout << std::endl;

    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    std::vector<int> result_deque = Ford_Johnson_sortingI(stor);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;
    clock_gettime(CLOCK_MONOTONIC, &start);
    std::vector<int> result_vector = Ford_Johnson_sortingII(storVec);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_nsec - start.tv_nsec) / 1000.0;

    std::cout << "After: ";
    for (size_t i = 0; i < result_deque.size(); i++)
    {
        std::cout << result_deque[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << number << "elements with std::deque : "<<timeDeq << " us" << std::endl;
    std::cout << "Time to process a range of " << number << "elements with std::vector : "<<timeVec << " us" << std::endl;
}
