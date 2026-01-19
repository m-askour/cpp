#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout<<"AAnimal Default constructer called"<<std::endl;
    type = "AAnimal";
}

AAnimal::AAnimal(AAnimal const &other)
{
    std::cout<<"AAnimal Copy constructer called"<<std::endl;
    *this = other;
}
AAnimal &AAnimal::operator=(AAnimal const &other)
{
    std::cout<<"AAnimal Copy assinged called"<<std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout<<"AAnimal Destructer called"<<std::endl;

}


std::string AAnimal::getType()const
{
    return type;
}

