#include "Cat.hpp"

Cat::Cat()
{
}
Cat::Cat(Cat const &other):Animal(other)
{
}
Cat &Cat::operator=(Cat const &other)
{
    if (this != &other)
        Cat::operator=(other);
    return *this;
}
Cat::~Cat()
{
}
void Cat::makeSound()const
{
    std::cout<< "cat say: Meyyyyyyyow\n";
}