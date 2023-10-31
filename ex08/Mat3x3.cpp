#include "Mat3x3.h"

Mat3x3::Mat3x3() {
    // Initialize as the identity matrix
    for (int i = 0; i < 9; i++) {
        data[i] = (i % 4 == 0) ? 1.0f : 0.0f;
    }
}

Mat3x3::Mat3x3(float matrixData[9]) {
    for (int i = 0; i < 9; i++) {
        data[i] = matrixData[i];
    }
}

Mat3x3 Mat3x3::operator+(const Mat3x3& other) const {
    Mat3x3 result;
    for (int i = 0; i < 9; i++) {
        result.data[i] = this->data[i] + other.data[i];
    }
    return result;
}

Mat3x3 Mat3x3::operator-(const Mat3x3& other) const {
    Mat3x3 result;
    for (int i = 0; i < 9; i++) {
        result.data[i] = this->data[i] - other.data[i];
    }
    return result;
}

Mat3x3 Mat3x3::operator*(const Mat3x3& other) const {
    Mat3x3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.data[i * 3 + j] = 0;
            for (int k = 0; k < 3; k++) {
                result.data[i * 3 + j] += this->data[i * 3 + k] * other.data[k * 3 + j];
            }
        }
    }
    return result;
}

Mat3x3& Mat3x3::operator+=(const Mat3x3& other) {
    for (int i = 0; i < 9; i++) {
        this->data[i] += other.data[i];
    }
    return *this;
}

Mat3x3& Mat3x3::operator-=(const Mat3x3& other) {
    for (int i = 0; i < 9; i++) {
        this->data[i] -= other.data[i];
    }
    return *this;
}

Mat3x3& Mat3x3::operator*=(const Mat3x3& other) {
    *this = *this * other;
    return *this;
}

Mat3x3 Mat3x3::operator-() const {
    Mat3x3 result;
    for (int i = 0; i < 9; i++) {
        result.data[i] = -this->data[i];
    }
    return result;
}

float Mat3x3::operator()(int i, int j) const {
    return this->data[i * 3 + j];
}

bool Mat3x3::operator==(const Mat3x3& other) const {
    for (int i = 0; i < 9; i++) {
        if (std::abs(this->data[i] - other.data[i]) > 1e-6) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Mat3x3& matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            os << matrix(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}
