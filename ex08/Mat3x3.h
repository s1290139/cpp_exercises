#ifndef MAT3X3_H
#define MAT3X3_H

#include <iostream>

class Mat3x3 {
public:
    Mat3x3();  // Default constructor
    Mat3x3(float data[9]);  // Constructor with data
    Mat3x3 operator+(const Mat3x3& other) const;
    Mat3x3 operator-(const Mat3x3& other) const;
    Mat3x3 operator*(const Mat3x3& other) const;
    Mat3x3& operator+=(const Mat3x3& other);
    Mat3x3& operator-=(const Mat3x3& other);
    Mat3x3& operator*=(const Mat3x3& other);
    Mat3x3 operator-() const;
    float operator()(int i, int j) const;
    bool operator==(const Mat3x3& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Mat3x3& matrix);

private:
    float data[9];
};

#endif
