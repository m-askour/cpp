#include "Span.hpp"
#include <algorithm>
Span::Span(unsigned int N)
{
}

Span::~Span()
{
}    
void Span::addNumber(int num)
{
    if (number.size() >= N)
        throw std::runtime_error("the size is the maxe of what we prifire");
    number.push_back(num);
}
int Span::shortestSpan()
{
      if(number.size() <= 1)
        throw std::runtime_error("there is just one value no spam");
}
int Span::longestSpan()
{ 
    if(number.size() <= 1)
        throw std::runtime_error("there is just one value no spam");
    return n
}