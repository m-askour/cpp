#include "ShrubberyCreationForm.hpp"
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AFrom("ShrubberyCreationForm", 145, 137), target(target)
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AFrom(other)
{
    this->target = other.target;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        this->target = other.target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
        if (!this->get_sign())
        {
            std::cout << "Form " << this->get_name() << " is not signed yet!" << std::endl;
            return;
        }
        if (executor.getGrade() > this->get_grade_exec())
        {
            std::cout << "Bureaucrat " << executor.getName() << " can't execute " << this->get_name() << " because his grade is too low!" << std::endl;
            return;
        }
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
        }
}