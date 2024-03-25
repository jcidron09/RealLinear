//
// Created by Joshua Cidron on 1/30/24.
//

#ifndef LINEARALGEBRA_REALLINEAR_H
#define LINEARALGEBRA_REALLINEAR_H

#include <vector>
#include "Errors/RealLinearErrors.h"


namespace RealLinear{
    class Vector;
    class Matrix;
    double norm(Vector&);
    double norm(Vector&, int);
    double dot_product(Vector& vector1, Vector& vector2);
    double angle(Vector&, Vector&);
    Vector cross_product3d(Vector&, Vector&);
    double cross_product2d(Vector&, Vector&);
}
class RealLinear::Vector {
    public:
        std::vector<double> elements;
        int dimension;

        Vector();
        explicit Vector(int dimension);
        explicit Vector(std::vector<double> contents);

        double& operator [](int index);
        Vector operator + (Vector vector);
        Vector operator += (Vector vector);
        bool operator == (Vector vector);
        Vector& operator *= (double scalar);
        Vector& operator * (double scalar);

        double norm ();
        double norm (int n);
        double dot_product(Vector vector2);
        double angle(Vector vector2);
        Vector cross_product(Vector vector2);
};


#endif //LINEARALGEBRA_REALLINEAR_H
