#include <iostream>
#include "linear_ops.h"

using Linear::Gauss::Algorithm;

Algorithm::Algorithm(Matrix &A, Vector &x, Vector &b, size_t n) : A(A), b(b), x(x), n(n) {};

void Algorithm::swapRows(size_t i, size_t j) {;
    std::swap(x[i], x[j]);
    std::swap(b[i], b[j]);
    std::swap(*A[i], *A[j]);
}

void Algorithm::swapCols(size_t i, size_t j) {
    for (size_t k = 0; k < n; ++k) {
        double *tmp = A[k][i];
        A[k][i] = A[k][j];
        A[k][j] = tmp;
    }
}

void Algorithm::addRow(size_t i, size_t j, double scalar) {
    Vector v = Vector(*A[i], n);
    Vector u = Vector(*A[j], n);

     x[i] += (x[j] * scalar);
     b[i] += (b[j] * scalar);
     v += (v * scalar);
     *A[i] = ~v;
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
    }
    return *this;
}
