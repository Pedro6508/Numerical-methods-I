#include <cmath>
#include "sonic_airplane.h"

using namespace impl;

SonicAirplane::SonicAirplane(double a, double x1, double x2, double e1)
    : Function(a, x1, x2, 1, e1)
{
    methodData = result::MethodData{};
}

SonicAirplane::SonicAirplane(double a, double e1)
    : Function(a, floor(exp(a)), ceil(exp(a)), 1, e1), iter_bis(0), iter_newt(0), iter_pos(0), err_bis(0), err_newt(0), err_pos(0)
{
}

double SonicAirplane::f(double d)
{
    return (getA() * d - d * (log(d)));
}

double SonicAirplane::ddx(double d)
{
    return (getA() - (log(d) + 1));
}

void SonicAirplane::put(double xk, double epsk)
{
    methodData.push_back({xk, epsk});
}

result::MethodData SonicAirplane::CaptureMethodData()
{
    return methodData;
};

// The variable i will be used to limit the number of iterations

double SonicAirplane::bisection()
{
    double xk, f1, f2;
    int i = 0;
    double x1 = getX1();
    double x2 = getX2();
    double epsk = fabs(x1 - x2) - getEps();
    double m = f(x1);
    while ((epsk > 0) && (i < 100))
    {
        put(xk, epsk);
        xk = (x1 + x2) / 2;

        f1 = f(x1);
        f2 = f(x2);

        // Choose between x1 and x2
        if (f1 == 0)
        {
            return f1;
        }
        else if (f2 == 0)
        {
            return f2;
        }
        else if (m * f(xk) < 0)
        {
            x2 = xk;
        }
        else
        {
            x1 = xk;
        }

        epsk = fabs(x1 - x2) - getEps();
        i++;
    }
    return xk;
}

double SonicAirplane::falsePosition()
{
    double xk, f1, f2;
    int i = 0;
    double x1 = getX1();
    double x2 = getX2();
    double epsk = fabs(x1 - x2) - getEps();

    while ((epsk > 0) && (i < 100))
    {
        put(xk, epsk);
        if ((f(x2) - f(x1)) != 0)
        {
            xk = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        }
        else
        {
            break;
        }

        f1 = f(x1);
        f2 = f(x2);

        // Choose between x1 and x2
        if (f1 == 0)
        {
            return x1;
        }
        else if (f2 == 0)
        {
            return x2;
        }
        else if (f1 * f2 < 0)
        {
            x2 = xk;
        }
        else
        {
            x1 = xk;
        }

        epsk = fabs(x1 - x2) - getEps();
        i++;
    }
    return xk;
}

double SonicAirplane::newtonRaphson()
{
    double xk0, xk1, f1, f2;
    int i = 0;
    xk0 = getX1();
    try
    {
        xk1 = xk0 - (f(xk0) / ddx(xk0));
    }
    catch (...)
    {
        return xk0;
    }
    double epsk = fabs(xk0 - xk1) - getEps();

    while ((epsk > 0) && (i < 100))
    {
        put(xk1, epsk);
        try
        {
            xk0 = xk1;
            xk1 = xk0 - (f(xk0) / ddx(xk0));
            i++;
        }
        catch (...)
        {
            return xk0;
        }
        epsk = fabs(xk0 - xk1) - getEps();
    }
    return xk1;
}
