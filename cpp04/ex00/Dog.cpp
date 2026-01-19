#include "Dog.hpp"

Dog::Dog()
{
    std::cout<<"Dog Default constructer called"<<std::endl;
    type = "Dog";
}

Dog::Dog(Dog const &other):Animal(other)
{
    std::cout<<"Dog copy constracter called"<<std::endl;
}

Dog &Dog::operator=(Dog const &other)
{
    std::cout<<"Dog copy assignment called"<<std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout<<"Dog Destructer called"<<std::endl;
}

void Dog::makeSound()const
{
    std::cout <<"Dog say: Hooooooooooooooow\n";
}