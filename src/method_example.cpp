//
// Created by Pedro Vinicius Coêlho Belém on 13/10/23.
//

namespace method::example {
    class LinearFunc {
    public:
        const float DEFAULT_ERROR = 0.1f;

        float calc(float x) {
            float ax = angular_coefficient*x;
            float b = linear_coefficient;

            return ax + b;
        };

        void set_error(float e) {
            error = e;
        }

        void set_angular_coefficient(float ac) {
            angular_coefficient = ac;
        }

        void set_linear_coefficient(float lc) {
            linear_coefficient = lc;
        }

        LinearFunc(float ac, float lc) {
            set_angular_coefficient(ac);
            set_linear_coefficient(lc);
        };
    private:
        float error = DEFAULT_ERROR;
        float angular_coefficient{};
        float linear_coefficient{};
    };
}


