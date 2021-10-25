//
// Created by filip on 25.10.2021.
//

#include <iostream>
#include "../include/MyFirstClass.h"

using namespace std;

int main() {
    MyFirstClass q1("Jan", "Kowalski", "Are you the best?", 0);

    q1.getQuestion();
    q1.setPoints(10);
    q1.askUser();

    return 0;
}

