#include <iostream>
#include "Mat3x3.h"

int main() {
    float data1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float data2[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    Mat3x3 A(data1);
    Mat3x3 B(data2);
    Mat3x3 C = A + B;
    Mat3x3 D = A - B;

    std::cout << "A:\n" << A;
    std::cout << "B:\n" << B;
    std::cout << "A + B:\n" << C;
    std::cout << "A - B:\n" << D;

    return 0;
}
