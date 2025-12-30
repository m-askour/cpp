#include "Cat.hpp"

Cat::Cat()
{
    brain = new Brain();
}
Cat::Cat(Cat const &other):Animal(other)
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