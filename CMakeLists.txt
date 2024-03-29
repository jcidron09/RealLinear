cmake_minimum_required(VERSION 3.26)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 23)

add_library(
        RealLinear.cpp
        RealLinear/RealLinear.h
        RealLinear/Tests/VectorTests.cpp
        RealLinear/Vector/Vector.cpp
        RealLinear/Errors/RealLinearErrors.cpp
        RealLinear/Errors/RealLinearErrors.h
        main.cpp
        RealLinear/Matrix/Matrix.cpp
)

add_executable(main.cpp
        main.cpp
        RealLinear/Matrix/Matrix.cpp
)