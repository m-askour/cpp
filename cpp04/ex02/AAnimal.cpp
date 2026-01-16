#include "AAnimal.hpp"

AAnimal::AAnimal():Type("Animal")
{
}
AAnimal::AAnimal(std::string type):Type(type)
{
    std::cout<<"Animal param constructer called"<<std::endl;
}
AAnimal::AAnimal(AAnimal const &other)
{
    *this = other;
}
AAnimal &AAnimal::operator=(AAnimal const &other)
{
    if (this != &other)
        this->Type = other.Type;
    return *this;
}

AAnimal::~AAnimal()
{
}


std::string AAnimal::getType()const
{
    return Type;
}
