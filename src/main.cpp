#include <iostream>
#include "utils/linear_ops.h"

int main() {
    using namespace std;
    using namespace Linear;

    Matrix A(3,4);
    *A[0] = new double[]{2,1,1,2};
    *A[1] = new double[]{1,2,1,1};
    *A[2] = new double[]{0,1,2,1};
    A.print();

    Vector L1 = Vector(*A[0], 4);
    Vector L2 = Vector(*A[1], 4);
    Vector L3 = Vector(*A[2], 4);

    *A[0] = ~L2;
    *A[1] = ~L1;
    L1 = Vector(*A[0], 4);
    L2 = Vector(*A[1], 4);
    cout << "L1 <-> L2" << endl;
    cout << "L1 = " << L1 << endl;
    cout << "L2 = " << L2 << endl;
    A.print();

    L2 += L1 * (-2);
    cout << "L1 <- L1 - 2*L2" << endl;
    *A[1] = ~L2;

    A.print();

    *A[1] = ~L3;
    *A[2] = ~L2;
    L2 = Vector(*A[1], 4);
    L3 = Vector(*A[2], 4);
    cout << "L2 <-> L3" << endl;
    cout << "L2 = " << L2 << endl;
    cout << "L3 = " << L3 << endl;
    A.print();

    L3 += L2 * (3);
    cout << "L3 <- L3 + 3*L2" << endl;
    *A[2] = ~L3;
    A.print();
}