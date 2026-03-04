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
public:
    MutantStack();
    ~MutantStack();

    void push(const T& i);//stack.push_back
    T & top();// return stack.back
    int size();//return stack.size()
    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();
    void pop();//stack.pop_back

};

#endif