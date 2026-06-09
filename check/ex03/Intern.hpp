#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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