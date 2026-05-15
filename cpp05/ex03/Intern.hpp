#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
class Intern
{
private:
    /* data */
public:
    Intern(/* args */);
    ~Intern();

    AForm* makeForm(std::string formname, std::string target);
};



#endif