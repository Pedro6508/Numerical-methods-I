#ifndef SONIC_AIRPLANE_H
#define SONIC_AIRPLANE_H

#include "function.h"

namespace impl {
class SonicAirplane : public utils::Function {
    private:
        int iter_bis;
        int iter_newt;
        int iter_pos;


    public:
        SonicAirplane(double a, double x1, double x2, double e1);
        SonicAirplane(double a, double e1);
        double f(double d) override;
        double ddx(double d) override;
        double bisection() override;
        double falsePosition() override;
        double newtonRaphson() override;
        int getIBis();
        int getINewt();
        int getIPos();
    };
}

#endif // SONIC_AIRPLANE_H
