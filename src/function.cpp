#include "function.h"
#include "cmath"

Function::Function(){}

Function::Function(float a, float error){
    this -> a = a;
    this -> error = error;
}

float Function::calc(float d){
    return (a * d - (d * log(d)));
}

float Function::derivative(float d){
    return (a - log(d) - 1);        
}

// Implementar os métodos aqui ... 





