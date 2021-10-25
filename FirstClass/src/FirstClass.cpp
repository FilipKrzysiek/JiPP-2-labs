//
// Created by filip on 25.10.2021.
//

#include "FirstClass.h"

void FirstClass::printName() {
    cout << firstName << " " << lastName << endl;
}

void FirstClass::printSizeData() {
    cout << "Foot size:" << footSize <<endl;
    cout << "Tall: " << tall << endl;
}

void FirstClass::printAllData() {
    printName();
    printSizeData();
}

FirstClass::FirstClass(string firstName, string lastName, unsigned short footSize, unsigned short tall)
: lastName(lastName), footSize(footSize), tall(tall){
    this->firstName = firstName;
}

void FirstClass::setTall(unsigned short tall) {
    this->tall = tall;
}

unsigned short FirstClass::getFootSize() {
    return footSize;
}
