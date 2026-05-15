#include "Intern.hpp"
Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    if (formName == "shrubbery creation")
    {
        std::cout << "Intern creates " << formName << std::endl;
        return new ShrubberyCreationForm(target);
    }
    else if (formName == "robotomy request")
    {
        std::cout << "Intern creates " << formName << std::endl;
        return new RobotomyRequestForm(target);
    }
    else if (formName == "presidential pardon")
    {
        std::cout << "Intern creates " << formName << std::endl;
        return new PresidentialPardonForm(target);
    }
    else
    {
        std::cout << "Intern can't create " << formName
                  << " because it doesn't exist!" << std::endl;
        return NULL;
    }
}