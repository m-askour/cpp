#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout<<"Dog Constructer called"<<std::endl;
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
    std::cout<<"Dog Destructer called"<<std::endl;
    delete brain;
}
void Dog::makeSound()const
{
    std::cout <<"Dog say: Hooooooooooooooow\n";
}
