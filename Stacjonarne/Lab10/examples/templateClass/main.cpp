//
// Created by filip on 20.12.2021.
//

#include <iostream>
#include "Triple.h"

using namespace std;

Triple<string, string, double> functionReturningMoreThanOneThing();



int main() {
//    Triple t1{"Hello", 5.1, true};   - To nie zadziała, ponieważ nie jesteśmy w stanie wydedukować jakiego typu będą parametry
    Triple <string, double, bool>t{"Hello", 5.1, true};
    cout << t.getVariable1() << endl;
    cout << t.getVariable2() << endl;
    cout << t.getVariable3() << endl;

    return 0;
}

Triple<string, string, double> functionReturningMoreThanOneThing() {
    return {"Hey", "its OK", 52};
}

