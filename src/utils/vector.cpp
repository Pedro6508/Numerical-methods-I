#include "linear_ops.h"
#import <iostream>

using Linear::Vector;

Vector::Vector(const size_t size) : size(size) {
    v = new double[size];
}

Vector::Vector(const double *v, const size_t size) : size(size) {
    this->v = new double[size];
    for (int i = 0; i < size; i++) {
        this->v[i] = v[i];
    }
}

Vector::Vector(const Vector &vector) : size(vector.size), elSize(vector.elSize) {
    v = new double[size];
    for (int i = 0; i < size; i++) {
        v[i] = vector.v[i];
    }
}

Vector::Vector(const size_t size, const double x, const std::function<double(double)>& f): size(size) {
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
    const auto el = v[i];
    const auto sign = el != 0 ? (el > 0 ? "+" : "-") : " ";
    std::string s = sign + std::to_string(abs(el));
    s.resize(elSize);
    return s;
}

double Vector::operator*(const Vector &rsh) const {
    double result = 0;
    if (size != rsh.size) {
        std::cerr << "Vectors must be of the same size" << std::endl;
        return result;
    }

    for (int i = 0; i < size; i++) {
        result += v[i] * rsh.v[i];
    }

    return result;
}

Vector Vector::operator*(const double &scalar) const {
    Vector result(size);
    for (int i = 0; i < size; i++) {
        result.v[i] = v[i] * scalar;
    }
    return result;
}

Vector Vector::operator+(const Vector &rsh) const {
    Vector result(size);
    if (size != rsh.size) {
        std::cerr << "Vectors must be of the same size" << std::endl;
        return result;
    }

    for (int i = 0; i < size; i++) {
        result.v[i] = v[i] + rsh.v[i];
    }

    return result;
}

Vector Vector::operator-(const Vector &rsh) const {
    Vector result(size);
    if (size != rsh.size) {
        std::cerr << "Vectors must be of the same size" << std::endl;
        return result;
    }

    for (int i = 0; i < size; i++) {
        result.v[i] = v[i] - rsh.v[i];
    }

    return result;
}

Vector Vector::operator!() const {
    Vector result(size);
    for (int i = 0; i < size; i++) {
        result.v[i] = v[size-i-1];
    }
    return result;
}

double& Vector::operator[](const size_t i) const {
    return v[i];
}

std::ostream &Linear::operator<<(std::ostream &os, const Vector &vector) {
    os << "[ ";
    for (int i = 0; i < vector.size; i++) {
        os << vector.elementToStr(i) << " ";
    }
    os << "]";
    return os;
}

Vector &Vector::operator=(double*& rsh) {
    this->v = rsh;
    return *this;
}


Vector &Vector::operator=(const Vector &rsh) {
    if (size != rsh.size) {
        std::cerr << "Vectors must be of the same size" << std::endl;
        return *this;
    }

    if (this == &rsh) {
        return *this;
    }

    for (int i = 0; i < size; i++) {
        v[i] = rsh.v[i];
    }

    return *this;
}

Vector &Vector::operator=(const Vector &&rsh) {
    if (size != rsh.size) {
        std::cerr << "Vectors must be of the same size" << std::endl;
        return *this;
    }

    if (this == &rsh) {
        return *this;
    }

    v = rsh.v;

    return *this;
}

Vector &Vector::operator+=(const Vector &rsh) {
    if (size != rsh.size) {
        std::cerr << "Vectors must be of the same size" << std::endl;
        return *this;
    }

    for (int i = 0; i < size; i++) {
        v[i] += rsh.v[i];
    }

    return *this;
}