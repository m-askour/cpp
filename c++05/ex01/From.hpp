#ifndef FROM_HPP
#define FROM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class From
{
private:
    const std::string name;
    const int grade_sign;
    const int grade_exec;
    bool sign;
public:
    From(std::string name, int grade_sign, int grade_exec);
    From(const From &other);
    From &operator=(const From &other);
    ~From();
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
std::ostream& operator<<(std::ostream& os, const From& from);


#endif