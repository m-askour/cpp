#include "Zombie.hpp"

int main()
{
    Zombie *new_zombie;
    new_zombie = zombieHorde(10, "new_zombie");
    
    for  (int i = 0;i < 10;i++)
        new_zombie[i].announce();
    delete[] new_zombie;
    return (0);
}