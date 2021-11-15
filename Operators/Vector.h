//
// Created by Filip on 15.11.2021.
//

#ifndef JIPP2_VECTOR_H
#define JIPP2_VECTOR_H

#include <iostream>
#include <math.h>

using namespace std;

class Vector{
private:
    double x, y;

public:
    Vector() {};

    Vector(double x, double y) : x(x), y(y) {}

    double length() {
        return sqrt(x * x + y * y);
    }

    Vector operator+(const Vector &vector) {
        Vector ret(x + vector.x, y + vector.y);
        return ret;
    }

    Vector operator+(const double &con) {
        Vector ret(x + con, y + con);
        return ret;
    }

    friend void print(Vector &vector);

    friend Vector operator+(const double& lhs, const Vector & rhs);
};

void print(Vector &vector) {
    cout << vector.x << " " << vector.y <<endl;
}

Vector operator+(const double& lhs, const Vector & rhs) {
    Vector vect(lhs + rhs.x, lhs + rhs.y);
    return vect;
}


#endif //JIPP2_VECTOR_H
