#include <iostream>
#include "sonic_airplane.h"
#include "output.h"
using namespace std;

int main() {
    double a = 1.0;
    double x1 = 2.0;
    double x2 = 3.0;
    double e1 = 10e-5;
    impl::SonicAirplane airplane(a, x1, x2, e1);

    // Test the Bisection Method implementation
    double bisection = airplane.bisection();
    cout << "Bisection Method result: " << bisection << endl;

    // Test the False-Position Method implementation
    double falsePosition = airplane.falsePosition();
    cout << "False-Position Method result: " << falsePosition << endl;

    // Test the Newton-Raphson Method implementation
    double newtonRaphson = airplane.newtonRaphson();
    cout << "Newton-Raphson Method result: " << newtonRaphson << endl;

    result::run();
    return 0;
}
