//
// Created by filip on 26.10.2021.
//

#ifndef JIPP_2_LABS_FIRSTCLASS_H
#define JIPP_2_LABS_FIRSTCLASS_H

#include <iostream>

using namespace std;

class FirstClass {
private:
    string title;
    string author;
    short amount = 0;
    short rented = 0;

    void printDetails();

public:
    FirstClass(string title, string author, short amount, short rented);

    void printBaseInformation();
    void printAllData();

    void setRented(short rented);

    short getRented();
};


#endif //JIPP_2_LABS_FIRSTCLASS_H
