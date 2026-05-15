#include "RobotomyRequestForm.hpp"
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm ("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    //if range sign <= 72 and range exec<= 45
    //1 makinga some noises
    //robotomized successfully 50%(some time it works some time not)
    if (!this->get_sign())
        throw GradeTooLowException();
    if (executor.getGrade() > get_grade_exec())
        throw GradeTooLowException();
    else
    {
        std::cout << "Bzzzzzz..." << this->target << "has been robotomized successfully 50% of the time." << std::endl;
        return ;
    }
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
