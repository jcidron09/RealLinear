//
// Created by Joshua Cidron on 1/30/24.
//

#ifndef LINEARALGEBRA_REALLINEAR_H
#define LINEARALGEBRA_REALLINEAR_H

#include <vector>
#include <tuple>
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

        std::string string();
        double norm ();
        double norm (int n);
        double dot_product(Vector vector2);
        double angle(Vector vector2);
        Vector cross_product(Vector vector2);
};

class RealLinear::Matrix {
    public:
        int rows;
        int columns;
        std::tuple<int, int> dimension;

        std::vector<RealLinear::Vector> entries;
        Matrix();
        Matrix(int rows, int columns);
        Matrix(std::tuple<int, int> dimension) : Matrix(std::get<0>(dimension), std::get<1>(dimension)) {};
        Matrix(std::vector<RealLinear::Vector>& entries);

        Vector& operator [](int index);
        Matrix operator + (Matrix matrix);
        Matrix operator += (Matrix matrix);
        bool operator == (Matrix matrix);
        Matrix& operator *= (double scalar);
        Matrix& operator * (double scalar);

        //getters
        Vector row (int index);
        Vector column (int index);
        std::string string();
        //actual methods
        Vector operator * (Vector vector);
        Matrix operator * (Matrix matrix);
};


#endif //LINEARALGEBRA_REALLINEAR_H
