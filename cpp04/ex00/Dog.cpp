#include "Dog.hpp"

Dog::Dog()
{
    std::cout<<"Dog Default constructer called"<<std::endl;

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
    std::cout<<"Dog Destructer called"<<std::endl;
}
void Dog::makeSound()const
{
    std::cout <<"Dog say: Hooooooooooooooow\n";
}

