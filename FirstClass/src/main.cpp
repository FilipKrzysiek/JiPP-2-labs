//
// Created by filip on 26.10.2021.
//

#include <iostream>

#include "FirstClass.h"

using namespace std;

int main() {
    FirstClass book("C++ dla opornych", "Nikt", 100, 95);

    book.printAllData();

    book.setRented(90);

    book.printAllData();

    cout << book.getRented() <<endl;

    return 0;
}

