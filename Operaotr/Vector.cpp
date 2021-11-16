//
// Created by Filip on 16.11.2021.
//

#include "Vector.h"

void print(const Vector &vector) {
    cout << vector.x << ", " << vector.y << endl;
}

Vector operator+(const double &lhs, const Vector &rhs) {
    return Vector(lhs + rhs.x, lhs + rhs.y);
}

Vector::Vector() : x(0), y(0) {}

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::length() {
    return sqrt(x * x + y * y);
}

Vector Vector::operator+(const Vector &rhs) {
    return Vector(x + rhs.x, y + rhs.y);
}

Vector Vector::operator+(const double &rhs) {
    return Vector(x + rhs, y + rhs);
}
