#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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

        std::cout << "\n===== Creating forms =====" << std::endl;
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n===== Signing tests =====" << std::endl;

        low.signAForm(shrub);
        mid.signAForm(robot);
        high.signAForm(pardon);

        std::cout << "\n===== Execution tests =====" << std::endl;

        low.executeForm(shrub);
        mid.executeForm(robot);
        high.executeForm(pardon);

        std::cout << "\n===== Direct execution =====" << std::endl;

        shrub.execute(high);
        robot.execute(high);
        pardon.execute(high);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}