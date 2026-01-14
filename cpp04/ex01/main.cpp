#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    Animal *arr[100];
    for (int k = 0; k < 100; k++)
    {
        if (k % 2 == 0)
            arr[k] = new Dog();
        else
            arr[k] = new Cat();
    }
    arr[4]->makeSound();
    arr[72]->makeSound();
    for (int k = 0; k < 100; k++)
    {
        delete arr[k];
    }
    return 0;
}
