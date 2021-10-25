//
// Created by filip on 25.10.2021.
//
#include "FirstClass.h"
#include <iostream>

using namespace std;

int main() {
    FirstClass person("Jan", "Kowalski", 44, 136);

    person.printAllData();
    person.setTall(140);

    person.printAllData();
    cout << person.getFootSize() <<endl;

    return 0;
}

