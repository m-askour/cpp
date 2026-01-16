#include "Animal.hpp"

Animal::Animal():Type("")
{
    std::cout<<"Animal Default constructer called"<<std::endl;
}
Animal::Animal(std::string type):Type(type)
{
    std::cout<<"Animal param constructer called"<<std::endl;
}
Animal::Animal(Animal const &other)
{
    std::cout<<"Animal Copy constructer called"<<std::endl;
    *this = other;
}
Animal &Animal::operator=(Animal const &other)
{
    std::cout<<"Animal Copy assinged called"<<std::endl;
    if (this != &other)
        this->Type = other.Type;
    return *this;
}

Animal::~Animal()
{
    std::cout<<"Animal Destructer called"<<std::endl;

}


std::string Animal::getType()const
{
    return Type;
}

void Animal::makeSound()const
{
    std::cout<<"Unoun anim say: Groooooooo\n";
}