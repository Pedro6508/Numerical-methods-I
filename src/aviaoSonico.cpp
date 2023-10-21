#include <iostream>
#include <cmath>
#include "function.h"

class AviaoSonico : public Function {
public:
    AviaoSonico(double a, double x1, double x2, double e1) 
        : Function(a, x1, x2, 1, e1) {
    }

    double f(double d){
        return (getA() * d - d * (log(d)));
    }

    double ddx(double d){
        return (getA() - (log(d) + 1));
    }

    // A variável "i" será utilizada para limitar o Número de iterações
    
    double bissec(){
        double xk, f1, f2;
        int i = 0;
        double x1 = getX1();
        double x2 = getX2();
        
        while((abs(x1 - x2) > getE1()) && (i<100)){
            
            xk = (x1 + x2) / 2;
            f1 = f(x1);
            f2 = f(x2);
    
            // Avalia f(x1) e f(x2)
            if (f1 == 0){
                return f1;
            } else if (f2 == 0) {
                return f2;
            } else if (f1 * f2 < 0) {
                x2 = xk;
            } else {
                x1 = xk;
            }
            
            i++;
        }
        return xk;
    }

    double pos_falsa(){
        double xk, f1, f2;
        int i = 0;
        double x1 = getX1();
        double x2 = getX2();
        
        while((abs(x1 - x2) > getE1()) && (i<100)){
            if ((f(x2) - f(x1)) != 0){
                xk = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
            }  else {
                return xk;
            }
            
            f1 = f(x1);
            f2 = f(x2);
    
            // Avalia f(x1) e f(x2)
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
        }
        return xk;
    }
    
    double newt_raph(){
        double xk0, xk1, f1, f2;
        int i = 0;
        xk0 = getX1();
        try{
            xk1 = xk0 - (f(xk0)/ddx(xk0));
        } catch (...){
            return xk0;
        }

        while((abs(xk0 - xk1) > getE1()) && (i<100)){
            try{
                xk0 = xk1;
                xk1 = xk0 - (f(xk0)/ddx(xk0));
                i++;
            } catch (...){
                return xk0;
            }
        }
        return xk1;
    }
};
