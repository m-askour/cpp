#ifndef FROM_HPP
#define FROM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class AFrom
{
private:
    const std::string name;
    const int grade_sign;
    const int grade_exec;
    bool sign;
public:
    AFrom(std::string name, int grade_sign, int grade_exec);
    AFrom(const AFrom &other);
    AFrom &operator=(const AFrom &other);
    virtual~AFrom();
    bool get_sign() const;
    std::string get_name() const;
    int get_grade_sign() const;
    int get_grade_exec() const;
    void beSigned(const class Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;
    class GradeTooHighException;
    class GradeTooLowException;

};
std::ostream& operator<<(std::ostream& os, const AFrom& from);


#endif