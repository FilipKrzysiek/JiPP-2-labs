//
// Created by filip on 31.10.2021.
//
#pragma once
#include "Figure.h"

class Circle: public Figure {
private:
    double r;
public:
    Circle(double r, string name);

    double getArea();
};

