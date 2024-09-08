#ifndef COMPLEX_H // #pragma once does the same thing
#define COMPLEX_H
#include <iostream>
#include <fstream>


class Complex {

    double _real;
    double _complex;

    Complex getConjuction(const Complex& oth);
public:
    Complex();
    Complex(double, double);

    Complex& operator+=(const Complex&);
    Complex& operator+=(double); // for scalar
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator*=(double); // for scalar
    Complex& operator/=(const Complex&);

    friend std::ostream& operator<<(std::ostream& os, const Complex&);
    friend std::istream& operator>>(std::istream& is, Complex&);
};

Complex operator+(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);

#endif
