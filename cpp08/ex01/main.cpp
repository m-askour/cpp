#include "Span.hpp"
#include <climits>

int main()
{
    try
    {
        Span sp = Span(INT_MAX);
        sp.addNumber(INT_MIN);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}