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
    double a = this->mReal*other.mReal - this->mImaginary*other.mImaginary;
    double b = this->mReal*other.mImaginary + this->mImaginary*other.mReal;
    return {a, b};
}

ostream &operator<<(ostream &o, const ComplexNumber& c) {
    if(c.mReal == 0 && c.mImaginary == 0){
        o << 0 << endl;
        return o;
    }
    if(c.mReal != 0) {
        o << c.mReal;
    }
    if(c.mReal != 0 && c.mImaginary > 0){
        o << " + " << c.mImaginary << 'i' << endl;
    }
    else if(c.mReal != 0 && c.mImaginary < 0){
        o << " - " << -c.mImaginary << 'i' << endl;
    }
    else if(c.mImaginary != 0){
        o << c.mImaginary << 'i' << endl;
    }
}


