//
// Created by filip on 25.10.2021.
//

#include "../include/FirstClass.h"

FirstClass::FirstClass(string productName, unsigned int price, unsigned int weight, unsigned int amount):
price(price), weight(weight), amount(amount){
    this->productName = productName;
}

void FirstClass::showBasicData() {
    cout << productName << " " << price << " gr" << endl;
}

void FirstClass::showDetails() {
    cout << weight << " kg, " << amount << " pcs." <<endl;
}

void FirstClass::showAllData() {
    showBasicData();
    showDetails();
}

void FirstClass::setPrice(unsigned int price) {
    this->price = price;
}

unsigned int FirstClass::getPrice() {
    return price;
}