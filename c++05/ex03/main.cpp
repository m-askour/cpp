#include "Bureaucrat.hpp"
#include "AFrom.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main()
{
    try
    {
        Bureaucrat b1("John", 50);
        Intern intern;
        AFrom* f1 = intern.makeForm("ShrubberyCreationForm", "Home");
        AFrom* f2 = intern.makeForm("RobotomyRequestForm", "Target");
        AFrom* f3 = intern.makeForm("PresidentialPardonForm", "Victim");
        AFrom* f4 = intern.makeForm("UnknownForm", "Unknown");
        if (f1)
        {            f1->beSigned(b1);
            b1.executeForm(*f1);    
        }
        if (f2)
        {
            f2->beSigned(b1);
            b1.executeForm(*f2);    
        }
        if (f3)
        {   
            f3->beSigned(b1);
            b1.executeForm(*f3);    
        }
        if (f4)
        {
            f4->beSigned(b1);
            b1.executeForm(*f4);    
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

     return 0;
}