#ifndef METODOS_NUMERICOS_MATRIX_H
#define METODOS_NUMERICOS_MATRIX_H

#include <iostream>

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

    double **operator[](size_t i);

    Matrix operator!();

    static Matrix unit(size_t n);

    static Matrix swap(size_t i, size_t j, size_t n);

    void print();

    std::string elementToStr(int i, int j);
};

#endif //METODOS_NUMERICOS_MATRIX_H
