#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream> 
int main()
{
    // const AAnimal me;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    std::cout << j->getType() << "Dog" << std::endl;
    std::cout << i->getType() << "Cat" << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound(); //will output the sound of the dog
    // meta->makeSound();
    delete j;//should not create a leak
    delete i;
    // delete meta;
    return 0;
}