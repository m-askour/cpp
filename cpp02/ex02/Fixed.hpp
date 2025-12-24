#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
private:
    int fixed_point;
    static const int fractional_bits = 8;
public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed (const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();


    Fixed operator+(const Fixed &other);
    Fixed operator-(const Fixed &other);
    Fixed operator*(const Fixed &other);
    Fixed operator/(const Fixed &other);

    bool operator==(const Fixed &other)const;
    bool operator!=(const Fixed &other)const;
    bool operator>(const Fixed &other)const;
    bool operator>=(const Fixed &other)const;
    bool operator<(const Fixed &other)const;
    bool operator<=(const Fixed &other)const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;


    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed const  &min(const Fixed &a, const Fixed &b);

    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed const  &max(const Fixed &a, const Fixed &b);
};
std::ostream &operator<<(std::ostream &out, const Fixed &value);
#endif