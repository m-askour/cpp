#include"PmergeMe.hpp"
int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }
    PmergeMe pmerge;
    pmerge.processInput(av[1]);
    return 0;
}