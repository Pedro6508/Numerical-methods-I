#ifndef SAIDA_H
#define SAIDA_H

#include <vector>
#include "function.h"

class Saida {
private:
    std::vector<Function> functionVector;
    // Podemos adiconar "quadro resposta e quadro comparativo como atributos"

public:
    Saida();

    void inserirFuncao(const Function& funcao);

// Sobre o tipo: Pode ser void (insere a um atributo quadroResposta em "Saida" ou pode retornar a própria matriz)

    void quadroResposta();

    void quadroComparativo();
};

#endif // SAIDA_H
