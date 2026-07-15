#pragma once
#include<algorithm>
#include<iostream>
#include<string>
#include<exception>
#include<vector>
#include<iterator>
template<typename T>
typename T::iterator easyfind(T &continer, int integer)
{
    typename T::iterator it;
    it = std::find(continer.begin(),continer.end(),integer);//find return the iterator 
    if(it == continer.end())
        throw std::runtime_error("value not found");
    return it;
}
