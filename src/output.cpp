#include "saida.h"

using namespace Result;

void Output::inputFunction(const utils::Function& function) {
    functionVector.push_back(function);
}

// Sobre o tipo: Pode ser void (insere a um atributo resultTable em "Output" ou pode retornar a própria matriz)
void Output::resultTable() {
    // Implementação do método de quadro de resposta
}

void Output::comparativeTable() {
    // Implementação do método de quadro comparativo
}
