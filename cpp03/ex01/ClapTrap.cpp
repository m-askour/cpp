#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Constracter called\n";
}
ClapTrap::ClapTrap(std::string name):Name(name), Hit_point(10), Energy_point(10), Attack_damage(0)
{
    std ::cout << "Param Constracter called\n";
}
ClapTrap::ClapTrap (const ClapTrap &other)
{
    std::cout<<"Copy Constracter called\n";
    *this = other;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout<<"Assignment operator called\n";
    if (this != &other)
    {
        this->Name = other.Name;
        this->Attack_damage = other.Attack_damage;
        this->Energy_point = other.Energy_point;
        this->Hit_point = other.Hit_point;
    }
    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout<<"Destracter called\n";
}

void ClapTrap::attack(const std::string& target)
{
    std::cout<<"ClapTrap "<< Name <<" attacks "<< target<<", causing "<< Attack_damage<< " points of damage!\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
    Energy_point -= amount;
    if (Energy_point < 0)
        Energy_point = 0;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    Energy_point += amount;
}
