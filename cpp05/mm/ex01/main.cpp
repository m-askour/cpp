#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("John", 20);
        Form f1("TaxForm", 30, 50);

        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form f2("InvalidForm", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Form f3("InvalidForm", 151, 50);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat boss("Boss", 10);
        Form permit("Permit", 20, 30);

        std::cout << permit << std::endl;
        permit.beSigned(boss);
        std::cout << permit << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat intern("Intern", 100);
        Form secret("SecretForm", 50, 20);

        std::cout << secret << std::endl;
        secret.beSigned(intern);
        std::cout << secret << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat alice("Alice", 40);
        Form contract("Contract", 50, 50);

        alice.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bob("Bob", 120);
        Form topSecret("TopSecret", 10, 10);

        bob.signForm(topSecret);
        std::cout << topSecret << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}