#include <iostream>
#include <cmath>
#include "function.h"
#include "sonic_airplane.h"

using namespace impl;


SonicAirplane::SonicAirplane(double a, double x1, double x2, double e1)
    : Function(a, x1, x2, 1, e1), iter_bis(0), iter_newt(0), iter_pos(0), err_bis(0), err_newt(0), err_pos(0) {
}

SonicAirplane::SonicAirplane(double a, double e1)
    : Function(a, floor(exp(a)), ceil(exp(a)), 1, e1), iter_bis(0), iter_newt(0), iter_pos(0), err_bis(0), err_newt(0), err_pos(0) {
}






double SonicAirplane::f(double d){
    return (getA() * d - d * (log(d)));
}

double SonicAirplane::ddx(double d){
    return (getA() - (log(d) + 1));
}

// The variable i will be used to limit the number of iterations

double SonicAirplane::bisection(){
    double xk, f1, f2;
    int i = 0;
    double x1 = getX1();
    double x2 = getX2();
    double m = f(x1);
    while((fabs(x1 - x2) > getEps()) && (i < 100)){
        this -> err_bis = (fabs(x1 - x2));

        xk = (x1 + x2) / 2;
        // Choose between x1 and x2

        if (m * f(xk) < 0) {
            x2 = xk;
        } else {
            x1 = xk;
        }

        i++;
        this -> iter_bis = i;

    }

            this -> err_bis = (fabs(x1 - x2));

    return xk;
}


double SonicAirplane::falsePosition(){
    double xk, f1, f2;
    int i = 0;
    double x1 = getX1();
    double x2 = getX2();

    while((fabs(x1 - x2) > getEps()) && (i < 100)){
        this -> err_pos = (fabs(x1 - x2));
        if ((f(x2) - f(x1)) != 0){
            xk = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        }  else {
            return xk;
        }

        f1 = f(x1);
        f2 = f(x2);

        // Choose between x1 and x2
        if (f1 == 0){
            return x1;
        } else if (f2 == 0) {
            return x2;
        } else if (f1 * f2 < 0) {
            x2 = xk;
        } else {
            x1 = xk;
        }
        i++;
        this -> iter_pos = i;

    }
    this -> err_pos = (fabs(x1 - x2));

    return xk;
}

double SonicAirplane::newtonRaphson(){
    double xk0, xk1, f1, f2;
    int i = 0;
    xk0 = getX1();
    try{
        xk1 = xk0 - (f(xk0)/ddx(xk0));
    } catch (...){
        this -> err_newt = (fabs(xk0 - xk1));

        return xk0;
    }

    while((fabs(xk0 - xk1) > getEps()) && (i < 100)){
        try{
            xk0 = xk1;
            xk1 = xk0 - (f(xk0)/ddx(xk0));
            i++;
            this -> iter_newt = i;

        } catch (...){
            this -> err_newt = (fabs(xk0 - xk1));

            return xk0;
        }
    }
    this -> err_newt = (fabs(xk0 - xk1));

    return xk1;
}

int SonicAirplane::getIBis(){
    return iter_bis;
}

int SonicAirplane::getINewt(){
    return iter_newt;
}

int SonicAirplane::getIPos(){
    return iter_pos;
}

double SonicAirplane::getEBis() {
    return err_bis;
}

double SonicAirplane::getEPos() {
    return err_pos;
}

double SonicAirplane::getENewt() {
    return err_newt;
}