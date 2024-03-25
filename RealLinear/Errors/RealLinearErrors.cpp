//
// Created by Joshua Cidron on 2/2/24.
//

#include "RealLinearErrors.h"

RealLinearException::RealLinearException(const std::string& error_type) {
    if (error_type  == "VectorDimensionMatchError"){
        RealLinearException::error_text = "To perform this operation, vectors must share the same dimension!\n";
    } else if (error_type == "CrossProduct3DDimensionError"){
        RealLinearException::error_text = "To do a 3D cross product, vectors must be in 3 dimensions!\n";
    } else if (error_type == "CrossProduct2DDimensionError"){
        RealLinearException::error_text = "To do a 2D cross product, vectors must be in 2 dimensions!\n";
    } else {
        RealLinearException::error_text = "Something went Wrong!";
    }
}
