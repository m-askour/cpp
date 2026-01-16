#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout<<"Cat Default constructer called"<<std::endl;

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
    std::cout<<"Cat Destructer called"<<std::endl;

}
void Cat::makeSound()const
{
    std::cout<< "cat say: Meyyyyyyyow\n";
}