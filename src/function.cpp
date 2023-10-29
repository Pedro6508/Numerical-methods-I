#include <iostream>
#include <format>
#include "function.h"

using namespace std;
using namespace utils;

// Private member access methods
double* Function::getTerms() { return t; }
double Function::getA() const { return a; }
int Function::getN() const { return n; }
double* Function::getRoots() { return roots; }
double Function::getRoot() const { return root; }
double Function::getX1() const { return x1; }
double Function::getX2() const { return x2; }
double Function::getEps() const { return eps; }

// Constructors
Function::Function(double a, double x1, double x2, int n, double eps)
    : a(a), x1(x1), x2(x2), n(n), eps(eps), t(nullptr), roots(nullptr) {
}

Function::Function(double* t, double x1, double x2, int n, double eps)
    : t(t), x1(x1), x2(x2), n(n), eps(eps), root(0.0) {
        roots = new double[n];
    }