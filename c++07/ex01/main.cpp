#include "iter.hpp"
template<typename T>
void iter(T *a, T const lent, void (*function)(T &)) 
{
    for (int i = 0; i < lent ; i++)
        function(a[i])
}

template<typename T>
void print (T &x)
{
    std::cout << x<< std::endl;
}
int main( void ) {

    int arr[] = {1, 2, 3};
    iter(arr, 3, print);

    std::string str[] = {"hello", "world"};
    iter(arr, 2, print);
}