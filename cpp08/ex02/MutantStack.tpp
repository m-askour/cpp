#include "MutantStack.hpp"
template <typename T>
MutantStack<T>::MutantStack()
{
}
template <typename T>
MutantStack<T>::~MutantStack()
{
}
template <typename T>

T & MutantStack<T>::top()
{
    return Stack.back();
}
template <typename T>

int MutantStack<T>::size()
{
    return Stack.size();
}
template <typename T>

typename std::vector<T>::iterator MutantStack<T>::begin()
{
    return Stack.begin();
}
template <typename T>

typename std::vector<T>::iterator MutantStack<T>::end()
{
    return Stack.end();
}
template <typename T>
void MutantStack<T>::push(const T& i)
{
    Stack.push_back(i);
}
template <typename T>
void MutantStack<T>::pop()
{
    Stack.pop_back();
}
