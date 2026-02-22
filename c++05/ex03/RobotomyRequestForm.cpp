#include "RobotomyRequestForm.hpp"
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
{}