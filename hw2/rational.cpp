#include "rational.hpp"

Rational::Rational()                   : num(   0), den(   1) {}
Rational::Rational(int _num)           : num(_num), den(   1) {}
Rational::Rational(int _num, int _den) : num(_num), den(_den) {
    assert(den != 0);
    make_den_pos();
    simplify();
}

/**
This member function makes sure that
the denominator of a rational number is positive,
a convenient choice.
*/
void Rational::make_den_pos() {
    if (den < 0) {
        num *= -1;
        den *= -1;
    }
}

/**
This member function simplifies a rational number.
It does so by computing the highest common factor
of the numerator and denominator and dividing
the numerator and denominator by it.

To compute the highest common factor,
the Euclidean algorithm is used.
Do not worry if you don't know the Euclidean algorithm.
*/
void Rational::simplify() {
    int a = abs(num);
    int b = abs(den);

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    num /= a;
    den /= a;
}

std::istream& operator>>(std::istream& in, Rational& r) {
    int num;
    int den;

    char forwardslash;

    in >> num >> forwardslash >> den;

    if (forwardslash != '/') {
        in.setstate(std::ios_base::failbit);
    }
    if (in) {
        r = Rational(num, den);
    }

    return in;
}
