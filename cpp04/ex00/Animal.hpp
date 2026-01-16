#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include<iostream>
#include <string>
class Animal
{
protected:
    std::string Type;
public:
    //ocf
    Animal();
    Animal(std::string type);
    Animal(Animal const &other);
    Animal &operator=(Animal const &other);
    virtual ~Animal();
    //methods
    std::string getType()const;
    virtual  void makeSound()const;
};

#endif