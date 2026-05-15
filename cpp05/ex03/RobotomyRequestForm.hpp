#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
// your class here
class RobotomyRequestForm : public AForm
{
private:
        std::string target;
public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const & executor) const;

};



#endif