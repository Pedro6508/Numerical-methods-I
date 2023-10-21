#ifndef SAIDA_H
#define SAIDA_H

#include "function.h"
#include <vector>

namespace Result {
    class Output {
    private:
        std::vector<utils::Function> functionVector;
        // Podemos adiconar "quadro resposta e quadro comparativo como atributos"

    public:
        void inputFunction(const utils::Function& function);

        // Sobre o tipo: Pode ser void (insere a um atributo resultTable em "Output" ou pode retornar a própria matriz)

        void resultTable();

        void comparativeTable();
    };
}

#endif // SAIDA_H
