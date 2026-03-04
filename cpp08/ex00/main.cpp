#include "easyfind.hpp"

int main ()
{
    try
    {
        std::vector<int>v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        std::vector<int>::iterator it = easyfind(v , 20);
        std::cout << *it << std::endl;
        easyfind(v, 100);//this to throw the exeption

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}