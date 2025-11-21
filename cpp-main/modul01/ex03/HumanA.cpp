#include "HumanA.hpp"
HumanA::HumanA(std::string name, Weapon &type) : name(name), Type(type)
{
}

HumanA::~HumanA()
{
    
}
void HumanA::attack()
{
    std::cout << name << " attacks with their"<< Type.getType() <<"\n";
}