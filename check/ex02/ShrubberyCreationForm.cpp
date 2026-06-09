#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm ("ShrubberyCreationForm", 145, 137), target(target)
{

}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):AForm(other), target(other.target)
{
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;

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
    if (!this->get_sign())
        throw NotSignedException();
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