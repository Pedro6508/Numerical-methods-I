#ifndef AVIAO_SONICO_H
#define AVIAO_SONICO_H

#include "function.h" // Inclua o arquivo de cabeçalho da classe Function

class AviaoSonico : public Function {
public:
    AviaoSonico(double a, double x1, double x2, double e1);

    double f(double d);
    double ddx(double d);
    double bissec();
    double pos_falsa();
    double newt_raph();
};

#endif // AVIAO_SONICO_H
