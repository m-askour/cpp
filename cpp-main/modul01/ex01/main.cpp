#include "Zombie.hpp"

int main()
{
    Zombie *new_zombie;
    new_zombie = zombieHorde(10, "new_zombie");
    int i = 0;
    while (i < 10)
    {
        new_zombie->announce();
    }
    delete[]new_zombie;    
    return (0);
}