//
// Created by Joshua Cidron on 2/2/24.
//

#include "RealLinearErrors.h"

RealLinearException::RealLinearException(const std::string& error_type) {
    this->error_type = error_type;
    if (error_type  == "VectorDimensionMatchError") {
        RealLinearException::error_text = "To perform this operation, vectors must share the same dimension!\n";
    } else if (error_type == "CrossProduct3DDimensionError") {
        RealLinearException::error_text = "To do a 3D cross product, vectors must be in 3 dimensions!\n";
    } else if (error_type == "CrossProduct2DDimensionError") {
        RealLinearException::error_text = "To do a 2D cross product, vectors must be in 2 dimensions!\n";
    } else if (error_type == "ZeroDimensionalVector") {
        RealLinearException::error_text = "Vector is 0 dimensional!\n";
    } else if (error_type == "VectorIndexOutOfBounds") {
        RealLinearException::error_text = "Index is greater than the dimension of the vector!\n";
    } else if (error_type == "MatrixVectorConstructionError") {
        RealLinearException::error_text = "Vectors trying to be instanced are not all of the same size!\n";
    } else if (error_type == "ZeroDimensionalMatrix") {
        RealLinearException::error_text = "Matrix row or column is zero dimensional!\n";
    } else if (error_type == "MatrixIndexOutOfBounds") {
        RealLinearException::error_text = "Index is greater than the dimension of the matrix!\n";
    }  if (error_type  == "MatrixDimensionMatchError") {
        RealLinearException::error_text = "To perform this operation, matrices must share the same dimension!\n";
    }else {
        RealLinearException::error_text = "Something went Wrong!";
    }
}

std::string RealLinearException::type() {
    return error_type;
}