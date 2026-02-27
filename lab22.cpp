#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber {
public:
    double real;
    double imag;

    ComplexNumber(double r = 0, double i = 0);

    ComplexNumber operator+(const ComplexNumber &c) const;
    ComplexNumber operator-(const ComplexNumber &c) const;
    ComplexNumber operator*(const ComplexNumber &c) const;
    ComplexNumber operator/(const ComplexNumber &c) const;
    bool operator==(const ComplexNumber &c) const;

    ComplexNumber operator+(double s) const;
    ComplexNumber operator-(double s) const;
    ComplexNumber operator*(double s) const;
    ComplexNumber operator/(double s) const;
    bool operator==(double s) const;

    double abs() const;
    double angle() const;
};

ComplexNumber::ComplexNumber(double r, double i) {
    real = r;
    imag = i;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c) const {
    return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c) const {
    return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) const {
    return ComplexNumber(real * c.real - imag * c.imag,
                         real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) const {
    double den = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((real * c.real + imag * c.imag) / den,
                         (imag * c.real - real * c.imag) / den);
}

// ==
bool ComplexNumber::operator==(const ComplexNumber &c) const {
    return real == c.real && imag == c.imag;
}

ComplexNumber ComplexNumber::operator+(double s) const {
    return ComplexNumber(real + s, imag);
}

ComplexNumber ComplexNumber::operator-(double s) const {
    return ComplexNumber(real - s, imag);
}

ComplexNumber ComplexNumber::operator*(double s) const {
    return ComplexNumber(real * s, imag * s);
}

ComplexNumber ComplexNumber::operator/(double s) const {
    return ComplexNumber(real / s, imag / s);
}

bool ComplexNumber::operator==(double s) const {
    return (real == s && imag == 0);
}

double ComplexNumber::abs() const {
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle() const {
    double PI = acos(-1.0);
    return atan2(imag, real) * 180.0 / PI;
}

ComplexNumber operator+(double s, const ComplexNumber &c) {
    return ComplexNumber(s + c.real, c.imag);
}

ComplexNumber operator-(double s, const ComplexNumber &c) {
    return ComplexNumber(s - c.real, -c.imag);
}

ComplexNumber operator*(double s, const ComplexNumber &c) {
    return ComplexNumber(s * c.real, s * c.imag);
}

ComplexNumber operator/(double s, const ComplexNumber &c) {
    double den = c.real * c.real + c.imag * c.imag;
    return ComplexNumber((s * c.real) / den, (-s * c.imag) / den);
}

bool operator==(double s, const ComplexNumber &c) {
    return (s == c.real && c.imag == 0);
}

ostream& operator<<(ostream& os, const ComplexNumber& c) {
    if (c.real == 0 && c.imag == 0) {
        os << "0";
    }
    else if (c.real == 0) {
        os << c.imag << "i";
    }
    else if (c.imag == 0) {
        os << c.real;
    }
    else {
        os << c.real;
        if (c.imag > 0) os << "+";
        os << c.imag << "i";
    }
    return os;
}