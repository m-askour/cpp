#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Form
{
    private:
        const std::string name;
        bool indicating;
        const int grade_sign;
        const int grade_execute; 
    public:
        Form(/* args */);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();
        std::string getName();
        int getGrade_sign();
        int getGrade_execute();
        Bureaucrat beSigned(Bureaucrat buro);// this function take a Burokrat as a parametre 
        class GradeTooLowException;


};
std::ostream &operator<<(std::ostream &out, const Form & F);
#endif