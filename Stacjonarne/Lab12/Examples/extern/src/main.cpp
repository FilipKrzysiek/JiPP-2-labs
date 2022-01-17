#include <iostream>
#include "functions.h"

using namespace std;


int number;

int main() {
    number = 0;
    cout << number << endl;
    cout << "Call function" << endl << endl;
    incrementNumber();
    printNumber();
    cout << "In main: " << number << endl << endl;

    cout << "Call function" << endl ;
    incrementNumber();
    printNumber();
    cout << "In main: " << number << endl << endl;

    cout << "Add 100 to number in main" << endl;
    number += 100;
    printNumber();
    cout << "In main: " << number << endl << endl;

    cout << "Call function" << endl ;
    incrementNumber();
    printNumber();
    cout << "In main: " << number << endl << endl;


    return 0;
 }