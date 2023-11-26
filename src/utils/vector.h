#ifndef METODOS_NUMERICOS_VECTOR_H
#define METODOS_NUMERICOS_VECTOR_H
#include <iostream>

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

    double &operator[](size_t i) const;

    double *operator~() const;

    Vector &operator=(const Vector &vector);

    Vector &operator+=(const Vector &vector);

    std::string elementToStr(int i) const;
};

std::ostream &operator<<(std::ostream &os, const Linear::Vector &vector);

#endif //METODOS_NUMERICOS_VECTOR_H
