#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include<iostream>
#include <string>
class AAnimal
{
protected:
    std::string type;
public:
    AAnimal();
    AAnimal(AAnimal const &other);
    AAnimal &operator=(AAnimal const &other);
    virtual ~AAnimal();
    std::string getType()const;
    virtual  void makeSound()const = 0;
};

#endif