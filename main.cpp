#include "src/QuadraticEquation.h"

int main(){
    ComplexNumber a{2, 0};
    ComplexNumber b{-3, 0};
    ComplexNumber c{6, 0};
    QuadraticEquation e{{c, b, a}};
    for(auto &solution: e.Solve()){
        cout << solution << endl;
    }
}