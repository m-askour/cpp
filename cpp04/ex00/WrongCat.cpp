#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout<<"WrongCat Default constracter called"<<std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other):WrongAnimal(other)
{
    std::cout<<"WrongCat copy constracter called"<<std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout<<"WrongCat copy assignment called"<<std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat Destructor called"<<std::endl;
}

void WrongCat::makeSound() const
{
    std::cout<<"Wroganimal make a sound"<<std::endl;
}
