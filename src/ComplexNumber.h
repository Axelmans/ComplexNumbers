//
// Created by axelmans on 5/02/24.
//

#ifndef COMPLEXNUMBERS_COMPLEXNUMBER_H
#define COMPLEXNUMBERS_COMPLEXNUMBER_H

#include <cmath>
#include <iostream>

using namespace std;

class ComplexNumber {

public:

    ComplexNumber(const double&, const double&);

    // Binary operators
    ComplexNumber operator -() const;
    ComplexNumber operator +(const ComplexNumber&) const;
    ComplexNumber operator -(const ComplexNumber&) const;
    ComplexNumber operator *(const ComplexNumber&) const;
    ComplexNumber operator /(const ComplexNumber&) const;

    // Print operator
    friend ostream& operator <<(ostream&, const ComplexNumber&);

    // Other functions
    pair<ComplexNumber, ComplexNumber> Roots() const;

private:

    double mReal;
    double mImaginary;

};


#endif //COMPLEXNUMBERS_COMPLEXNUMBER_H
