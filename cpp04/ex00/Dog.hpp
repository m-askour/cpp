#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog: public Animal
{
private:
    
public:
    Dog();
    Dog(Dog const &other);
    Dog &operator=(Dog const &other);
    ~Dog();
    void makeSound()const;
};

#endif