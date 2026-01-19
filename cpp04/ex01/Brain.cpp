#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructer called" << std::endl;
}
Brain::Brain(Brain const &other)
{
    std::cout << "Brain Copy constructer called" << std::endl;
    *this = other;
}
Brain &Brain::operator=(Brain const &other)
{
    std::cout << "Brain Copy assignment called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructer called" << std::endl;
}
