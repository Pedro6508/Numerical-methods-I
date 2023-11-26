#include "linear_ops.h"
#import <iostream>

using Linear::Vector;

Vector::Vector(size_t size) : size(size) {
    v = new double[size];
}

Vector::Vector(const double *u, size_t size) : size(size) {
    this->v = new double[size];
    for (int i = 0; i < size; i++) {
        this->v[i] = u[i];
    }
}

Vector::Vector(const Vector &vector) : size(vector.size), elSize(vector.elSize) {
    v = new double[size];
    for (int i = 0; i < size; i++) {
        v[i] = vector.v[i];
    }
}

Vector::Vector(size_t size, const double x, const std::function<double(double)>& f): size(size) {
    this->v = new double[size];
    double aux = x;

    for (int i = 0; i < this->size; i++) {
        this->v[i] = aux;
        aux = f(aux);
    }
}

Vector::~Vector() {
    using namespace std;
    delete[] v;
}

std::string Vector::elementToStr(int i) const {
    auto el = v[i];
    auto sign = el != 0 ? (el > 0 ? "+" : "-") : " ";
    std::string s = sign + std::to_string(abs(el));
    s.resize(elSize);
    return s;
}

double Vector::operator*(const Linear::Vector &vector) {
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

Vector Vector::operator*(const double &scalar) {
    Vector result(size);
    for (int i = 0; i < size; i++) {
        result.v[i] = v[i] * scalar;
    }
    return result;
}

Vector Vector::operator+(const Vector &vector) {
    Vector result(size);
    if (size != vector.size) {
        std::cerr << "Vectors must be of the same size" << std::endl;
        return result;
    }

    for (int i = 0; i < size; i++) {
        result.v[i] = v[i] + vector.v[i];
    }

    return result;
}

Vector Vector::operator-(const Vector &vector) {
    Vector result(size);
    if (size != vector.size) {
        std::cerr << "Vectors must be of the same size" << std::endl;
        return result;
    }

    for (int i = 0; i < size; i++) {
        result.v[i] = v[i] - vector.v[i];
    }

    return result;
}

Vector Vector::operator!() {
    Vector result(size);
    for (int i = 0; i < size; i++) {
        result.v[i] = v[size-i-1];
    }
    return result;
}

double &Vector::operator[](size_t i) const {
    return v[i];
}

double *Vector::operator~() const {
    auto u = new double [size];
    for (int i = 0; i < size; i++) {
        u[i] = v[i];
    }
    return u;
}

std::ostream &Linear::operator<<(std::ostream &os, const Vector &vector) {
    os << "[ ";
    for (int i = 0; i < vector.size; i++) {
        os << vector.elementToStr(i) << " ";
    }
    os << "]";
    return os;
}

Vector &Vector::operator=(const Vector &vector) {
    if (this == &vector) {
        return *this;
    }

    Vector u(vector);
    return u;
}

Vector &Vector::operator+=(const Vector &vector) {
    if (size != vector.size) {
        std::cerr << "Vectors must be of the same size" << std::endl;
        return *this;
    }

    for (int i = 0; i < size; i++) {
        v[i] += vector.v[i];
    }

    std::cout << *this << std::endl;

    return *this;
}