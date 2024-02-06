//
// Created by axelmans on 6/02/24.
//

#ifndef COMPLEXNUMBERS_QUADRATICEQUATION_H
#define COMPLEXNUMBERS_QUADRATICEQUATION_H

#include <algorithm>
#include <array>
#include <vector>
#include "ComplexNumber.h"

using namespace std;

class QuadraticEquation {

public:

    explicit QuadraticEquation(const array<ComplexNumber, 3>&);

    // () operator gives function value for input value
    ComplexNumber operator()(const ComplexNumber&);

    // Returns the input values for which the equation results in 0
    vector<ComplexNumber> Solve();

private:

    ComplexNumber Discriminant();

    // One coefficient per power, index = power
    array<ComplexNumber, 3> mCoefficients;

};


#endif //COMPLEXNUMBERS_QUADRATICEQUATION_H
