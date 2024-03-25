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


//----------------------------

//Overloaded Operators
//----------------------------

//----------------------------
//Vector Methods

//double norm (){
//    double norm = 0.0;
//    for (double element : this->elements){
//        norm += std::pow(element, 2.0);
//    }
//    return std::pow(norm, 1.0/2.0);
//}
//
//double norm (int n) {
//    double norm = 0.0;
//    for (double element : this->elements){
//        norm += std::pow(element, n);
//    }
//    return std::pow(norm, 1.0/n);
//}
//
//double dot_product(Vector vector2) {
//    if (dimension != vector2.dimension)
//        throw RealLinearException("VectorDimensionMatchError");
//    double dot = 0.0;
//    for (int i = 0; i < dimension; i++) {
//        dot += elements[i] * vector2[i];
//    }
//    return dot;
//}
//
//double angle(Vector vector2) {
//    if (dimension != vector2.dimension)
//        throw RealLinearException("VectorDimensionMatchError");
//    return acos(this->dot_product(vector2)/(this->norm()*vector2.norm()));
//}
//
//Vector cross_product(Vector vector2) {
//    if (dimension != vector2.dimension){
//        throw RealLinearException("VectorDimensionMatchError");
//    } else if (dimension != 3) {
//        throw RealLinearException("CrossProductDimensionError");
//    }
//    double entry_1 = this->elements[1]*vector2.elements[2] - this->elements[2]*vector2.elements[1];
//    double entry_2 = this->elements[2]*vector2.elements[0] - this->elements[0]*vector2.elements[2];
//    double entry_3 = this->elements[0]*vector2.elements[1] - this->elements[1]*vector2.elements[0];
//    return RealLinear::Vector({entry_1, entry_2, entry_3});
//}
//
//};
//
//double RealLinear::norm(const Vector& vector){
//    double norm = 0.0;
//    for (double element : vector.elements){
//        norm += std::pow(element, 2.0);
//    }
//    return std::pow(norm, 1.0/2.0);
//};
//
//double RealLinear::norm (const Vector& vector, int n) {
//    double norm = 0.0;
//    for (double element : vector.elements){
//        norm += std::pow(element, n);
//    }
//    return std::pow(norm, 1.0/n);
//};
//
//double RealLinear::dot_product(Vector vector1, Vector vector2){
//    if (vector1.dimension != vector2.dimension)
//        throw RealLinearException("VectorDimensionMatchError");
//    double dot = 0.0;
//    for (int i = 0; i < vector1.dimension; i++){
//        dot += vector1[i] * vector2[i];
//    }
//    return dot;
//};
//
//double RealLinear::angle(Vector vector1, Vector vector2) {
//    if (vector1.dimension != vector2.dimension)
//        throw RealLinearException("VectorDimensionMatchError");
//    return acos(vector1.dot_product(vector2)/(vector1.norm()*vector2.norm()));
//};
//
//RealLinear::Vector RealLinear::cross_product3d(Vector vector1, Vector vector2) {
//    if (vector1.dimension != vector2.dimension){
//        throw RealLinearException("VectorDimensionMatchError");
//    } else if (vector1.dimension != 3) {
//        throw RealLinearException("CrossProduct3DDimensionError");
//    }
//    double entry_1 = vector1.elements[1]*vector2.elements[2] - vector1.elements[2]*vector2.elements[1];
//    double entry_2 = vector1.elements[2]*vector2.elements[0] - vector1.elements[0]*vector2.elements[2];
//    double entry_3 = vector1.elements[0]*vector2.elements[1] - vector1.elements[1]*vector2.elements[0];
//    return RealLinear::Vector({entry_1, entry_2, entry_3});
//};
//
//double RealLinear::cross_product2d(Vector vector1, Vector vector2) {
//    if (vector1.dimension != vector2.dimension){
//        throw RealLinearException("VectorDimensionMatchError");
//    } else if (vector1.dimension != 2) {
//        throw RealLinearException("CrossProduct2DDimensionError");
//    }
//    return vector1.elements[0]*vector2.elements[1] - vector1.elements[1]*vector2.elements[0];
//};