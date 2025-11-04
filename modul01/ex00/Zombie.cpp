#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
    std::cout << "This zombie " << name << " created\n";
}
Zombie::~Zombie()
{
    std::cout << "this zombie" << name << " destroied\n";
}
void Zombie::announce(void)
{
    std:: cout << name << ": BraiiiiiiinnnzzzZ..." << "\n";
}
