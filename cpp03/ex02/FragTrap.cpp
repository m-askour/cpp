#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap("FragTrap")
{
    std::cout<<"FragTrap default constracter called\n";
    Hit_point = 100;
    Energy_point = 100;
    Attack_damage = 30;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    std::cout<<"FragTrap param constracter called\n";
    Hit_point = 100;
    Energy_point = 100;
    Attack_damage = 30;
}
FragTrap::FragTrap(FragTrap const &other):ClapTrap(other)
{
    std::cout<<"FragTrap copy constracter called\n";
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
    std::cout<<"FragTrap copy assign called\n";
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}
FragTrap::~FragTrap()
{
    std::cout<<"FragTrap Distracter called\n";
}
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " requests a high five!\n";
}
