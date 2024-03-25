//
// Created by Joshua Cidron on 2/2/24.
//
#include "../Vector/Vector.cpp"
#include <cassert>


//Class Methods
//RealLinear::Vector v1({1,2,3,4,5,6,7,8,9,10});
//RealLinear::Vector v2({1,2,3,4,5,6,7,8,9,10});
//RealLinear::Vector v3({1,2,3,4,5,6,7,8,9,10});

//void testVectorBrackets () {
//    for (int i = 1; i <= 10; i++) {
//        assert(i == v1[i]);
//    }
//}

//void testEquals () {
//    assert(v1 == v2);
//    assert(v1 == v3);
//    assert(v2 == v3);
//    v2[0] = v2[0] + 1;
//    assert(v1 != v2);
//    assert(v2 != v3);
//    for (int i = 0; i < 10; i++) {
//        v1[i] = v1[i] * 2;
//    }
//    assert(v1 != v3);
//}



////Vector Space Properties
//void testCommunativeAddition () {
//    v1 *= 1;
//    v2 *= 2;
//
//    RealLinear::Vector test1(v1 + v2);
//    RealLinear::Vector test2(v2 + v1);
//
//    assert(test1 == test2);
//}

//void testAssociativeAddition () {
//    v1 *= 1;
//    v2 *= 2;
//    v3 *= 3;
//
//    RealLinear::Vector test1(v1 + v2);
//    RealLinear::Vector test2(v2 + v1);
//
//    assert(test1 == test2);
//}
//
//int main (){
//    testVectorBrackets();
//}

//v1 *= 1;
//    v2 *= 2;
//    v3 *= 3;
//
//    RealLinear::Vector test1(v1 + v2);
//    RealLinear::Vector test2(v2 + v1);
//
//    RealLinear::Vector test3((v1 + v2) +  v3);
//    RealLinear::Vector test4(v1 + (v2 + v3));
//
//    RealLinear::Vector test5(10);
//    RealLinear::Vector test6(v1 + test5);
//
//    RealLinear::Vector test7(v1 * -1.0);
//    RealLinear::Vector test8(v1 + test7);
//    RealLinear::Vector test9(test7 + v1);
//    RealLinear::Vector test10(10);
//
//    RealLinear::Vector test11(v1 * 1.0);
//
//    RealLinear::Vector test12((2*3)*v1);
//    RealLinear::Vector test13((2)*(3*v1));
//
//    RealLinear::Vector test14(2 * (v1 + v2));
//    RealLinear::Vector test15((2 * v1) + (2 * v2));
//
//    RealLinear::Vector test16((2+3) * v1);
//    RealLinear::Vector test17((2*v1) + (3*v1));
//
//    bool A1 = (test1 == test2);
//    bool A2 = (test3 == test4);
//    bool A3 = (v1 == test6);
//    bool A4 = ((test8 == test9) && (test9 == test10) && (test8 == test10));
//    bool A5 = (v1 == test11);
//    bool A6 = (test12 == test13);
//    bool A7 = (test14 == test15);
//    bool A8 = (test14 == test15);
//
//    std::cout << A1 << std::endl;
//    std::cout << A2 << std::endl;
//    std::cout << A3 << std::endl;
//    std::cout << A4 << std::endl;
//    std::cout << A5 << std::endl;
//    std::cout << A6 << std::endl;
//    std::cout << A7 << std::endl;
//    std::cout << A8 << std::endl;