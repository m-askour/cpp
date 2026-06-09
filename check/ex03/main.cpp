#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        std::cout << "===== Creating bureaucrats =====" << std::endl;
        Bureaucrat low("low", 140);
        Bureaucrat mid("mid", 50);
        Bureaucrat high("high", 1);

        std::cout << low << std::endl;
        std::cout << mid << std::endl;
        std::cout << high << std::endl;

        std::cout << "\n===== Intern creates forms =====" << std::endl;
        Intern someRandomIntern;

        AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        AForm* f4 = someRandomIntern.makeForm("invalid form name", "test"); // should fail

        std::cout << "\n===== Forms info =====" << std::endl;
        if (f1) std::cout << *f1 << std::endl;
        if (f2) std::cout << *f2 << std::endl;
        if (f3) std::cout << *f3 << std::endl;

        std::cout << "\n===== Signing tests =====" << std::endl;

        if (f1) low.signAForm(*f1);
        if (f2) mid.signAForm(*f2);
        if (f3) high.signAForm(*f3);

        std::cout << "\n===== Execution tests =====" << std::endl;

        if (f1) low.executeForm(*f1);   // likely fail
        if (f2) mid.executeForm(*f2);   // random success/fail
        if (f3) high.executeForm(*f3);  // should succeed

        std::cout << "\n===== Direct execution =====" << std::endl;

        if (f1) f1->execute(high);
        if (f2) f2->execute(high);
        if (f3) f3->execute(high);

        std::cout << "\n===== Cleanup =====" << std::endl;
        delete f1;
        delete f2;
        delete f3;
        delete f4;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}