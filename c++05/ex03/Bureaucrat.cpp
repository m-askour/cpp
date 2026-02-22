#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat(std::string name , int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat()
{

}
std::string Bureaucrat::getName() const
{
    return this->name;
}
int Bureaucrat::getGrade() const
{
    return this->grade;
}
void Bureaucrat::incrementGrade()
{
    if (this->grade>= 150)
        throw GradeTooHighException();
    this->grade++;
}
void Bureaucrat::decrementGrade()
{
    if (this->grade <= 1)
        throw GradeTooLowException();
    this->grade--;
}
int Bureaucrat::signForm() const
{
    return this->grade;
}

class Bureaucrat::GradeTooHighException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Grade is too high!";
        }
};

class Bureaucrat::GradeTooLowException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Grade is too low!";
        }
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &B)
{
    out << B.getName() << ", bureaucrat grade " << B.getGrade() << ".";
    return out;
}