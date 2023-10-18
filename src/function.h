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
