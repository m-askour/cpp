#include "Cat.hpp"

Cat::Cat() 
{
    std::cout << "Cat Default constructer called" << std::endl;
    type = "Cat";
}

Cat::Cat(Cat const &other) : Animal(other)
{
    std::cout << "Cat copy constructer called" << std::endl;
}

Cat &Cat::operator=(Cat const &other)
{
    std::cout << "Cat copy assigne called" << std::endl;

    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructer called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "cat say: Meyyyyyyyow\n";
}
