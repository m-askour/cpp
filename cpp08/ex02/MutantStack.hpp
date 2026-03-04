#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iterator>
#include <iostream>
#include <vector>
template<typename T>
class MutantStack : public std::stack<T>
{
private:
    std::vector<int> Stack;
public:
    MutantStack();
    ~MutantStack();

    void push(const T& i);//stack.push_back
    T & top();// return stack.back
    int size();//return stack.size()
    typedef typename std::vector<T>::iterator iterator;
    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();
    void pop();//stack.pop_back
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

#endif