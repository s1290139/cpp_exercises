#include <iostream>
#include "Mat3x3.h"

int main() {
    float data1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};//A
    float data2[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};//B
    float data3[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};//F
    float data4[9] = {9, 9, 9, 9, 9, 9, 9, 9, 9};//G
    float data5[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};//H

    Mat3x3 A(data1);
    Mat3x3 B(data2);
    Mat3x3 F(data3);
    Mat3x3 G(data4);
    Mat3x3 H(data5);
    Mat3x3 C = A + B;
    Mat3x3 D = A - B;
    Mat3x3 E = A * B;

    std::cout << "A:\n" << A<<std::endl;
    std::cout << "B:\n" << B<<std::endl;
    std::cout << "F:\n" << F<<std::endl;
    std::cout << "G:\n" << G<<std::endl;
    std::cout << "H:\n" << H<<std::endl;

    std::cout << "A + B:\n" << C<<std::endl;
    std::cout << "A - B:\n" << D<<std::endl;
    std::cout << "A * B:\n" << E<<std::endl;
    F += B;
    std::cout << "F += B:\n" << F<<std::endl;
    G -= H;
    std::cout << "G -= H:\n" << G<<std::endl;
    G *= H;
    std::cout << "G *= H:\n" << G<<std::endl;

    if(B==A){
        std::cout<<"B==A correct"<<std::endl;
    }else{
        std::cout<<"B==A not correct"<<std::endl;
    }

    return 0;
}
