#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm ("ShrubberyCreationForm", 145, 137), target(target)
{

}
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
std::string ShrubberyCreationForm:: getTarget()
{
    return this->target;
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    //this class is to check the range of sing <= 145 and range de exec <= 137
    //if this rool is success wecreat a target file and weites ascii tree inside this file

    if (!this->get_sign())
        throw GradeTooLowException();
    if (executor.getGrade() > this->get_grade_exec())
        throw GradeTooLowException();
    std::ofstream file(this->target + "_shrubbery");
    if (file.is_open())
    {
        file << "       _-_" << std::endl;
        file << "    /~~   ~~\\" << std::endl;
        file << " /~~         ~~\\" << std::endl;
        file << "{               }" << std::endl;
        file << " \\  _-     -_  /" << std::endl;
        file << "   ~  \\\\ //  ~" << std::endl;
        file << "_- -   | | _- _" << std::endl;
        file << "  _ -  | |   -_" << std::endl;
        file << "      // \\\\" << std::endl;
        file.close();
    }
    else
    {
        std::cout << "Error: Could not create the file." << std::endl;
        return ;
    }
}
