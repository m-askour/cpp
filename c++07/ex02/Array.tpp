#include "Array.hpp"

#include <iostream>
#include <string>
//this is where we declarate the member function that insinde of class
//default class
template<typename T>
Array<T>::Array() : arr(NULL), size(0)
{}

template<typename T>
Array<T>::Array(unsigned int n) : size(n)
{
    arr = new T[n]();//default inisialisation
    int * a = new int();
    std::cout << *a << std::endl;
}

template <typename T>
Array<T>::Array(const Array &other)
{
    *this = other;
}

template  <typename T>

Array<T>& Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] arr;

        size = other.size;

        if (size == 0)
            arr = NULL;
        else
        {
            arr = new T[size];
            for (unsigned int i = 0; i < size; i++)
            {
                arr[i] = other.arr[i];
            }
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{}

//trow the exeption 
template <typename T>
T& Array<T>::operator[](int index)
{
    if (index >= size || index < 0)
    {
        throw std::out_of_range("index out of the range");
    }
    return arr[index];
}


template <typename T>
int Array<T>::size() const
{
    return size;
}