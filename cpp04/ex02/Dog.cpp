#include "Dog.hpp"

Dog::Dog()
{
    brain = new Brain();
}
Dog::Dog(Dog const &other):Animal(other)
{
    brain = new Brain(*other.brain);
}
Dog &Dog::operator=(Dog const &other)
{
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    delete brain;
}
void Dog::makeSound()const
{
    std::cout <<"Dog say: Hooooooooooooooow\n";
}

