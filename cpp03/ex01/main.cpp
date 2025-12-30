#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    ClapTrap Brosly("Brosly");
    ClapTrap Jackichan("Jackichan");
    ScavTrap Monster("Monster");

    std::cout << "\n--- ClapTrap fight ---\n";
    Brosly.attack("Jackichan");
    Jackichan.takeDamage(2);

    std::cout << "\n--- ScavTrap attack ---\n";
    Monster.attack("Brosly");

    std::cout << "\n--- Gate mode ---\n";
    Monster.guardGate();

    return 0;
}