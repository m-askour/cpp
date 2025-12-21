#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *names;
    if (N <= 0)
        return NULL;    
    names = new Zombie[N];
    int i = 0;
    while (i < N)
    {
        names[i] = Zombie(name);
        i++;
    }
    return (names);
}