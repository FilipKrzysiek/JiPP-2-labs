//
// Created by Filip on 15.11.2021.
//

#include "Vector.h"

int main() {
    Vector v1, v2(5,5);

    print(v1);
    Vector v3 = v1 + v2;
    print(v3);
    Vector v4 = v2 + 5;
    Vector v5 = 5 + v2;
    print(v4);
    print(v5);
}