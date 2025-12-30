#include "Animal.hpp"

Animal::Animal():Type("")
{
}
Animal::Animal(Animal const &other)
{
    *this = other;
}
Animal &Animal::operator=(Animal const &other)
{
    if (this != &other)
        this->Type = other.Type;
    return *this;
}

Animal::~Animal()
{
}


std::string Animal::getType()const
{
    return Type;
}

void Animal::makeSound()const
{
    std::cout<<"Unoun anim say: Groooooooo\n";
}