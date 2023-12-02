#include <iostream>
#include "linear_ops.h"

using Linear::Gauss::Algorithm;

Algorithm::Algorithm(Matrix &A, Vector &x, Vector &b, size_t n) : A(A), b(b), x(x), n(n) {};

void Algorithm::print() {
    using namespace std;

    for (int i = 0; i < A.rows; i++) {
        cout << "[ ";
        for (int j = 0; j < A.cols; j++) {
            auto s = A.elementToStr(i, j);

            cout << s << " ";
        }
        cout
            << "| " << x.elementToStr(i) << " ] "
            << (i == A.rows/2 ? "= " : "  ")
            << "[ " << b.elementToStr(i) << " ]"
        << endl;
    }
    cout << endl;
}

void Algorithm::swapRows(size_t i, size_t j) {
    std::swap(x[i], x[j]);
    auto aux = b[i];
    b[i] = b[j];
    b[j] = aux;
    aux = x[i];
    x[i] = x[j];
    x[j] = aux;
}

void Algorithm::swapCols(size_t i, size_t j) {
    for (size_t k = 0; k < n; ++k) {
        double tmp = A[k][i];
        A[k][i] = A[k][j];
        A[k][j] = tmp;
    }
}

void Algorithm::addRow(size_t i, size_t j, double scalar) {
    x[i] += (x[j] * scalar);
    b[i] += (b[j] * scalar);
    for (size_t k = 0; k < n; ++k) {
        A[i][k] += (A[j][k] * scalar);
    }
}

Algorithm Algorithm::operator<<(const Operation &op) {
    switch (op.type) {
        case SWAP_ROWS:
            std::cout << "Swap Row: L[" << op.i << "] <=> L[" << op.j << "]" << std::endl;
            swapRows(op.i, op.j);
            print();
            break;
        case SWAP_COLS:
            std::cout << "Swap Column: C[" << op.i << "] <=> C[" << op.j << "]" << std::endl;
            swapCols(op.i, op.j);
            print();
            break;
        case ADD_ROW:
            std::cout
                << "Add Row's: L[" << op.i << "] <- "
                << "L[" << op.i << "] +  L[" << op.j << "]"
                <<  "*(" << op.scalar << ")"
            << std::endl;
            addRow(op.i, op.j, op.scalar);
            print();
            break;
        default: break;
    }
    return *this;
}
