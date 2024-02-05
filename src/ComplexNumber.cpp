//
// Created by axelmans on 5/02/24.
//

#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(const double &a, const double &b) : mReal(a), mImaginary(b)  {}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &other) const {
    return {mReal + other.mReal, mImaginary + other.mImaginary};
}

ComplexNumber ComplexNumber::operator-() const {
    return {-mReal, -mImaginary};
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &other) const {
    return *this + -other;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &other) const {
    double a = mReal*other.mReal - mImaginary*other.mImaginary;
    double b = mReal*other.mImaginary + mImaginary*other.mReal;
    return {a, b};
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &other) const {
    // (a + bi)/(c + di) = [(ac + bd) + (bc - ad)i]/(c² + d²)
    // division by 0 + 0i is impossible
    double divisor = pow(other.mReal, 2) + pow(other.mImaginary, 2);
    if(divisor == 0){
        throw logic_error("Division failed: c² + d² is zero!");
    }
    double real = mReal*other.mReal + mImaginary*other.mImaginary;
    double imaginary = mImaginary*other.mReal - mReal*other.mImaginary;
    return {real/divisor, imaginary/divisor};
}

ostream &operator<<(ostream &o, const ComplexNumber& c) {
    // if both components a and b are 0: print 0
    if(c.mReal == 0 && c.mImaginary == 0){
        o << 0 << endl;
        return o;
    }
    // if either component is zero, they should not be printed
    if(c.mReal != 0) {
        o << c.mReal;
    }
    // plus or minus only if real part is nonzero, depends on sign of imaginary part
    if(c.mReal != 0 && c.mImaginary > 0){
        o << " + " << c.mImaginary << 'i' << endl;
    }
    else if(c.mReal != 0 && c.mImaginary < 0){
        o << " - " << -c.mImaginary << 'i' << endl;
    }
    // if only imaginary part: print imaginary part with sign before it
    else if(c.mImaginary != 0){
        o << c.mImaginary << 'i' << endl;
    }
    return o;
}

pair<ComplexNumber, ComplexNumber> ComplexNumber::Roots() const {
    // x = ± √{[√(a² + b²) + a]/2} and y = ± √{[√(a² + b²) - a]/2}
    double x = sqrt((sqrt(pow(mReal, 2) + pow(mImaginary, 2)) + mReal)/2);
    double y = sqrt((sqrt(pow(mReal, 2) + pow(mImaginary, 2)) - mReal)/2);
    // x and y have the same sign if b >= 0
    if(mImaginary >= 0){
        return {{x, y}, {-x, -y}};
    }
    // otherwise they have a different sign
    else{
        return {{-x, y}, {x, -y}};
    }
}


