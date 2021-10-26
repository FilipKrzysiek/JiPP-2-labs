//
// Created by filip on 26.10.2021.
//

#include "FirstClass.h"

FirstClass::FirstClass(string title, string author, short amount, short rented)
: author(author), amount(amount), rented(rented){
    this->title = title;
}

void FirstClass::printAllData() {
    printBaseInformation();
    printDetails();
}

void FirstClass::printBaseInformation() {
    cout << title << " " << author << endl;
}

void FirstClass::printDetails() {
    cout << rented << " of " << amount <<endl;
}

void FirstClass::setRented(short rented) {
    this->rented = rented;
}

short FirstClass::getRented() {
    return rented;
}
