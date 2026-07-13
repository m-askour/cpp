#pragma once
#include<exception>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
class Span
{
private:
    /* data */
    std::vector<int> vec;
    unsigned int N;//this is the N we can stor 
public:
    Span(/* args */);
    Span(unsigned int N);
    Span(const Span&other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);//this shuld throw an exception if there is this number
    long long  shortestSpan();//if there are no number or just 1 number >>>throw exception
    long long longestSpan();//if there are no number or just 1 number >>>throw exception
};


