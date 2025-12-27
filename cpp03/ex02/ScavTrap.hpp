#ifndef SAVTRAP_HPP
#define SAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string>
class ScavTrap: public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &other);
        ScavTrap &operator=(ScavTrap const &other);
        ~ScavTrap();
        void guardGate();
};
#endif