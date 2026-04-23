#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
        Bureaucrat b1("John", 50);
        Form f1("Form1", 30, 20);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        f1.beSigned(b1);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

     return 0;
}