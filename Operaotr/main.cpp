//
// Created by Filip on 16.11.2021.
//

#include "Vector.h"

int main() {
    Vector v1, v2(5,3);

    print(v1);
    print(v2);

    Vector v3 = v2 + v2;
    print(v3);

    Vector v4 = v3 + 10;
    Vector v5 = 10 + v3;
    print(v4);
    print(v5);
    return 0;
}

