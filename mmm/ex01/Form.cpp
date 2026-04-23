#include "Form.hpp"

Form::Form(std::string name, int grade_sign, int grade_exec) : name(name), grade_sign(grade_sign), grade_exec(grade_exec), sign(false)
{
    if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    else if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
}
Form::Form(const Form &other)
    : name(other.name),
      grade_sign(other.grade_sign),
      grade_exec(other.grade_exec),
      sign(other.sign)
{
}
Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->sign = other.sign;
    }
    return *this;
}
Form::~Form()
{

}
bool Form::get_sign() const
{
    return this->sign;
}
std::string Form::get_name() const
{
    return this->name;
}
int Form::get_grade_sign() const
{
    return this->grade_sign;
}
int Form::get_grade_exec() const
{
    return this->grade_exec;
}
void Form::beSigned(const class Bureaucrat& bureaucrat)
{
    if (bureaucrat.signForm() > this->grade_sign)
        throw GradeTooLowException();
    this->sign = true;
}
const char* Form::GradeTooHighException::what() const throw()
{
            return "Grade is too high!";
}
const char* Form::GradeTooLowException::what() const throw()
{
            return "Grade is too low!";
}
std::ostream& operator<<(std::ostream& os, const Form& Form)
{
    os << "Form Name: " << Form.get_name() << ", Grade to Sign: " << Form.get_grade_sign() << ", Grade to Execute: " << Form.get_grade_exec() << ", Signed: " << (Form.get_sign() ? "Yes" : "No");
    return os;
}