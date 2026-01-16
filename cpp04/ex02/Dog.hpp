#ifndef DOG_HPP
#define DOG_HPP
#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog: public AAnimal
{
private:
    Brain* brain;
public:
    Dog();
    Dog(Dog const &other);
    Dog &operator=(Dog const &other);
    ~Dog();
    void makeSound()const;
};

#endif