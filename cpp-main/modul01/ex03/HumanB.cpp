#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name)
{
}

HumanB::~HumanB()
{
}
void HumanB::setWeapon(Weapon *weapon)
{
    this->weapon = weapon;
}
void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their" << weapon->getType() <<"\n";
    else
            std::cout << name << " has no weapon to attack\n";
}
