#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main()
{
    ClapTrap a("Brosly");
    a.attack("enemy");
    a.takeDamage(5);
    a.beRepaired(3);

    ScavTrap b("Monster");
    b.attack("Brosly");
    b.takeDamage(20);
    b.beRepaired(10);
    b.guardGate();

    FragTrap c("GIST");
    c.attack("Monster");
    c.takeDamage(30);
    c.beRepaired(15);
    c.highFivesGuys();
    return 0;
}