#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream> 
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound(); //will output the sound of the dog
    delete j;//should not create a leak
    delete i;
    return 0;
}
