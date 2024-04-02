#include "Complex.h"

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double complex) : _real(real), _complex(complex) {}

std::ostream& operator<<(std::ostream& os, const Complex& el) {
    return os << el._real << "+" << el._complex << "i" << std::endl;
}

std::istream& operator>>(std::istream& in, Complex& el) {
    return in >> el._real >> el._complex;
}

Complex& Complex::operator+=(const Complex& oth) {
    _real += oth._real;
    _complex += oth._complex;

    return *this;
}

Complex& Complex::operator+=(double real) {
    _real += real;

    return *this;
}


Complex& Complex::operator-=(const Complex& oth) {
    _real -= oth._real;
    _complex -= oth._complex;

    return *this;
}

Complex& Complex::operator*=(const Complex& oth) {
    double tempReal = (_real * oth._real) - (_complex * oth._complex);
    _complex = (_real * oth._complex) + (_complex * oth._real);
    _real = tempReal;

    return *this;
}

Complex& Complex::operator*=(double real) {
    _real *= real;
    _complex *= real;

    return *this;
}


Complex& Complex::operator/=(const Complex& oth) {

    Complex conjuction = getConjuction(oth);
    *this *= conjuction;
    Complex denominator(oth);
    denominator *= conjuction;

    if(denominator._real != 0) {
        _real /= denominator._real;
        _complex /= denominator._real;
    }

    return *this;
}

Complex Complex::getConjuction(const Complex& oth) {
    return Complex(oth._real, -oth._complex);
}

Complex operator+(const Complex& l, const Complex& r) {
    Complex res(l);
    res += r;

    return res;
}

Complex operator-(const Complex& l, const Complex& r) {
    Complex res(l);
    res -= r;

    return res;
}

Complex operator*(const Complex& l, const Complex& r) {
    Complex res(l);
    res *= r;

    return res;
}

Complex operator/(const Complex& l, const Complex& r) {
    Complex res(l);
    res /= r;

    return res;
}