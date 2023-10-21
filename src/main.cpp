#include <iostream>
#include "output.h"
#include "sonic_airplane.h"

using namespace std;

int main() {
    Result::Output Tabela;
    cout << "1 - Inserir aviões\n2 - Quadro Resposta\n3 - Quadro Comparativo\nOutro - Sair " << endl;
    int num;
    while (true) {
        cout << ": ";
        cin >> num;
        cout << "\n";

        if (num == 1){
            double a;
            double e;
            cout << "Insira o 'a' do avião: ";
            cin >> a;
            cout << "Insira a precisão: ";
            cin >> e;
            Tabela.inputFunction(a, e);
        }
        else if(num == 2) {
            Tabela.resultTable();
            cout << "\n\n";

        }
        else if(num == 3){
            Tabela.comparativeTable();
            cout << "\n\n";

        }
        else {
            break;
        }
    }

    return 0;
}
