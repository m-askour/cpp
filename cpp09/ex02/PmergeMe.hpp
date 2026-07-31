#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
class PmergeMe
{
    private:
        std::stack<int> stack;
    public:
        PmergeMe(/* args */);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        void processInput(const std::string &input);
};


