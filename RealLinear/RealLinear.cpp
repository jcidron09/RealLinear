//
// Created by Joshua Cidron on 1/30/24.
//
#include <utility>
#include <vector>
#include <cmath>
#include "RealLinear.h"
#include "Errors/RealLinearErrors.cpp"
#include "Vector/Vector.cpp"
namespace RealLinear{
    class Vector;
    double norm(const Vector&);
    double norm(const Vector&, int);
    double dot_product(Vector, Vector);
    double angle(Vector, Vector);
    Vector cross_product3d(Vector, Vector);
    double cross_product2d(Vector, Vector);
}