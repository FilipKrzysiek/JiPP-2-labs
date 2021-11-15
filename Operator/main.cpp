//
// Created by Filip on 15.11.2021.
//

#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    Vector v1(0,5), v2(5,4);

    Vector v3 = v1 + v2;

    Vector v4 = v1 + 100;
    Vector v5 = 100 + v1;
    Vector v6 = !v1;

    print(v1);
    print(v2);
    print(v3);
    print(v4);
    print(v5);
    print(v6);
}

