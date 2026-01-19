#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout<<"WrongAnimal Default constracter called"<<std::endl;
    type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout<<"WrongAnimal copy constracter called"<<std::endl;
    *this = other;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout<<"WrongAnimal copy assignment called"<<std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal Destructor called"<<std::endl;

}

void WrongAnimal::makeSound() const
{
    std::cout<<"Wroganimal make a sound"<<std::endl;
}
