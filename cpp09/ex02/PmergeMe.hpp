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
        std::deque<int> stor;
    public:
        PmergeMe(/* args */);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        int processInput(const std::string &input);
};


