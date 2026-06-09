#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class AForm
{
private:
    const std::string name;
    const int grade_sign;
    const int grade_exec;
    bool sign;
public:
    AForm(std::string name, int grade_sign, int grade_exec);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    ~AForm();
    bool get_sign() const;
    virtual void execute(Bureaucrat const &executor) const = 0;
    std::string get_name() const;
    int get_grade_sign() const;
    int get_grade_exec() const;
    void beSigned(const class Bureaucrat& bureaucrat);
    class GradeTooHighException: public std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException: public std::exception
    {
        public:
            const char* what() const throw();
    };
    class NotSignedException: public std::exception
    {
        public:
            const char* what() const throw();
    };
};
std::ostream& operator<<(std::ostream& os, const AForm& AForm);


#endif