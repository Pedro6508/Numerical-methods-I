#ifndef FUNCTION_H
#define FUNCTION_H

#include "output.h"

namespace utils {
    class Function {
    private:
        // Function Terms
        double *t;
        double a{};

        // Number of Roots
        int n;

        // Roots
        double *roots;
        double root{};

        // Function analysis range
        double x1, x2;

        // Tolerable Error
        double eps;
    protected:
        double *getTerms();

        double getA() const;

        int getN() const;

        double *getRoots();

        double getRoot() const;

        double getX1() const;

        double getX2() const;

        double getEps() const;

    public:
        Function(double a, double x1, double x2, int n, double eps);

        Function(double *t, double x1, double x2, int n, double eps);

        // Function f
        virtual double f(double x) = 0;

        // Derivative of function f
        virtual double ddx(double d) = 0;

        // Numerical Methods
        virtual double bisection() = 0;
        virtual double falsePosition() = 0;
        virtual double newtonRaphson() = 0;
    };
}

#endif // FUNCTION_H
