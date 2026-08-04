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
        if(pmerge.processInput(av[i]))
            return 1;
    }
    pmerge.run();
    return 0;
}