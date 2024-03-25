//
// Created by Joshua Cidron on 1/30/24.
//
#include <utility>
#include <vector>
#include <cmath>
#include "LinearAlgebraErrors.cpp"
namespace LinearAlgebra{
    class Vector;
    class Matrix;
    double norm(const Vector&);
    double norm(const Vector&, int);
    double dot_product(Vector, Vector);
    double angle(Vector, Vector);
    Vector cross_product3d(Vector, Vector);
    double cross_product2d(Vector, Vector);
}
class LinearAlgebra::Vector{
    public:
        std::vector<double> elements;
        int dimension;

        //Vector Constructors & Property Methods
        //----------------------------
        Vector(){
            Vector::elements = {};
            Vector::dimension = 0;
        }

        explicit Vector(int dimension){
            Vector::dimension = dimension;
            for (int i = 0; i < dimension; i++){
                Vector::elements.push_back(0);
            }
        }

        explicit Vector(std::vector<double> elements){
            Vector::elements = std::move(elements);
            Vector::dimension = Vector::elements.size();
        }

        //----------------------------

        //Overloaded Operators
        //----------------------------
        double& operator [](int index){
            return elements[index];
        }

        friend bool operator == (Vector vector1, Vector vector2){
            if (vector1.dimension != vector2.dimension) throw LinearAlgebraException("VectorDimensionMatchError");
                for (int i = 0; i < vector1.elements.size(); i++){
                if (vector1.elements[i] != vector2.elements[i]){
                    return false;
                }
            }
            return true;
        }

        friend Vector operator + (Vector vector1, Vector vector2){
            auto* sum = new Vector(vector1.dimension);
            if (vector1.dimension != vector2.dimension) throw LinearAlgebraException("VectorDimensionMatchError");
            for (int i = 0; i < vector1.dimension; i++){
                sum->elements[i] = vector1.elements[i] + vector2.elements[i];
            }
            return *sum;
        }

        Vector& operator*= (double scalar){
            for (double& content : this->elements) {
                content *= scalar;
            }
            return *this;
        }

        friend Vector operator*(double scalar, const Vector& vec) {
            Vector result = vec;

            for (double& content : result.elements) {
                content *= scalar;
            }

            return result;
        }

        friend Vector operator*=(double scalar, const Vector& vec) {
            Vector result = vec;

            for (double& content : result.elements) {
                content *= scalar;
            }

            return result;
        }

        //----------------------------
        //Vector Methods

        double norm (){
            double norm = 0.0;
            for (double element : this->elements){
                norm += std::pow(element, 2.0);
            }
            return std::pow(norm, 1.0/2.0);
        }

        double norm (int n) {
            double norm = 0.0;
            for (double element : this->elements){
                norm += std::pow(element, n);
            }
            return std::pow(norm, 1.0/n);
        }

        double dot_product(Vector vector2) {
            if (dimension != vector2.dimension)
                throw LinearAlgebraException("VectorDimensionMatchError");
            double dot = 0.0;
            for (int i = 0; i < dimension; i++) {
                dot += elements[i] * vector2[i];
            }
            return dot;
        }

        double angle(Vector vector2) {
            if (dimension != vector2.dimension)
                throw LinearAlgebraException("VectorDimensionMatchError");
            return acos(this->dot_product(vector2)/(this->norm()*vector2.norm()));
        }

        Vector cross_product(Vector vector2) {
            if (dimension != vector2.dimension){
                throw LinearAlgebraException("VectorDimensionMatchError");
            } else if (dimension != 3) {
                throw LinearAlgebraException("CrossProductDimensionError");
            }
                double entry_1 = this->elements[1]*vector2.elements[2] - this->elements[2]*vector2.elements[1];
                double entry_2 = this->elements[2]*vector2.elements[0] - this->elements[0]*vector2.elements[2];
                double entry_3 = this->elements[0]*vector2.elements[1] - this->elements[1]*vector2.elements[0];
                return LinearAlgebra::Vector({entry_1, entry_2, entry_3});
        }

};

double LinearAlgebra::norm(const Vector& vector){
    double norm = 0.0;
    for (double element : vector.elements){
        norm += std::pow(element, 2.0);
    }
    return std::pow(norm, 1.0/2.0);
};

double LinearAlgebra::norm (const Vector& vector, int n) {
    double norm = 0.0;
    for (double element : vector.elements){
        norm += std::pow(element, n);
    }
    return std::pow(norm, 1.0/n);
};

double LinearAlgebra::dot_product(Vector vector1, Vector vector2){
    if (vector1.dimension != vector2.dimension) throw LinearAlgebraException("VectorDimensionMatchError");
    double dot = 0.0;
    for (int i = 0; i < vector1.dimension; i++){
        dot += vector1[i] * vector2[i];
    }
    return dot;
};

double LinearAlgebra::angle(Vector vector1, Vector vector2) {
    if (vector1.dimension != vector2.dimension)
        throw LinearAlgebraException("VectorDimensionMatchError");
    return acos(vector1.dot_product(vector2)/(vector1.norm()*vector2.norm()));
};

LinearAlgebra::Vector LinearAlgebra::cross_product3d(Vector vector1, Vector vector2) {
    if (vector1.dimension != vector2.dimension){
        throw LinearAlgebraException("VectorDimensionMatchError");
    } else if (vector1.dimension != 3) {
        throw LinearAlgebraException("CrossProduct3DDimensionError");
    }
    double entry_1 = vector1.elements[1]*vector2.elements[2] - vector1.elements[2]*vector2.elements[1];
    double entry_2 = vector1.elements[2]*vector2.elements[0] - vector1.elements[0]*vector2.elements[2];
    double entry_3 = vector1.elements[0]*vector2.elements[1] - vector1.elements[1]*vector2.elements[0];
    return LinearAlgebra::Vector({entry_1, entry_2, entry_3});
};

double LinearAlgebra::cross_product2d(Vector vector1, Vector vector2) {
    if (vector1.dimension != vector2.dimension){
        throw LinearAlgebraException("VectorDimensionMatchError");
    } else if (vector1.dimension != 2) {
        throw LinearAlgebraException("CrossProduct2DDimensionError");
    }
    return vector1.elements[0]*vector2.elements[1] - vector1.elements[1]*vector2.elements[0];
};