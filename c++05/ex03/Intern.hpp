#ifndef INTERN_HPP
#define INTERN_HPP
#include "AFrom.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern
{
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();
        AFrom* makeForm(std::string formName, std::string target);
};

#endif