#include "linear_ops.h"
#import <iostream>

using LinearOps::Mat::Matrix;

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    m = new double *[rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new double[cols];
    }
}

void Matrix::print() {
    using namespace std;
    
    for (int i = 0; i < rows; i++) {
        cout << "[ ";
        for (int j = 0; j < cols; j++) {
            cout << m[i][j] << " ";
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
        for (int j = 0; j < matrix.cols; j++) {
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

LinearOps::Mat::Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] m[i];
    }
    delete[] m;
}


















