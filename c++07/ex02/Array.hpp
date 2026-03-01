#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "Array.tpp"
#include <iostream>
#include <string>
template <typename T>
class Array
{
private:
    T arr;
    int size;
public:
    Array();//this to creat a empty array
    Array(unsigned int n);//this to creat an array with n element
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();
    T& operator[](int index);

    int size() const;


};
#endif