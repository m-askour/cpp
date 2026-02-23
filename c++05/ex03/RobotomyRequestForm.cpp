#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AFrom("RobotomyRequestForm", 72, 4), target(target)
{}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AFrom(other)
{
    this->target = other.target;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!get_sign())
        throw AFrom::GradeTooLowException();
    if (executor.getGrade() > get_grade_exec())
        throw AFrom::GradeTooLowException();
    else
    {
        std::cout << "Bzzzzzz... " << target << " has been robotomized successfully 50% of the time." << std::endl;
    }
    if (rand() % 2)
    {
        std::cout << target << " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on " << target << "." << std::endl;
    }
}