#include "Cat.hpp"

Cat::Cat()
{
    std::cout<<"Cat Default constructer called"<<std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(Cat const &other):AAnimal(other)
{
    std::cout<<"Cat Copy constructer called"<<std::endl;
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(Cat const &other)
{
    std::cout<<"Cat Copy assignment called"<<std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout<<"Cat Destructer called"<<std::endl;
    delete brain;
}

void Cat::makeSound()const
{
    std::cout<< "cat say: Meyyyyyyyow\n";
}
