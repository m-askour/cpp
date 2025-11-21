#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int fixed_point;
    static const int fractional_bits = 8;

public:
    Fixed();                                 // Default constructor
    Fixed(int value);                                // Default constructor
    Fixed(float value);                          // Int constructor
    Fixed(const Fixed &other);              // Copy constructor
    Fixed &operator=(const Fixed &other);   // Copy assignment operator
    
    ~Fixed();                               // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;//this function converts the fixed-point value to a floating-point value
    int toInt( void ) const;
    Fixed operator*(const Fixed &other) const;
    Fixed &operator++(); // Prefix increment
    Fixed operator++(int); // Postfix increment
    max(Fixed &a, Fixed &b);
};

#endif