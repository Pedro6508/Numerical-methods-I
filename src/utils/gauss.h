#ifndef METODOS_NUMERICOS_GAUSS_H
#define METODOS_NUMERICOS_GAUSS_H
#include <iostream>
#include "vector.h"
#include "matrix.h"

enum Type {
    SWAP_ROWS,
    SWAP_COLS,
    ADD_ROW,
    ADD_COL
};

struct Operation {
    Type type;
    size_t pivot, j;
    double scalar;
};

class Algorithm {
private:
    Matrix *A;
    Vector *b;
    Vector *x;
    size_t n;

public:
    Algorithm(Matrix *A, Vector *b, Vector *x, size_t n);

    void swapRows(size_t i, size_t j);

    void swapCols(size_t i, size_t j);

    void addRow(size_t i, size_t j, double scalar);

    void addCol(size_t i, size_t j, double scalar);

    Algorithm operator<<(const Operation &op);
};

#endif //METODOS_NUMERICOS_GAUSS_H
