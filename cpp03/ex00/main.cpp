#include "ClapTrap.hpp"

int main()
{
    ClapTrap Brosly("Brosly");
    ClapTrap Jackichan("Jakichan");

    std::cout<<"first attack\n";
    Brosly.attack("Jackichan");
    Jackichan.takeDamage(2);
    std::cout<<"points\n";
    Brosly.beRepaired(10);
    Jackichan.beRepaired(0);
    std::cout<<"secondattack\n";
    Jackichan.attack("Brosly");
    Brosly.takeDamage(1);
    std::cout<<"points\n";
    Brosly.beRepaired(0);
    Jackichan.beRepaired(5);
    return 0;

}