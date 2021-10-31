//
// Created by filip on 31.10.2021.
//
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

int main() {
    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;
    system("PAUSE");
    return 0;
}

