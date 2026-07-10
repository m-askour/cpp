#pragma once

#include <string>
#include <iostream>

template <typename T, typename T_function> void iter(T *arr,const size_t lent, T_function function)
{
    for(std::size_t  i = 0 ; i < lent; i++)
        function(arr[i]);
}