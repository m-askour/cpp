#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define SIZE 10

int main()
{
    Animal *arr[SIZE];
    for (int k = 0; k < SIZE; k++)
    {
        if (k < SIZE / 2)
            arr[k] = new Dog();
        else
            arr[k] = new Cat();
    }
    std::cout<<"==========================================================="<<std::endl;
    arr[2]->makeSound();
    arr[8]->makeSound();
    std::cout<<"==========================================================="<<std::endl;
    for (int k = 0; k < SIZE; k++)
    {
        delete arr[k];
    }
    return 0;
}
