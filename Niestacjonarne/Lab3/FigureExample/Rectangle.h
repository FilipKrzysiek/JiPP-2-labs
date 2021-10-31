//
// Created by filip on 31.10.2021.
//
#pragma once

#include "Figure.h"

class Rectangle: public Figure{
private:
    double a, b;

public:
    Rectangle(double a, double b, string name);

    double getArea();

};

