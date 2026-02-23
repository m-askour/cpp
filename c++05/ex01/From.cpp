#include "From.hpp"
From::From(std::string name, int grade_sign, int grade_exec) : name(name), grade_sign(grade_sign), grade_exec(grade_exec), sign(false)
{
    if (grade_sign < 1 || grade_exec < 1)
        throw GradeTooHighException();
    else if (grade_sign > 150 || grade_exec > 150)
        throw GradeTooLowException();
}
From::From(const From &other)
    : name(other.name),
      grade_sign(other.grade_sign),
      grade_exec(other.grade_exec),
      sign(other.sign)
{
}
From &From::operator=(const From &other)
{
    if (this != &other)
    {
        this->sign = other.sign;
        // this->grade_sign = other.grade_sign;
        // this->grade_exec = other.grade_exec;
        // this->name = other.name; this is const so we can't assign it after initialization
    }
    return *this;
}
From::~From()
{

}
bool From::get_sign() const
{
    return this->sign;
}
std::string From::get_name() const
{
    return this->name;
}
int From::get_grade_sign() const
{
    return this->grade_sign;
}
int From::get_grade_exec() const
{
    return this->grade_exec;
}
void From::beSigned(const class Bureaucrat& bureaucrat)
{
    if (bureaucrat.signForm() > this->grade_sign)
        throw GradeTooLowException();
    this->sign = true;
}
const char* From::GradeTooHighException::what() const throw()
{
            return "Grade is too high!";
}
const char* From::GradeTooLowException::what() const throw()
{
            return "Grade is too low!";
}
std::ostream& operator<<(std::ostream& os, const From& from)
{
    os << "Form Name: " << from.get_name() << ", Grade to Sign: " << from.get_grade_sign() << ", Grade to Execute: " << from.get_grade_exec() << ", Signed: " << (from.get_sign() ? "Yes" : "No");
    return os;
}