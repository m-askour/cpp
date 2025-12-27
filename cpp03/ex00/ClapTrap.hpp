#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>
class ClapTrap
{
private:
    std::string Name;
    int Hit_point;
    int Energy_point;
    int Attack_damage;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap (const ClapTrap &name);
    ClapTrap &operator=(const ClapTrap &name);
    ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif