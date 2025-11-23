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
    
    Fixed operator+(const Fixed &other) const; // Addition operator
    Fixed operator-(const Fixed &other) const; // Subtraction operator
    Fixed operator*(const Fixed &other) const; // Multiplication operator
    Fixed operator/(const Fixed &other) const; // Division operator    
    bool operator==(const Fixed &other) const; // Equality operator
    bool operator!=(const Fixed &other) const; // Inequality operator
    bool operator<(const Fixed &other) const;  // Less than operator
    bool operator<=(const Fixed &other) const; // Less than or equal to operator
    bool operator>(const Fixed &other) const;  // Greater than operator
    bool operator>=(const Fixed &other) const; // Greater than or equal to operator
    Fixed &operator++();               // Prefix increment operator
    Fixed operator++(int);            // Postfix increment operator
    Fixed &operator--();               // Prefix decrement operator
    Fixed operator--(int);            // Postfix decrement operator
    ~Fixed();                               // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;//this function converts the fixed-point value to a floating-point value
    int toInt( void ) const;//this function converts the fixed-point value to a int value
    static Fixed &min(Fixed &a, Fixed &b); // Returns the minimum of two Fixed objects
    static const Fixed &min(const Fixed &a, const Fixed &b); // Returns the
    static Fixed &max(Fixed &a, Fixed &b); // Returns the maximum of two Fixed objects
    static const Fixed &max(const Fixed &a, const Fixed &b); // Returns the maximum of two Fixed objects
};

#endif