#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <ctime>
class PmergeMe
{
private:
    std::vector<int> digits;
    std::deque<int> stor;     // this to store the numbers in deque to use it in the first sorting method
    std::vector<int> storVec; // this to store the numbers in vector to use it in the second sorting method
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();
    // deque version of the Ford Johnson sorting algorithm
    std::vector<int> Ford_Johnson_sortingI(const std::deque<int> &sort);
    std::vector<int> handle_major(std::vector<int> pair);
    std::vector<int> handle_minor(std::vector<int> pair);
    std::vector<int> split_pair(const std::deque<int> &sort, bool &hasStray, int &strayValue);
    // vector version of the Ford Johnson sorting algorithm
    std::vector<int> Ford_Johnson_sortingII(const std::vector<int> &sort);
    std::vector<int> split_pair(const std::vector<int> &sort, bool &hasStray, int &strayValue);

    int processInput(const std::string &input);
    void run(int number);
};
