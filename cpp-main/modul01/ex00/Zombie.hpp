#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <new>
#include <string>
class Zombie{
private:
std::string name;
public:
    Zombie(std::strign name);
    ~Zombie();
    void announce(void);
};
Zombie* newZombie( std::string name );
void randomChump( std::string name );
#endif