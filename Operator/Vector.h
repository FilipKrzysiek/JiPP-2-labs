//
// Created by Filip on 15.11.2021.
//

#ifndef JIPP2_VECTOR_H
#define JIPP2_VECTOR_H

#include <math.h>
#include <iostream>

using namespace std;


class Vector{
private:
    double x = 0, y = 0;

public:
    Vector() {};

    Vector(double x, double y) : x(x), y(y) {}

    double length();

    Vector operator+(const Vector &rhs);

    Vector operator+(const double &rhs);

    friend void print(const Vector &vector);
    friend Vector operator+(const double &lhs, const Vector& rhs);
};


#endif //JIPP2_VECTOR_H
