#ifndef METODOS_NUMERICOS_LINEAR_OPS_H
#define METODOS_NUMERICOS_LINEAR_OPS_H
#include "iostream"

namespace LinearOps {
    namespace Vec {
        class Vector {
        private:
            double *v;
            int size;
        public:
            explicit Vector(int size);

            Vector(const double *v, int size);

            Vector(const Vector &vector);

            ~Vector();

            double *getV() const;

            int getSize() const;

            double innerProduct(const Vector &vector);

            static void test();
        };

        std::ostream &operator<<(std::ostream &os, const Vector &vector);
    }

    namespace Mat {
        class Matrix {
        private:
            double **m;
            int rows, cols;

        public:
            Matrix(int rows, int cols);

            Matrix(double **m, int rows, int cols);

            Matrix(const Matrix &matrix);

            ~Matrix();

            double **getM() const;

            int getRows() const;

            int getCols() const;

            void print();

            Matrix operator+(const Matrix &matrix);

            Matrix operator-(const Matrix &matrix);

            Matrix operator*(const Matrix &matrix);

            Matrix operator*(const double &scalar);
        };
    }



}

#endif //METODOS_NUMERICOS_LINEAR_OPS_H
