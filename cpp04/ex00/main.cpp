#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{

    // the simple use
    // Cat cat;
    // Cat cat1;
    // cat = cat1;
    // Dog dog;
    // cat.makeSound();
    // dog.makeSound();
    // with out virtual function
    WrongAnimal *A = new WrongCat();
    A->makeSound();
    // Polymorphisam with pointer
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();    // will output the cat sound!
    j->makeSound();    // will output the dog sound;
    meta->makeSound(); // will output the animal sound;
    // meta->setType("Cat");//this test about why we use const object
    delete i;
    delete j;
    delete meta;
    // polymorphisam with refrence
    //  Cat C;
    //  Dog D;
    //  Animal &ref1 = C;
    //  Animal &ref2 = D;
    //  ref1.makeSound();
    //  ref2.makeSound();
    // object slicing
    //  Dog DOG;
    //  Animal slicingA = DOG;
    //  slicingA.makeSound();
    // const polymorphisam
    //  const Animal &constRef = C;
    //  constRef.makeSound();

    return 0;
}
