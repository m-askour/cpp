#include "ClapTrap.hpp"
ClapTrap::ClapTrap():Name(""), Hit_point(10), Energy_point(10), Attack_damage(0)
{
    std::cout<<"Claptrap Default constracter called\n";
}
ClapTrap::ClapTrap(std::string name):Name(name), Hit_point(10), Energy_point(10), Attack_damage(0)
{
    std::cout<<"Claptrap Param constracter called\n";
}
ClapTrap::ClapTrap(ClapTrap const &other)
{
    std::cout<<"ClapTrap copy constracter called\n";
    *this = other;
}
ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
    std::cout<<"ClapTrap copy assign called\n";
    if (this != &other)
    {
        this->Name = other.Name;
        this->Hit_point = other.Hit_point;
        this->Energy_point = other.Energy_point;
        this->Attack_damage = other.Attack_damage;
    }
    return *this;
}
ClapTrap::~ClapTrap()
{
    std::cout<<"Claptrap Destracter called\n";
}
void ClapTrap::attack(const std::string& target)
{
    if (Hit_point > 0 && Energy_point > 0)
        std::cout <<"ClapTrap " << Name <<" attacks " << target <<" , causing "<< Attack_damage <<" points of damage!\n";
    else
        std::cout <<"ClapTrap " << Name<<" cannot attack (no energy or hit points).\n";

}
void ClapTrap::takeDamage(unsigned int amount)
{
    Hit_point -= amount;
    if (Hit_point < 0)
        Hit_point = 0;
    std::cout<<"ClapTrap " << Name <<"takeDamage lose "<<amount<<" hp!\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(Energy_point > 0 && Hit_point > 0)
    {
    Energy_point += amount;
    std::cout<<"ClapTrap " << Name <<"beRepaired "<<Energy_point<<" hp!\n";
    }
    else
       std::cout <<"ClapTrap " << Name<<" cannot repair (no energy or hit points).\n"; 
}