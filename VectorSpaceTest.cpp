//
// Created by Joshua Cidron on 2/2/24.
//

#include "VectorSpaceTest.h"
#include "LinearAlgebra.cpp"

int main (){
    LinearAlgebra::Vector v1({1,2,3,4,5,6,7,8,9,10});
    LinearAlgebra::Vector v2({1,2,3,4,5,6,7,8,9,10});
    LinearAlgebra::Vector v3({1,2,3,4,5,6,7,8,9,10});

    v1 *= 1;
    v2 *= 2;
    v3 *= 3;

    LinearAlgebra::Vector test1(v1 + v2);
    LinearAlgebra::Vector test2(v2 + v1);

    LinearAlgebra::Vector test3((v1 + v2) +  v3);
    LinearAlgebra::Vector test4(v1 + (v2 + v3));

    LinearAlgebra::Vector test5(10);
    LinearAlgebra::Vector test6(v1 + test5);

    LinearAlgebra::Vector test7(v1 * -1);
    LinearAlgebra::Vector test8(v1 + test7);
    LinearAlgebra::Vector test9(test7 + v1);
    LinearAlgebra::Vector test10(10);

    LinearAlgebra::Vector test11(v1 * 1);

    LinearAlgebra::Vector test12((2*3)*v1);
    LinearAlgebra::Vector test13((2)*(3*v1));

    LinearAlgebra::Vector test14(2 * (v1 + v2));
    LinearAlgebra::Vector test15((2 * v1) + (2 * v2));

    LinearAlgebra::Vector test16((2+3) * v1);
    LinearAlgebra::Vector test17((2*v1) + (3*v1));

    bool A1 = (test1 == test2);
    bool A2 = (test3 == test4);
    bool A3 = (v1 == test6);
    bool A4 = ((test8 == test9) && (test9 == test10) && (test8 == test10));
    bool A5 = (v1 == test11);
    bool A6 = (test12 == test13);
    bool A7 = (test14 == test15);
    bool A8 = (test14 == test15);

    std::cout << A1 << std::endl;
    std::cout << A2 << std::endl;
    std::cout << A3 << std::endl;
    std::cout << A4 << std::endl;
    std::cout << A5 << std::endl;
    std::cout << A6 << std::endl;
    std::cout << A7 << std::endl;
    std::cout << A8 << std::endl;
}