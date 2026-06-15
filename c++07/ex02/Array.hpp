#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Array
{
private:
    T* arr;
    unsigned int _size;
public:
    Array(); // create an empty array
    Array(unsigned int n); // create an array with n elements
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();
    T& operator[](int index);

    int size() const;
};

#include "Array.tpp"

#endif