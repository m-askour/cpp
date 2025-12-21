#include "Zombie.hpp"
Zombie::Zombie()
{
}
Zombie::Zombie(std::string name) : name(name){}
Zombie::~Zombie(){
    std::cout << "ditroied the Zombiez\n";
}

void Zombie::announce()
{
    std::cout<<"this is the zombie allocat" <<"\n";
}