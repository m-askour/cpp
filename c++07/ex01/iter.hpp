#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
template <typename T>
    void iter(T *a, T const lent, void (*function)(T &));
template <typename T>
     void print(T &x);
#endif