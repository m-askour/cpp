#include "Dog.hpp"

Dog::Dog()
{
}
Dog::Dog(Dog const &other):Animal(other)
{
}
Dog &Dog::operator=(Dog const &other)
{
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
}
void Dog::makeSound()const
{
    std::cout <<"Dog say: Hooooooooooooooow\n";
}

