#include <iostream>
#include <cmath>

using namespace std;

class Function {
private:
    // Termos da função
    double* t;  //caso haja mais de um termo
    double a;   //caso haja apenas um termo
    
    //Número de Raízes
    int n;
    
    // Raízes da função
    double* raizes; //caso haja mais de uma raíz
    double raiz;    //caso haja apenas uma raíz

    // Intervalo de análise da função
    double x1, x2;
    
    // Precisão da raíz
    double e1;

protected:
    // Métodos de acesso aos membros privados
    double* getTermos() { return t; }
    double getA() { return a; }
    int getN() { return n; }
    double* getRaizes() { return raizes; }
    double getRaiz() { return raiz; }
    double getX1() { return x1; }
    double getX2() { return x2; }
    double getE1() { return e1; }

public:
    Function(double a, double x1, double x2, int n, double e1)
        : a(a), x1(x1), x2(x2), n(n), e1(e1), t(nullptr), raizes(nullptr) {}
        
    Function(double* t, double x1, double x2, int n, double e1)
        : t(t), x1(x1), x2(x2), n(n), e1(e1), raiz(0.0) {
            raizes = new double[n];
        }

    // função
    virtual double f(double x) = 0;
    
    // Derivada da função
    virtual double ddx(double d) = 0;

    // Métodos Numéricos
    virtual double bissec() = 0;
    virtual double pos_falsa() = 0;
    virtual double newt_raph() = 0;
};