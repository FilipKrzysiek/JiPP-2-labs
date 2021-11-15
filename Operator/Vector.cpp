//
// Created by Filip on 15.11.2021.
//

#include "Vector.h"

void print(const Vector &vector) {
    cout << vector.x << ", " << vector.y << endl;
}

Vector operator+(const double &lhs, const Vector& rhs) {
    Vector res(lhs + rhs.x, lhs + rhs.y);
    return res;
}

double Vector::length() {
    return sqrt(x * x + y * y);
}

Vector Vector::operator+(const Vector &rhs) {
    Vector res(x + rhs.x, y + rhs.y);
    return res;
}

Vector Vector::operator+(const double &rhs) {
    Vector res(x + rhs, y + rhs);
    return res;
}

Vector Vector::operator!() {
    return Vector(-1 * x, -1 * y);
}
