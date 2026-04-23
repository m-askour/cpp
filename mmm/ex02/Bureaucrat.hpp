#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <exception>
class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();
    std::string getName() const; // this to geet the name
    int getGrade() const;        // this to geet the grade
    void increment_Grade();      // this just to modifide the internel state
    void decrement_Grade();      // this just to modifide the internel state
    class GradeTooHighException; // this class inheriting from the exception to improv the error of overflow
    class GradeTooLowException;  // this class inheriting from the exception to improv the error of inderflow
    void signForm();
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b); // to print work
#endif