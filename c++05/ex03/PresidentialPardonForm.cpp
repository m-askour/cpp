#include "PresidentialPardonForm.hpp"
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AFrom("PresidentialPardonForm", 25, 5), target(target)
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AFrom(other)
{
    this->target = other.target;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

}