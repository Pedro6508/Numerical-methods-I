#ifndef METODOS_NUMERICOS_LINEAR_OPS_H
#define METODOS_NUMERICOS_LINEAR_OPS_H
#include "iostream"

namespace LinearOps {
    class Vector {
    private:
        double *v;
    public:
        const size_t size;
        const u_int elSize = 5;

        explicit Vector(size_t size);

        Vector(const double *v, size_t size);

        Vector(const Vector &vector);

        Vector(size_t size, double x, const std::function<double(double)>& f);

        ~Vector();

        Vector operator*(const double &scalar);

        Vector operator+(const Vector &vector);

        Vector operator-(const Vector &vector);

        double operator*(const Vector &vector);

        Vector operator!();

        double &operator[](size_t i);

        double *getV() const;

        std::string elementToStr(int i) const;
    };

    std::ostream &operator<<(std::ostream &os, const LinearOps::Vector &vector);

    class Matrix {
    private:
        double **m;
        const u_int elSize = 5;
    public:
        const size_t rows, cols;

        Matrix(size_t rows, size_t cols);

        Matrix(size_t n);

        Matrix(const Matrix &matrix);

        ~Matrix();

        Matrix operator+(const Matrix &matrix);

        Matrix operator-(const Matrix &matrix);

        Matrix operator*(const Matrix &matrix);

        Matrix operator*(const double &scalar);

        Vector operator()(const Vector &vector);

        double *operator[](size_t i);

        Matrix operator!();

        static Matrix unit(size_t n);

        void print();

        std::string elementToStr(int i, int j);
    };
}

#endif //METODOS_NUMERICOS_LINEAR_OPS_H
