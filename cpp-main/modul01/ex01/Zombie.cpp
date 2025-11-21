#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name), num(10){}
Zombie::~Zombie(){}

void Zombie::announce()
{
    std::cout<<"this is the zombie allocat" <<name<<"\n";
}