//
// Created by filip on 31.10.2021.
//

#include "Rectangle.h"

Rectangle::Rectangle(double a, double b, string name) : a(a), b(b) {
    this->name = name;
}

double Rectangle::getArea() {
    return a * b;
}
