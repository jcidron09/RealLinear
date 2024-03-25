cmake_minimum_required(VERSION 3.26)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 23)

add_library(LinearAlgebra SHARED library.cpp
        RealLinear.cpp
        RealLinear.h
        main.cpp
        VectorSpaceTest.cpp
        VectorSpaceTest.h
        RealLinearErrors.cpp
        RealLinearErrors.h
)

add_executable(main.cpp
        main.cpp
)