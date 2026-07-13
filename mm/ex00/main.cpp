#include"easyfind.hpp"

int main()
{
try
{   std::vector<int> str;
    str.push_back(1);
    str.push_back(3);
    str.push_back(6);
    str.push_back(100);
    str.push_back(30);
    std::vector<int>::iterator it;
    it = easyfind(str,300);
    std::cout<<*it<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}