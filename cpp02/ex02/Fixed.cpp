#include "Fixed.hpp"


Fixed::Fixed():fixed_point(0){}
Fixed::Fixed(const int value)
{
    fixed_point = value << fractional_bits;
}
Fixed::Fixed(const float value){
    fixed_point = roundf(value * (1 << fractional_bits));
}
Fixed::Fixed (const Fixed &other){
    *this = other;
}
Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
       this->fixed_point = other.fixed_point;
    return (*this);
}
Fixed::~Fixed(){}
int Fixed::getRawBits()const{
    return fixed_point;
}

void Fixed::setRawBits(int const raw){
    fixed_point = raw;
}
float Fixed::toFloat( void ) const{
    return (float(fixed_point)/(1 << fractional_bits));
}

int Fixed::toInt( void ) const{
    return fixed_point >> fractional_bits;
}
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return out;
}

Fixed Fixed::operator+(const Fixed &other){
    return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other)
{
    return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other)
{
    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other)
{
    if (other.toFloat() != 0)
        return Fixed(this->toFloat() / other.toFloat());
    return Fixed(0);
}

bool Fixed::operator==(const Fixed &other)const
{
    return fixed_point == other.fixed_point;
}
bool Fixed::operator!=(const Fixed &other)const
{
    return fixed_point != other.fixed_point;
}
bool Fixed::operator>(const Fixed &other)const
{
    return fixed_point > other.fixed_point;
}
bool Fixed::operator>=(const Fixed &other)const
{
    return fixed_point >= other.fixed_point;
}
bool Fixed::operator<(const Fixed &other)const
{
    return fixed_point < other.fixed_point;
}
bool Fixed::operator<=(const Fixed &other)const
{
    return fixed_point <= other.fixed_point;
}

Fixed &Fixed::operator++()
{
    this->fixed_point += 1;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed old_value = *this;
    this->fixed_point += 1;
    return old_value;

}
Fixed &Fixed::operator--()
{
    this->fixed_point -= 1;
    return (*this);
}
Fixed Fixed::operator--(int)
{
    Fixed old_value = *this;
    this->fixed_point -= 1;
    return old_value;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return (a);
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return (a);
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b) 
        return a;
    return  b;
}