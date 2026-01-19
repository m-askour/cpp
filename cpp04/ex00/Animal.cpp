#include "Animal.hpp"

Animal::Animal()
{
    std::cout<<"Animal Default constructer called"<<std::endl;
    type = "Animall";
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
        this->type = other.type;
    return *this;
}

Animal::~Animal()
{
    std::cout<<"Animal Destructer called"<<std::endl;
}

std::string Animal::getType() const
{
    return type;
}
// void Animal::setType(const std::string& other)
// {
//     this->type = other;
// }
void Animal::makeSound() const
{
    std::cout<<"Unoun anim say: Groooooooo\n";
}
