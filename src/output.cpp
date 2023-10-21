#include "output.h"
#include <iomanip>
#include <iostream>
#include "function.h"
#include <cmath>

using namespace Result;



void Output::inputFunction(double a, double e1){
    impl::SonicAirplane ap(a, e1);
        //Comparativo: [[j1, k1, d1, ]]
        // RESULTADO: [[d1, e1, d2, e2, d3, e3], []]
        // Você pode adicionar "quadro resposta" e "quadro comparativo" como atributos
    double bis = ap.bisection();
    double newton = ap.newtonRaphson();
    double false_pos = ap.falsePosition();
    std::vector<double> comp = {a, e1, floor(exp(a)), ceil(exp(a)),  bis, (double) ap.getIBis(), false_pos, (double) ap.getIPos(), newton, (double) ap.getINewt()};
    comparativeData.push_back(comp);
    std::vector<double> result = {a, e1, bis, false_pos, newton};
    resultData.push_back(result);

    
}

void Output::resultTable(){
     // Printa
    std::cout << std::left << std::setw(5) << " a" << std::setw(10) << " erro" << std::setw(15) << " bisseção" 
              << std::setw(18) << "posição falsa" << std::setw(10) << "     newton " << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    for (int i = 0; i < resultData.size(); i++){
        std::cout << " " << std::left << std::setw(5) << resultData[i][0] << std::setw(10) << resultData[i][1]
                  << std::setw(15) << resultData[i][2] << std::setw(18) << resultData[i][3]
                  << std::setw(10) << resultData[i][4] << std::endl; 
    }
}

void Output::comparativeTable(){ // Printa
   std::cout << " a       erro        intervalo     bisseção          posição falsa      newton " << std::endl;
   std::cout << "-------------------------------------------------------------------------------" << std::endl;

     for (int i = 0; i < comparativeData.size(); i++) {
        std::cout << " " << std::left << std::setw(8) << comparativeData[i][0] << 
        std::setw(12) << comparativeData[i][1] << std::setw(15) << "[" + std::to_string((int)(comparativeData[i][2]))
        + "," + std::to_string((int)comparativeData[i][3]) + "]" << 
        std::setw(19) << std::to_string (comparativeData[i][4]) + " " + std::to_string((int) comparativeData[i][5]) 
        << std::setw(17) << std::to_string (comparativeData[i][6]) + " " + std::to_string((int) comparativeData[i][7])
        << std::to_string(comparativeData[i][8]) + " " + std::to_string((int) comparativeData[i][9]) <<std::endl; 
    }
}

// [raiz, erro, raiz, erro, raiz, erro]