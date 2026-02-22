#include "ShrubberyCreationForm.hpp"
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AFrom("ShrubberyCreationForm", 145, 137), target(target)
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AFrom(other)
{
    this->target = other.target;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{}