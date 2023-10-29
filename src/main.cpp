#include <iostream>
#include "sonic_airplane.h"
#include "output.h"
#include <cmath>
using namespace std;

int main() {
    double a = 1.0;
    double x1 = 2.0;
    double x2 = 3.0;
    double e1 = 10e-5;
    impl::SonicAirplane airplane1(a, x1, x2, e1);
    impl::SonicAirplane airplane2(a, x1, x2, e1);
    impl::SonicAirplane airplane3(a, x1, x2, e1);

    result::MethodData bisectionMethod;
    result::MethodData newtonRaphsonMethod;
    result::MethodData falsePositionMethod;

    // Test the Bisection Method implementation
    double bisection = airplane1.bisection();
    double bisectionEps = a - fabs(airplane1.getX2() - airplane1.getX1());
    airplane1.put(bisection, bisectionEps);
    for (int i=0; i<airplane1.CaptureMethodData().size(); i++)  {
        bisectionMethod.push_back(airplane1.CaptureMethodData()[i]);
    }

    // Test the False-Position Method implementation
    double falsePosition = airplane2.falsePosition();
    double falsePositionEps = a - fabs(airplane2.getX2() - airplane2.getX1());
    airplane2.put(falsePosition, falsePositionEps);
    for (int i=0; i< airplane2.CaptureMethodData().size(); i++)  {
        falsePositionMethod.push_back(airplane2.CaptureMethodData()[i]);
    }
    cout << "False-Position Method result: " << falsePosition << endl;

    // Test the Newton-Raphson Method implementation
    double newtonRaphson = airplane3.newtonRaphson();
    double newtonRaphsonEps = a - fabs(airplane3.getX2() - airplane3.getX1());
    airplane3.put(newtonRaphson, newtonRaphsonEps);
    for (int i=0; i<airplane3.CaptureMethodData().size(); i++)  {
        newtonRaphsonMethod.push_back(airplane3.CaptureMethodData()[i]);
    }
    newtonRaphsonMethod = airplane3.CaptureMethodData();
    cout << "Newton-Raphson Method result: " << newtonRaphson << endl;

    const map<string, result::MethodData> table{
            {"Bisection", bisectionMethod},
            {"False-Position", falsePositionMethod},
            {"Newton-Raphson", newtonRaphsonMethod},
    };

    result::run(table);
    return 0;
}
