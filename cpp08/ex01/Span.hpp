#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>
class Span
{
private:
    std::vector<int> number;
    unsigned int N;

public:
    Span(unsigned int N);
    ~Span();
    void addNumber(int num);
    void Span::addNumbers(Iterator first, Iterator last);
    int shortestSpan();
    int longestSpan();
};
#endif
