//
// Created by Filip on 15.11.2021.
//

#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    Vector v1, v2(2,5);

    Vector v3 = v1 + v2;

    Vector v4 = v1 + 5;
    Vector v5 = 5 + v1;
    print(v5);
    print(v4);
    print(v3);




    return 0;
}