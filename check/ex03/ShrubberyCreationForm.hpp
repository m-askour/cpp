#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm {
    private:
    std::string target;

    public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other); 
    ~ShrubberyCreationForm();
    std::string getTarget();
    void execute(Bureaucrat const & executor) const;
};

#endif