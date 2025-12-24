#include "Fixed.hpp"


Fixed::Fixed():fixed_point(0)
{
    std::cout << "Default constructor called \n";
}
Fixed::Fixed (const Fixed &other)
{
    std::cout << "Copy constructor called \n";
    fixed_point = other.getRawBits();
}
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called \n";
    if (this != &other)
       this->fixed_point = other.getRawBits();
    return (*this);
}
Fixed::~Fixed()
{
    std::cout << "Destructor called \n";
}
int Fixed::getRawBits()const
{
    std::cout << "getRawBits member function called \n";
    return fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called \n";
    fixed_point = raw;
}