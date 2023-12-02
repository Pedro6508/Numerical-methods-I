#ifndef METODOS_NUMERICOS_VECTOR_H
#define METODOS_NUMERICOS_VECTOR_H

class Vector {
    double *v;
public:
    const size_t size;
    const u_int elSize = 5;

    explicit Vector(size_t size);

    Vector(const double *v, size_t size);

    Vector(const Vector &vector);

    Vector(size_t size, double x, const std::function<double(double)>& f);

    ~Vector();

    Vector operator*(const double &scalar) const;

    Vector operator+(const Vector &vector) const;

    Vector operator-(const Vector &rsh) const;

    double operator*(const Vector &rsh) const;

    Vector operator!() const;

    double& operator[](const size_t i) const;

    Vector &operator=(const double *rsh);

    Vector &operator=(const Vector &rsh);

    Vector &operator=(const Vector &&rsh);

    Vector &operator+=(const Vector &rsh);

    std::string elementToStr(int i) const;
};

std::ostream &operator<<(std::ostream &os, const Linear::Vector &vector);

#endif //METODOS_NUMERICOS_VECTOR_H
