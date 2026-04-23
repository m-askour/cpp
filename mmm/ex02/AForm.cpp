#include "AForm.hpp"
AForm::AForm(std::string name, int grade_sign, int grade_exec)
    : name(name),
      grade_sign(grade_sign),
      grade_exec(grade_exec),
      sign(false)
{
    if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm &other)
    : name(other.name),
      grade_sign(other.grade_sign),
      grade_exec(other.grade_exec),
      sign(other.sign)
{
}
AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->sign = other.sign;
    }
    return *this;
}
AForm::~AForm()
{

}
bool AForm::get_sign() const
{
    return this->sign;
}
std::string AForm::get_name() const
{
    return this->name;
}
int AForm::get_grade_sign() const
{
    return this->grade_sign;
}
int AForm::get_grade_exec() const
{
    return this->grade_exec;
}
void AForm::beSigned(const class Bureaucrat& bureaucrat)
{
    if (bureaucrat.signForm() > this->grade_sign)
        throw GradeTooLowException();
    this->sign = true;
}
const char* AForm::GradeTooHighException::what() const throw()
{
            return "Grade is too high!";
}
const char* AForm::GradeTooLowException::what() const throw()
{
            return "Grade is too low!";
}
const char* AForm::NotSignedException::what() const throw()
{
    return "Form is not signed yet!";
}

std::ostream& operator<<(std::ostream& os, const AForm& from)
{
    os << "Form Name: " << from.get_name() << ", Grade to Sign: " << from.get_grade_sign() << ", Grade to Execute: " << from.get_grade_exec() << ", Signed: " << (from.get_sign() ? "Yes" : "No");
    return os;
}