#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap("FragTrap")
{
    
}
FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    this->Hit_point = 100;
    this->Energy_point = 100;
    this->Attack_damage = 30;
}
FragTrap::FragTrap(FragTrap const &other):ClapTrap(other)
{

}
FragTrap &FragTrap::operator=(FragTrap const &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}
FragTrap::~FragTrap()
{

}
void FragTrap::highFivesGuys(void)
{

}