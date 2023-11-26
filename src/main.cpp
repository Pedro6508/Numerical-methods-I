#include <iostream>
#include "utils/linear_ops.h"

int main() {
    using namespace std;
    using namespace Linear;

    Matrix A(3);
    *A[0] = new double[]{1, 2,-1};
    *A[1] = new double[]{3, 5, 2};
    *A[2] = new double[]{8, 14, 2};
    A.print();

    Vector L1 = Vector(*A[0], 3);
    Vector L2 = Vector(*A[1], 3);
    Vector L3 = Vector(*A[2], 3);

    L2 += L1 * (-3);
    cout << "L2 <- L2 - 3*L1" << endl;
    L3 += L1 * (-8);
    cout << "L3 <- L3 - 8*L1" << endl;

    *A[1] = ~L2;
    *A[2] = ~L3;
    A.print();

    L3 += L2 * (-2);
    cout << "L3 <- L3 - 2*L2" << endl;

    *A[2] = ~L3;
    A.print();
}