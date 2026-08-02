#include"PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac > 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }
    PmergeMe pmerge;
    for(int i = 0 ; i < ac; i++)
    {
    
        return(pmerge.processInput(av[i]));
    }
    return 0;
}