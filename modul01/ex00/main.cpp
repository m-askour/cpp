#include "Zombie.hpp"

int main ()
{
    Zombie *newZombie1;
    newZombie1 = newZombie("new zombie");
    newZombie1->announce();
    randomChump("rand zombie");
    delete newZombie1;
    return (0);
}


