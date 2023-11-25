#include <iostream>
#include "utils/linear_ops.h"

double f(double t) {
    return t*t;
}

int main() {
    using namespace std;
    using namespace LinearOps;

    Matrix I = Matrix::unit(5);
    I.print();
    (!I).print();

    auto u = Vector(5, 5, f);
    cout << u << " " << !u;
}
