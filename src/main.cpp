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

    result::MethodData bisectionMethod;
//    {{1, 1}, {2, 2}, {4, 4}, {8, 8}};
    result::MethodData newtonRaphsonMethod;
//    {{1, 1}, {5, 5}, {25, 25}};
    result::MethodData falsePositionMethod;
//    {{1, 1}, {3, 3}, {9, 9}, {27,27}, {81, 81}, {243, 243}};

    // Test the Bisection Method implementation
    double bisection = airplane.bisection();
    bisectionMethod = airplane.CaptureMethodData();
    cout << "Bisection Method result: " << bisection << endl;

    // Test the False-Position Method implementation
    double falsePosition = airplane.falsePosition();
    falsePositionMethod = airplane.CaptureMethodData();
    cout << "False-Position Method result: " << falsePosition << endl;

    // Test the Newton-Raphson Method implementation
    double newtonRaphson = airplane.newtonRaphson();
    newtonRaphsonMethod = airplane.CaptureMethodData();
    cout << "Newton-Raphson Method result: " << newtonRaphson << endl;

    const map<string, result::MethodData> table{
            {"Bisection", bisectionMethod},
            {"False-Position", falsePositionMethod},
            {"Newton-Raphson", newtonRaphsonMethod},
    };

    result::run(table);
    return 0;
}
