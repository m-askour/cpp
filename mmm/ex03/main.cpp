#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Buro("moha", 15);
        std::cout << Buro.getName() << std::endl;
        std::cout << Buro.getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "exception catch : " << e.what() << std::endl;
    }
    return 0;
}