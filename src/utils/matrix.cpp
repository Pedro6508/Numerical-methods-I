#import <iostream>
#include "linear_ops.h"

using LinearOps::Matrix;

Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    m = new double *[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new double[cols];
    }
}

Matrix::Matrix(size_t n): rows(n), cols(n) {
    m = new double *[n];
    for (int i = 0; i < n; i++) {
        m[i] = new double[n];
    }
}

Matrix Matrix::unit(size_t n) {
    Matrix I(n);

    for (int i = 0; i < n; i++) {
        I.m[i][i] = 1;
    }

    return I;
}

void Matrix::print() {
    using namespace std;
    
    for (int i = 0; i < rows; i++) {
        cout << "[ ";
        for (int j = 0; j < cols; j++) {
            auto s = elementToStr(i, j);

            cout << s << " ";
        }
        cout << "]" << endl;
    }
}

Matrix Matrix::operator*(const double &scalar) {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            result.m[i][j] = m[i][j] * scalar;
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &matrix) {
    Matrix result(rows, matrix.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result.m[i][j] += m[i][k] * matrix.m[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator+(const Matrix &matrix) {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.m[i][j] = m[i][j] + matrix.m[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &matrix) {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            result.m[i][j] = m[i][j] - matrix.m[i][j];
        }
    }
    return result;
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] m[i];
    }
    delete[] m;
}

LinearOps::Vector Matrix::operator()(const LinearOps::Vector &vector) {
    if (cols != vector.size) {
        std::cerr << "Matrix and vector must be of the same size" << std::endl;
        return {{}, 0};
    }

    LinearOps::Vector result(rows);
    for (int i = 0; i < rows; i++) {
        result.getV()[i] = 0;
        for (int j = 0; j < cols; j++) {
            result.getV()[i] += m[i][j] * vector.getV()[j];
        }
    }
    return result;
}

double *Matrix::operator[](size_t i) {
    return m[i];
}

Matrix Matrix::operator!() {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "ArgumentSelectionDefects"
    Matrix result(cols, rows);
#pragma clang diagnostic pop
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.m[i][j] = m[i][cols-j-1];
        }
    }
    return result;
}

std::string Matrix::elementToStr(int i, int j) {
    auto el = m[i][j];
    auto sign = el != 0 ? (el > 0 ? "+" : "-") : " ";
    std::string s = sign + std::to_string(abs(el));
    s.resize(elSize);
    return s;
}
