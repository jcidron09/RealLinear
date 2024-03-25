//
// Created by Joshua Cidron on 1/30/24.
//


#include "LinearAlgebra.cpp"
#include <iostream>
int main(){
    LinearAlgebra::Vector vector_1({1,2,3});
    LinearAlgebra::Vector vector_2({4,5,6,2});
    LinearAlgebra::Vector vector_3({4,5,6});

    std::cout << vector_1.dot_product(vector_3) << std::endl;
    std::cout << vector_1.angle(vector_3);
    return 0;
}