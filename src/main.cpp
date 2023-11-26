#include <iostream>
#include "utils/linear_ops.h"

int main() {
    using namespace std;
    using namespace Linear;
    using namespace Linear::Gauss;

    Matrix A(3);
    Vector x(new double[]{1, 2, 3}, 3);
    Vector b(new double[]{1, 2, 3}, 3);
    *A[0] = new double[]{2,1,1};
    *A[1] = new double[]{1,2,1};
    *A[2] = new double[]{0,1,2};
    Algorithm Alg(A, x, b, 3);
    Alg.swapRows(0, 1);
    A.print();
    cout << "x = " << x << endl;

    // TODO: Fix this
    cout << "b = " << b << endl;

    // TODO: Fix this
    Alg.swapCols(0, 1);
    A.print();
}