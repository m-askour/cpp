#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    //if the range sing <= 25 andrange exec <= 5
    // the target hasse  been pardoned by  Zaphod Beeblebrox
    if (!this->get_sign())
        throw GradeTooLowException();
    if (executor.getGrade() > get_grade_exec())
        throw GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}