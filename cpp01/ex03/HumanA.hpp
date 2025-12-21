#ifndef HUMAN_A
#define HUMAN_A
#include <string>
#include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon &Type;
public:
    HumanA(std::string name, Weapon &type);
    ~HumanA();
    void attack();
};
#endif