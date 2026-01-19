#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
private:
public:
    // ocf
    Dog();
    Dog(Dog const &other);
    Dog &operator=(Dog const &other);
    virtual ~Dog();
    // methods
    void makeSound() const;
};

#endif