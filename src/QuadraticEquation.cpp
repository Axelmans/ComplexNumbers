//
// Created by axelmans on 6/02/24.
//

#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation(const array<ComplexNumber, 3> &coefficients) : mCoefficients(coefficients) {}

ComplexNumber QuadraticEquation::operator()(const ComplexNumber &c) {
    ComplexNumber result{0, 0};
    for(int i = 0; i < mCoefficients.size(); i++){
        // Calculate power of input number first
        ComplexNumber power = c;
        for(int j = 0; j < i; j++){
            power *= c;
        }
        // Multiply power with coefficient, then add to result
        result += power * mCoefficients[i];
    }
    return result;
}

vector<ComplexNumber> QuadraticEquation::Solve() {
    ComplexNumber d = Discriminant();
    // If discriminant is zero, there is one solution
    if(d == 0){
        return {-mCoefficients[1] / (mCoefficients[2] * 2)};
    }
    // Else, there are 2 distinct solutions
    pair<ComplexNumber, ComplexNumber> d_roots = d.Roots();
    return {(-mCoefficients[1] + d_roots.first) / (mCoefficients[2] * 2),
            (-mCoefficients[1] + d_roots.second) / (mCoefficients[2] * 2)};
}

ComplexNumber QuadraticEquation::Discriminant() {
    return mCoefficients[1]*mCoefficients[1] - mCoefficients[0]*mCoefficients[2]*4;
}