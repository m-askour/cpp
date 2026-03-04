#include "MutantStack.hpp"
template <typename T>
MutantStack<T>::MutantStack(): size(0)
{
}
template <typename T>
MutantStack<T>::~MutantStack()
{
}
template <typename T>

int MutantStack<T>::top()
{

}
template <typename T>

int MutantStack<T>::size()
{
    return Stack.size();
}
template <typename T>

int MutantStack<T>::begin()
{
    std::vector<int>::iterator it = Stack.begin;
    return *it;
}
template <typename T>

int MutantStack<T>::end()
{
    std::vector<int>::iterator it = Stack.begin;
    while(it < Stack.size() - 1)
        it++;
    return *it;
}
template<typename T>
void MutantStack<T>::push(int i)
{
    Stack.push_back(i);
}