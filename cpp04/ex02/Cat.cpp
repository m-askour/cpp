#include "Cat.hpp"

Cat::Cat():AAnimal("Cat")
{
    brain = new Brain();
}
Cat::Cat(Cat const &other):AAnimal(other)
{
    brain = new Brain(*other.brain);
}
Cat &Cat::operator=(Cat const &other)
{
    if (this != &other)
        Cat::operator=(other);
    return *this;
}
Cat::~Cat()
{
    delete brain;
}
void Cat::makeSound()const
{
    std::cout<< "cat say: Meyyyyyyyow\n";
}