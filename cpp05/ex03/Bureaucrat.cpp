#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade)
{}
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
    if (this->grade<= 1)
        throw GradeTooHighException();
    this->grade--;
}
void Bureaucrat::decrementGrade()
{
    if (this->grade >= 150)
        throw GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signAForm(AForm  &AForm) const
{
    try
    {
        AForm.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " couldn't sign " << AForm.get_name()  << " because "<< e.what() << '\n';
        return;
    }
    std::cout << this->name << " signed " << AForm.get_name() << '\n'; 
}

void Bureaucrat::executeForm(AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->name << " couldn't execute "
                  << form << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &B)
{
    out << B.getName() << ", bureaucrat grade " << B.getGrade() << ".";
    return out;
}
