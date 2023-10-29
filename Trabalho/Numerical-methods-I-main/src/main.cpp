#include <iostream>
#include "sonic_airplane.h"
#include "output.h"
#include <cmath>
using namespace std;

int main() {
    double a;
    double e1;
    int num_a;
    cout << "Enter an error (epsilon): ";
    cin >> e1;
    cout << "Enter the number of 'as' you want to insert: ";
    cin >> num_a;
    num_a ++; // default case
    cout << endl;


    for (int i = 0; i < num_a; i++) {
        if (i != 0) {
            cout << endl;
            cout << "Enter the value of 'a' number:" << i + 1 << ": ";
            cin >> a;
            std::cout << "The calculated insulation is: [" << floor(exp(a)) << ", " << ceil(exp(a)) << "]";
            cout << endl;
        } else {
            a = 1.f;
            e1 = 10e-5;
            double x1 = 2.f, x2 = 3.f;
            impl::SonicAirplane defaultCase(a, x1, x2, e1);

            cout << "Default case a = 1. ; insulation = (2., 3.) ; eps = 10e-5" << endl;
        };
        impl::SonicAirplane airplane1(a, e1);
        impl::SonicAirplane airplane2(a, e1);
        impl::SonicAirplane airplane3(a, e1);

        result::MethodData bisectionMethod;
        result::MethodData newtonRaphsonMethod;
        result::MethodData falsePositionMethod;

        // Test the Bisection Method implementation
        double bisection = airplane1.bisection();
        double bisectionEps =  1 - fabs(airplane1.getX2() - airplane1.getX1());
        airplane1.put(bisection, bisectionEps);
        bisectionMethod = airplane1.CaptureMethodData();

        // Test the False-Position Method implementation
        double falsePosition = airplane2.falsePosition();
        double falsePositionEps = 1 - fabs(airplane2.getX2() - airplane2.getX1());
        airplane2.put(falsePosition, falsePositionEps);
        falsePositionMethod = airplane2.CaptureMethodData();

        // Test the Newton-Raphson Method implementation
        double newtonRaphson = airplane3.newtonRaphson();
        double newtonRaphsonEps = 1 - fabs(airplane3.getX2() - airplane3.getX1());
        airplane3.put(newtonRaphson, newtonRaphsonEps);
        newtonRaphsonMethod = airplane3.CaptureMethodData();
        newtonRaphsonMethod = airplane3.CaptureMethodData();

        const map<string, result::MethodData> table{
                {"Bisection",      bisectionMethod},
                {"False-Position", falsePositionMethod},
                {"Newton-Raphson", newtonRaphsonMethod},
        };

        result::run(table);
    }

    return 0;
}
