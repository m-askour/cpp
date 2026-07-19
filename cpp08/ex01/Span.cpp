#include"Span.hpp"

Span::Span(unsigned int N):N(N)
{}
Span::Span(const Span&other):N(other.N), vec(other.vec)
{}
Span& Span::operator=(const Span& other)
{
    if(this != &other)
    {
        N = other.N;
        vec = other.vec;
    }
    return *this;
}
Span::~Span()
{
}
void Span::addNumber(int number)
{
    if(vec.size() >= N)
    {
        throw std::runtime_error("the size is not inaph");
    }
    vec.push_back(number);
}
void Span::addnumbers(int first, int last)
{
    if(vec.size() + std::distance(first, last) > N)
        throw std::runtime_error("the size is not inaph");
    vec.insert(vec.end(),forst,last);
}
long long  Span::shortestSpan()
{
    if(vec.size() < 2)
        throw std::runtime_error("Not enough numbers");
    sort(vec.begin(),vec.end()); 
    long long min_span =static_cast<long long >(vec[1])- vec[0];

    for(unsigned int i=1; i<vec.size()-1;i++)
    {
        if(static_cast<long long >(vec[i+1]) - vec[i] < min_span)
            min_span = static_cast<long long >(vec[i+1]) - vec[i];
    }
    return min_span;
}
long long Span::longestSpan()
{
    if(vec.size() < 2)
        throw std::runtime_error("there is not numbers"); 
    long long max_elemnt = *std::max_element(vec.begin(),vec.end());
    long long min_element  = *std::min_element(vec.begin(),vec.end());
    return max_elemnt - min_element;
}
