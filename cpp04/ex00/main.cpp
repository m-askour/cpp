#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main()
{
    //the simple use 
    Cat cat;
    Dog dog;
    cat.makeSound();
    dog.makeSound();
    //Polymorphisam with pointer 
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;
    //polymorphisam with refrence 
    Cat C;
    Dog D;
    Animal &ref1 = C;
    Animal &ref2 = D;
    ref1.makeSound();
    ref2.makeSound();
    //object slicing
    Dog DOG;
    Animal slicingA = DOG;
    slicingA.makeSound();
    //const polymorphisam 
    const Animal &constRef = C;
    constRef.makeSound();
    return 0;
}