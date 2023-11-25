#include "linear_ops.h"
#import <iostream>

using LinearOps::Vec::Vector;

Vector::Vector(int size) : size(size) {
    v = new double[size];
}

Vector::Vector(const double *v, int size) : size(size) {
    this->v = new double[size];
    for (int i = 0; i < size; i++) {
        this->v[i] = v[i];
    }
}

Vector::Vector(const Vector &vector) : size(vector.size) {
    v = new double[size];
    for (int i = 0; i < size; i++) {
        v[i] = vector.v[i];
    }
}

Vector::~Vector() {
    using namespace std;
    delete[] v;
}

double *Vector::getV() const {
    return v;
}

int Vector::getSize() const {
    return size;
}

double Vector::innerProduct(const Vector &vector) {
    double result = 0;
    if (size != vector.size) {
        std::cerr << "Vectors must be of the same size" << std::endl;
        return result;
    }

    for (int i = 0; i < size; i++) {
        result += v[i] * vector.v[i];
    }

    return result;
}

std::ostream &LinearOps::Vec::operator<<(std::ostream &os, const LinearOps::Vec::Vector &vector) {
    os << "[ ";
    for (int i = 0; i < vector.getSize(); i++) {
        os << vector.getV()[i] << " ";
    }
    os << "]";
    return os;
}



void Vector::test() {
    using namespace std;

    double v1[] = {1, 1, 1, 1, 1};
    double v2[] = {2, 2, 2, 2, 2};
    Vector vector1(v1, 5);
    Vector vector2(v2, 5);

    double result = vector1.innerProduct(vector2);
    cout << "The inner product of " << vector1 << " and " << vector2 << " is " << result << endl;
}