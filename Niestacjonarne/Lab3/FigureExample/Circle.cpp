//
// Created by filip on 31.10.2021.
//

#include "Circle.h"

Circle::Circle(double r, string name): r(r) {
    this->name = name;
}

double Circle::getArea() {
    return 3.14 * r * r;
}
