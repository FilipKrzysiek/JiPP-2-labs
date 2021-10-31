//
// Created by filip on 31.10.2021.
//
#pragma once
#include <iostream>

using namespace std;

class Figure {
protected:
    string name;
public:
    virtual double getArea() = 0;
};

