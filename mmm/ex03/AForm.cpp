#include "Form.hpp"
Form::Form(/* args */)
{
}
Form::Form(const Form &other)
{
    
}
Form &Form::operator=(const Form &other)
{

}
Form::~Form()
{
}
stream & operator<<(std::ostream &out, const Bureaucrat & b)
{
    out << F.getGrade();
    return out;
}