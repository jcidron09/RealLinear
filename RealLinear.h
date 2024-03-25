//
// Created by Joshua Cidron on 1/30/24.
//

#ifndef LINEARALGEBRA_REALLINEAR_H
#define LINEARALGEBRA_REALLINEAR_H

#include <vector>

namespace LinearAlgebra{
    class Vector;
    class Matrix;
    double norm(Vector);
    double norm(Vector, int);
    double dot_product(Vector, Vector);
}
class LinearAlgebra::Vector{
    public:
        std::vector<double> elements;
        int dimension;
        explicit Vector(int dimension);
        explicit Vector(std::vector<double> contents);
        double& operator [](int index);
        friend Vector operator + (Vector vector1, Vector Vector2);
        friend bool operator == (Vector vector1, Vector vector2);
        friend Vector operator + (Vector vector1, Vector vector2);
        friend Vector& operator *= (Vector vector1, Vector vector2);
        friend Vector operator*(double scalar, const Vector& vec);
        double norm ();
        double norm (int n);
        double dot_product(Vector vector2);
        double angle(Vector vector2);

};

class LinearAlgebra::Matrix{
    public:
        int rows;
        int columns;
        double contents[rows][columns];
};

#endif //LINEARALGEBRA_REALLINEAR_H
