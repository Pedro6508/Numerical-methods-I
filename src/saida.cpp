#include "saida.h"

Saida::Saida() {
    // Implementação do construtor se necessário 
}

void Saida::inserirFuncao(const Function& funcao) {
    functionVector.push_back(funcao);
}

// Sobre o tipo: Pode ser void (insere a um atributo quadroResposta em "Saida" ou pode retornar a própria matriz)
void Saida::quadroResposta() { 
    // Implementação do método de quadro de resposta
}

void Saida::quadroComparativo() {
    // Implementação do método de quadro comparativo
}
