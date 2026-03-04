#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostram>
class Span
{
private:
    std::vector<int> number;
    unsigned int N;
public:
    Span(unsigned int N);
    ~Span();
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
};





#endif