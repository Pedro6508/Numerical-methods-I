/*
#pragma once 

class Function {
    public:
        Function();
        Function(float a, float error); 
        float derivative(float x);
        float calc(float x);
        float bissecao();
        float posicao_falsa();
        float newton();
    private: 
        float a;
        float error;
};
*/

#ifndef FUNCTION_H
#define FUNCTION_H

class Function {
private:
    double* t;
    double a;
    int n;
    double* raizes;
    double raiz;
    double x1, x2;
    double e1;

protected:
    double* getTermos();
    double getA();
    int getN();
    double* getRaizes();
    double getRaiz();
    double getX1();
    double getX2();
    double getE1();

public:
    Function(double a, double x1, double x2, int n, double e1);
    Function(double* t, double x1, double x2, int n, double e1);
    virtual double f(double x) = 0;
    virtual double ddx(double d) = 0;
    virtual double bissec() = 0;
    virtual double pos_falsa() = 0;
    virtual double newt_raph() = 0;
};

#endif // FUNCTION_H
