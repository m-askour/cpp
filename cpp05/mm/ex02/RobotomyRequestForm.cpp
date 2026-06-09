#include "RobotomyRequestForm.hpp"
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm ("RobotomyRequestForm", 72, 45), target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target)
{
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
void RobotomyRequestForm::execute(const Bureaucrat  & executor) const
{
    if (!this->get_sign())
        throw GradeTooLowException();
    if (executor.getGrade() > get_grade_exec())
        throw GradeTooLowException();
    std::cout << "Bzzzzzz..."<< std::endl;
    if (rand() % 2)
    {
        std::cout << this->target << "has been robotomized successfully." << std::endl;
        return ;
    }
    else
    {
        std::cout << "Robotomy failed on " << this->target << "."<< std::endl;
        return ;
    }
}
