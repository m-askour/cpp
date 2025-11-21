#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *names;
    int i = 0;
    while (i < N)
    {
        names = new Zombie(name);
        i++;
    }
    return (names);
}