#include "Span.hpp"
#include <algorithm>
//what's the span 

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
    // std::vector<int>::iterator it = number.begin();
    std::sort(number.begin(),number.end());
    //
    int minspan = number[1] - number[0];
    for(int i = 1; i < number.size() - 1; i++)
    {
        int curentspan = number[i + 1] - number[i];
        if(curentspan < minspan)
            minspan = curentspan; 
    }
    return minspan;


}
int Span::longestSpan()
{ 
    if(number.size() <= 1)
        throw std::runtime_error("there is just one value no spam");
    std::vector<int>::iterator maxit = std::max_element(number.begin(), number.end());
    std::vector<int>::iterator minit = std::min_element(number.begin(), number.end());
    return (*maxit - *minit);
}