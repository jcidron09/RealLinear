cmake_minimum_required(VERSION 3.26)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 23)

add_library(LinearAlgebra SHARED library.cpp
        LinearAlgebra.cpp
        LinearAlgebra.h
        main.cpp
        VectorSpaceTest.cpp
        VectorSpaceTest.h
        LinearAlgebraErrors.cpp
        LinearAlgebraErrors.h
)

add_executable(main.cpp
        main.cpp
)