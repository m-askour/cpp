#include "Dog.hpp"

Dog::Dog()
{
    std::cout<<"Dog Deafault Constructer called"<<std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(Dog const &other):Animal(other)
{
    std::cout<<"Dog Copy Constructer called"<<std::endl;
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(Dog const &other)
{
    std::cout<<"Dog Copy assignment called"<<std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
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

