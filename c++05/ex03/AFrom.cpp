#include "AFrom.hpp"
AFrom::AFrom(std::string name, int grade_sign, int grade_exec)
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
AFrom::AFrom(const AFrom &other)
    : name(other.name),
      grade_sign(other.grade_sign),
      grade_exec(other.grade_exec),
      sign(other.sign)
{
}
AFrom &AFrom::operator=(const AFrom &other)
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
AFrom::~AFrom()
{

}
bool AFrom::get_sign() const
{
    return this->sign;
}
std::string AFrom::get_name() const
{
    return this->name;
}
int AFrom::get_grade_sign() const
{
    return this->grade_sign;
}
int AFrom::get_grade_exec() const
{
    return this->grade_exec;
}
void AFrom::beSigned(const class Bureaucrat& bureaucrat)
{
    if (bureaucrat.signForm() > this->grade_sign)
        throw GradeTooLowException();
    this->sign = true;
}
const char* AFrom::GradeTooHighException::what() const throw()
{
            return "Grade is too high!";
}
const char* AFrom::GradeTooLowException::what() const throw()
{
            return "Grade is too low!";
}
const char* AFrom::NotSignedException::what() const throw()
{
    return "Form is not signed yet!";
}
std::ostream& operator<<(std::ostream& os, const AFrom& from)
{
    os << "Form Name: " << from.get_name() << ", Grade to Sign: " << from.get_grade_sign() << ", Grade to Execute: " << from.get_grade_exec() << ", Signed: " << (from.get_sign() ? "Yes" : "No");
    return os;
}