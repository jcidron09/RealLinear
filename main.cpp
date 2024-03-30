//
// Created by Joshua Cidron on 1/30/24.
//


#include "RealLinear/RealLinear.cpp"
#include <iostream>
#include <cassert>

int main(){
    RealLinear::Vector vector_1({1,2,3});
    RealLinear::Vector vector_2({4,5,6});
    RealLinear::Vector vector_3({7,8,9});

    RealLinear::Matrix matrix_1(3,3);

    matrix_1.entries[0][0] = 1;
    matrix_1.entries[0][1] = 2;
    matrix_1.entries[0][2] = 3;
    matrix_1.entries[1][0] = 4;
    matrix_1.entries[1][1] = 5;
    matrix_1.entries[1][2] = 6;
    matrix_1.entries[2][0] = 7;
    matrix_1.entries[2][1] = 8;
    matrix_1.entries[2][2] = 9;

    for (int row = 0; row < matrix_1.rows; row++) {
        for (int col = 0; col < matrix_1.columns; col++) {
            std::cout << matrix_1.entries[row][col] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<RealLinear::Vector> toPlace = {vector_1*2, vector_2*2, vector_3*2};
    RealLinear::Matrix matrix_2(toPlace);

    RealLinear::Matrix matrix_3(3,3);

    matrix_3 = matrix_1 + matrix_2;

    RealLinear::Matrix identity(3,3);

    for (int row = 0; row < matrix_3.rows; row++) {
        for (int col = 0; col < matrix_3.columns; col++) {
            std::cout << matrix_3[row][col] << " ";
        }
        std::cout << std::endl;
    }

    RealLinear::Matrix I(3,3);

    for (int row = 0; row < matrix_3.rows; row++) {
        for (int col = 0; col < matrix_3.columns; col++) {
            if (row == col)
                I[row][col] = 1;
        }
    }

    RealLinear::Vector product = I * vector_1;

    RealLinear::Matrix matrix_4(3,3);
    matrix_4.entries[0][0] = 11;
    matrix_4.entries[0][1] = 12;
    matrix_4.entries[0][2] = 13;
    matrix_4.entries[1][0] = 14;
    matrix_4.entries[1][1] = 15;
    matrix_4.entries[1][2] = 16;
    matrix_4.entries[2][0] = 17;
    matrix_4.entries[2][1] = 18;
    matrix_4.entries[2][2] = 19;

    RealLinear::Matrix matrix_5 = matrix_4 * matrix_1;

    std::cout << matrix_5.string();

    return 0;
}