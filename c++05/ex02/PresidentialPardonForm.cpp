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
        if (!this->get_sign())
        {
            std::cout << "Form " << this->get_name() << " is not signed yet!" << std::endl;
            return;
        }
        if (executor.getGrade() > this->get_grade_exec())
        {
            std::cout << executor.getName() << " can't execute " << this->get_name() << " because his grade is too low!" << std::endl;
            return;
        }
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}