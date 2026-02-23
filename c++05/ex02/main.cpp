#include "Bureaucrat.hpp"
#include "AFrom.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
    try
    {
        Bureaucrat b1("John", 50);
        Bureaucrat b2("Jane", 10);
        ShrubberyCreationForm f1("Home");
        RobotomyRequestForm f2("Target");
        PresidentialPardonForm f3("Victim");
        f1.beSigned(b1);
        f2.beSigned(b2);
        f3.beSigned(b2);
        b1.executeForm(f1);
        b2.executeForm(f2);
        b2.executeForm(f3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
     return 0;
    
}