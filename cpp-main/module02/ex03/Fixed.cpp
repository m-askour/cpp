// ...existing code...
#include "Fixed.hpp"
const int Fixed::fractional_bits;

Fixed::Fixed() : fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(int value)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_point = value << fractional_bits;
}
Fixed   Fixed::operator+(const Fixed &other) const
{
    return (Fixed)(toFloat() + other.toFloat());
}
Fixed   Fixed::operator-(const Fixed &other) const
{
    return (Fixed)(toFloat() - other.toFloat());
}
Fixed   Fixed::operator*(const Fixed &other) const
{
    return (Fixed)(toFloat() * other.toFloat());
}
Fixed   Fixed::operator/(const Fixed &other) const
{
    return (Fixed)(toFloat() / other.toFloat());
}
Fixed  & Fixed::operator++()
{
    this->fixed_point += 1;
    return (*this);
}
Fixed   Fixed::operator++(int)
{
    Fixed old_val = *this;

    this->fixed_point +=1;
    return old_val;
}
Fixed  & Fixed::operator--()
{
    this->fixed_point -= 1;
    return (*this);
}
Fixed   Fixed::operator--(int)
{   
    Fixed old_val=*this;
    
    this->fixed_point -=-1;
    return old_val;
}
bool    Fixed::operator==(const Fixed &other) const
{
    if (getRawBits() == other.getRawBits())
        return true;
    return false;
}
bool Fixed::operator!=(const Fixed &other) const
{
    if (getRawBits() != other.getRawBits())
        return true;
    return false;
}
bool Fixed::operator<(const Fixed &other) const
{
    if (getRawBits() < other.getRawBits())
        return true;
    return false;
}
bool Fixed::operator<=(const Fixed &other) const
{
 if (getRawBits() <= other.getRawBits())
        return true;
    return false;
}
bool Fixed::operator>(const Fixed &other) const
{
    if (getRawBits() > other.getRawBits())
        return true;
    return false;
}
bool Fixed::operator>=(const Fixed &other) const
{
    if (getRawBits() >= other.getRawBits())
        return true;
    return false;
}

Fixed::Fixed(float value)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_point = int(value * 256.0f);
}
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixed_point = other.fixed_point;
    return *this;
}

Fixed::Fixed(const Fixed &other) : fixed_point(other.fixed_point)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point = raw;
}
float Fixed::toFloat( void ) const
{
    return float(fixed_point) / 256.0f;
}

int Fixed::toInt( void ) const
{
    return fixed_point >> fractional_bits;
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}
const Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
    if(a < b)
        return a;
    return b;
}
Fixed & Fixed::max(Fixed &a, Fixed &b)
{
    if(a > b)
        return a;
    return b;
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}
