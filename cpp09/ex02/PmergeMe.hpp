#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include<vector>
#include<deque>
#include <string>
class PmergeMe
{
    private:
        std::vector<int> digits;
        std::vector<int> minor_num;
        std::vector<int> majour_num;
        std::deque<int> stor;
    public:
        PmergeMe(/* args */);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        
        std::vector<int> Ford_Johnson_sortingI(const std::deque<int>& sort);
        int processInput(const std::string &input);
};


