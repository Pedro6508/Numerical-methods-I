#include <iostream>
#include "linear_ops.h"

using Linear::Gauss::Algorithm;

Algorithm::Algorithm(Matrix *A, Vector *b, Vector *x, size_t n) : A(A), b(b), x(x), n(n) {};

void Algorithm::swapRows(size_t i, size_t j) {;
    auto u = Linear::Vector(*A->operator[](i), n);
    auto v = Linear::Vector(*A->operator[](j), n);

    *A->operator[](i) = ~v;
    *A->operator[](j) = ~u;
}

void Algorithm::swapCols(size_t i, size_t j) {
    for (size_t k = 0; k < n; ++k) {
        double *tmp = A->operator[](k)[i];
        A->operator[](k)[i] = A->operator[](k)[j];
        A->operator[](k)[j] = tmp;
    }
}

void Algorithm::addRow(size_t i, size_t j, double scalar) {
    Vector v = Vector(*A->operator[](i), n);
    Vector u = Vector(*A->operator[](j), n);

     v += (v * scalar);
     *A->operator[](i) = ~v;
}

void Algorithm::addCol(size_t i, size_t j, double scalar) {
    for (size_t k = 0; k < n; ++k) {
        *A->operator[](k)[i] += scalar * (*A->operator[](k)[j]);
    }
}

Algorithm Algorithm::operator<<(const Operation &op) {
    switch (op.type) {
        case SWAP_ROWS:
            swapRows(op.pivot, op.j);
            break;
        case SWAP_COLS:
            swapCols(op.pivot, op.j);
            break;
        case ADD_ROW:
            addRow(op.pivot, op.j, op.scalar);
            break;
        case ADD_COL:
            addCol(op.pivot, op.j, op.scalar);
            break;
    }
    return *this;
}
