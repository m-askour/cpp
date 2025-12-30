#ifndef CAT_HPP
#define CAT_HPP
#include "Brain.hpp"
#include "Animal.hpp"
class Cat: public Animal
{
private:
    Brain* brain;
public:
    Cat();
    Cat(Cat const &other);
    Cat &operator=(Cat const &other);
    ~Cat();
    void makeSound()const;//this is overriding function whene we have in the basec class an virtual this function but if not we talking about the redifine function  
};


#endif