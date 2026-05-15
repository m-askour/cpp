#ifndef Form_HPP
#define Form_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Form
{
private:
    const std::string name;
    const int grade_sign;
    const int grade_exec;
    bool sign;
public:
    Form(std::string name, int grade_sign, int grade_exec);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();
    bool get_sign() const;
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
};
std::ostream& operator<<(std::ostream& os, const Form& Form);


#endif