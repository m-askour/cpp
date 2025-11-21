#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : Type(type)
{
    std::cout << Type << "\n";
}

Weapon::~Weapon()
{
    
}
const std::string &Weapon::getType() const
{
    return Type;
}

void Weapon::setType(const std::string &type)
{
    Type = type;
}