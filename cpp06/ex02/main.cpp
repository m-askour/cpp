#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 5; i++)
    {
        std::cout << "---- Test " << i + 1 << " ----" << std::endl;

        Base* ptr = generate();

        std::cout << "Pointer identification: ";
        identify(ptr);

        std::cout << "Reference identification: ";
        identify(*ptr);

        delete ptr;
        std::cout << std::endl;
    }

    return 0;
}