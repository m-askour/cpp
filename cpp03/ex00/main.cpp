#include "ClapTrap.hpp"

int main ()
{
    ClapTrap broslie("BrosLie");
    ClapTrap jackichan = broslie;
    jackichan = broslie;
    broslie.attack("JakiChan");
    jackichan.takeDamage(10);
    
    jackichan.attack("BrosLie");
    broslie.takeDamage(12);

    broslie.beRepaired(5);
    jackichan.beRepaired(8);

    broslie.attack("JakiChan");
    jackichan.takeDamage(10);
    return 0;
}