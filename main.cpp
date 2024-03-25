//
// Created by Joshua Cidron on 1/30/24.
//


#include "RealLinear/RealLinear.cpp"
#include <iostream>
#include <cassert>


int main(){
    RealLinear::Vector vector_1({1,2,3});
    RealLinear::Vector vector_2({4,5,6,2});
    RealLinear::Vector vector_3({4,5,6});

    int null = vector_1[1];


//    std::cout << vector_1.dot_product(vector_3) << std::endl;
//    std::cout << vector_1.angle(vector_3);
    return 0;
}