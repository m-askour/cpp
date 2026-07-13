#pragma once

#include <stack>
#include<iostream>
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>()
    {
    }

    MutantStack(const MutantStack& other)
        : std::stack<T>(other)
    {
    }

    MutantStack& operator=(const MutantStack& other)
    {
        if (this != &other)
            std::stack<T>::operator=(other);
        return *this;
    }

    ~MutantStack()
    {
    }
    //rename the iterator
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }
    typedef typename std::stack<T>::container_type::iterator constiterator;

    constiterator bigin() const
    {
        return this->c.begin();//c is the contener atribute it's in the stack class
    }
    constiterator end() const
    {
        return this->c.end();
    }
};