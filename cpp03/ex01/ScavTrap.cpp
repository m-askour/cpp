#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap("ScavTrap")
{
    std::cout<<"ScavTrap Default constracter called\n";
    Hit_point = 100;
    Energy_point = 50;
    Attack_damage = 20;
}
ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    std::cout<<"ScavTrap Param constracter called\n";
    Hit_point = 100;
    Energy_point = 50;
    Attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &other):ClapTrap(other)
{
    std::cout<<"ScavTrap Copy constracter called\n";
}
ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
    std::cout<<"ScavTrap copy assign called\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout<<"ScavTrap Destracter called\n";
}
void ScavTrap::guardGate()
{
    std::cout<<"that ScavTrap is now in Gatekeeper mode\n";
}
void ScavTrap::attack(const std::string& target)
{
    if (Hit_point > 0 && Energy_point > 0)
        std::cout <<"ScavTrap " << Name <<" attacks " << target <<" , causing "<< Attack_damage <<" points of damage!\n";
    else
        std::cout <<"ScavTrap " << Name<<" cannot attack (no energy or hit points).\n";
}
