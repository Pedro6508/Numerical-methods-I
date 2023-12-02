#include <iostream>
#include "utils/linear_ops.h"

int main() {
    using namespace std;
    using namespace Linear;
    using namespace Linear::Gauss;

    Matrix A(3);
    Vector x(new double[]{1, 2, 3}, 3);
    Vector b(new double[]{4, 5, 6}, 3);
    A[0] = new double[]{7,8,9};
    A[1] = new double[]{10,11,12};
    A[2] = new double[]{13,14,15};
    Algorithm Alg(A, x, b, 3);
    A.print();
    Alg.swapRows(0, 1);
    A.print();
    Alg.swapCols(0, 1);
    A.print();
}