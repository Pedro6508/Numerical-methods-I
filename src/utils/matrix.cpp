#import <iostream>
#include "linear_ops.h"

using Linear::Matrix;

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

Matrix Linear::swap(size_t i, size_t j, size_t n) {
    Matrix S = Matrix::unit(n);
    auto aux = new double[n];
    for (int k = 0; k < n; k++) {
        aux[k] = (*S[i])[k];
    }

    *S[i] = *S[j];
    *S[j] = aux;
    return S;
}

void Matrix::print() {
    using namespace std;
    cout << endl;
    for (int i = 0; i < rows; i++) {
        cout << "[ ";
        for (int j = 0; j < cols; j++) {
            auto s = elementToStr(i, j);

            cout << s << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
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

Linear::Vector Matrix::operator()(const Linear::Vector &vector) {
    if (cols != vector.size) {
        std::cerr << "Matrix and vector must be of the same size" << std::endl;
        return {{}, 0};
    }

    Linear::Vector result(vector.size);
    auto u = new double [vector.size];
    for (int i = 0; i < rows; i++) {
        u[i] = 0;
        for (int j = 0; j < cols; j++) {
            double el = vector[j];
            result[i] += m[i][j] * el;
        }
    }
    return result;
}

double **Matrix::operator[](const size_t i) {
    return &m[i];
}

Matrix Matrix::operator!() {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "ArgumentSelectionDefects"
    Matrix result(cols, rows);
#pragma clang diagnostic pop

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.m[j][i] = m[i][j];
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