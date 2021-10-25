//
// Created by filip on 25.10.2021.
//

#include <iostream>
#include "../include/FirstClass.h"

using namespace std;

int main() {
    FirstClass product("Pass exam", 100000000, 1000, 0);

    product.showAllData();

    product.setPrice(2000000000);

    product.showAllData();

    cout << product.getPrice() << endl;
    return 0;
}