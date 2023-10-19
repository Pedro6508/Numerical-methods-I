#include <iostream>
#include "aviaoSonico.h"

using namespace std;

int main() {
    double a = 1.0;
    double x1 = 2.0;
    double x2 = 3.0;
    double e1 = 10e-5;
    AviaoSonico aviao(a, x1, x2, e1);

    // Teste o método bissec
    double resultadoBissec = aviao.bissec();
    cout << "Resultado da bissecção: " << resultadoBissec << endl;

    // Teste o método pos_falsa
    double resultadoPosFalsa = aviao.pos_falsa();
    cout << "Resultado da posição falsa: " << resultadoPosFalsa << endl;

    // Teste o método newt_raph
    double resultadoNewtRaph = aviao.newt_raph();
    cout << "Resultado do método de Newton-Raphson: " << resultadoNewtRaph << endl;

    return 0;
}
