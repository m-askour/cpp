#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include<iostream>
#include <string>
class AAnimal
{
protected:
    std::string Type;
public:
    AAnimal();
    AAnimal(std::string type);
    AAnimal(AAnimal const &other);
    AAnimal &operator=(AAnimal const &other);
    virtual ~AAnimal();
    std::string getType()const;
    virtual  void makeSound()const = 0;//pure virtual function 
};

#endif