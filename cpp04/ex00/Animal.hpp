#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include<iostream>
#include <string>


class Animal
{
protected:
    std::string type;
public:
    //ocf
    Animal();
    Animal(Animal const &other);
    Animal &operator=(Animal const &other);
    virtual ~Animal();
    //methods
    std::string getType() const;
    // void setType(const std::string& other);
    virtual  void makeSound() const;
};

#endif
