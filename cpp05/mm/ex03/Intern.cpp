#include "Intern.hpp"
Intern::Intern()
{
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    int i = 0;
    std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    while (i < 3 && formName != forms[i])
        i++;
    switch(i)
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return new ShrubberyCreationForm(target);
    
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return new RobotomyRequestForm(target);
    
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "Intern can't create " << formName
                  << " because it doesn't exist!" << std::endl;
            return NULL;

}
