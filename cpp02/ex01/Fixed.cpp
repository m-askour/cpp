#include "Fixed.hpp"


Fixed::Fixed():fixed_point(0)
{
    std::cout << "Default constructor called \n";
}
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called \n";
    fixed_point = value << fractional_bits;
}
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called \n";
    fixed_point = roundf(value * (1 << fractional_bits));
}
Fixed::Fixed (const Fixed &other)
{
    std::cout << "Copy constructor called \n";
    *this = other;
}
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called \n";
    if (this != &other)
       this->fixed_point = other.fixed_point;
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
float Fixed::toFloat( void ) const
{
    return (float(fixed_point)/(1 << fractional_bits));
}

int Fixed::toInt( void ) const
{
    return fixed_point >> fractional_bits;
}
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return out;
}