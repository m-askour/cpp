#include "Intern.hpp"
Intern::Intern()
{
}
Intern::Intern(const Intern &other)
{
    (void)other;
}
Intern &Intern::operator=(const Intern &other)  
{
    (void)other;
    return *this;
}
Intern::~Intern()
{
}
AFrom* Intern::makeForm(std::string formName, std::string target)
{
    if (formName == "ShrubberyCreationForm")
        return new ShrubberyCreationForm(target);
    else if (formName == "RobotomyRequestForm")
        return new RobotomyRequestForm(target);
    else if (formName == "PresidentialPardonForm")
        return new PresidentialPardonForm(target);
    else
    {
        std::cout << "Intern can't create " << formName << " because it doesn't exist!" << std::endl;
        return NULL;
    }
}   