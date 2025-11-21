#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *names =  new Zombie(name);
    return (names);
}