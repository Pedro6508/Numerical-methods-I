#ifndef SAIDA_H
#define SAIDA_H

#include "sonic_airplane.h"
#include <vector>

namespace Result {
    class Output {
    private:
        std::vector<std::vector<double>> resultData;
        std::vector<std::vector<double>> comparativeData;
        // Comparativo: [[j1, k1, d1, a, j2, k2, d2, a, j3, dk3, d3, a]]
        // RESULTADO: [[d1, e1, d2, e2, d3, e3], []]
        // Você pode adicionar "quadro resposta" e "quadro comparativo" como atributos

    public:
        void inputFunction(double a, double e1);

        void resultTable();

        void comparativeTable();
    };
}

#endif // SAIDA_H
