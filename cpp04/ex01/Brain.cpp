#include "Brain.hpp"

Brain::Brain()
{
    std::cout<<"Brain Default constructer called"<<std::endl;
    for (int i = 0; i < 100;i++)
    {
        ideas[i] = ""; 
    }
}
Brain::Brain(Brain const &other)
{
    *this = other;
}
Brain &Brain::operator=(Brain const &other)
{
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
        {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
Brain::~Brain()
{
    std::cout<<"Brain Destructer called"<<std::endl;
}
std::string Brain::getRandomIdea() const
{
    return *ideas;
}