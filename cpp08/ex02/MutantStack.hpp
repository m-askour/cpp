#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iterator>
#include <iostream>
#include <vector>
template<typename T>
class MutantStack
{
private:
    std::vector<int> Stack;
    unsigned int size;
public:
    MutantStack();
    ~MutantStack();

    void push(int i);
    int top();
    int size();
    int begin();
    int end();

};

#endif