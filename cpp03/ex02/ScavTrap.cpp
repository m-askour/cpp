#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
    Hit_point = 100;
    Energy_point = 50;
    Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other)
{
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name
              << " is now in Gate keeper mode\n";
}
