#include "Bureaucrat.hpp"
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooLowException(grade);
    else if (grade > 150)
        throw GradeTooHighException(grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
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
    return name;
}
int Bureaucrat::getGrade() const
{
    return grade;
}
void Bureaucrat::increment_Grade()
{
    if (grade <= 1)
        throw GradeTooLowException(grade);
    grade++;
}
void Bureaucrat::decrement_Grade()
{
    if (grade >= 150)
        throw GradeTooHighException(grade);
    grade--; // thhis to uncriment the value of grade
}
class Bureaucrat::GradeTooHighException : public std::exception
{
private:
    int value;

public:
    // constracter
    GradeTooHighException(int V) : value(V)
    {
    }
    // overide function froom exception
    const char *what() const noexcept
    {
        return "the value of grade is to High";
    }
};
class Bureaucrat::GradeTooLowException : public std::exception
{
private:
    int value;

public:
    // constracter
    GradeTooLowException(int v) : value(v) {}
    const char *what() const noexcept
    {
        return "the value of grade is to low";
    }
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}