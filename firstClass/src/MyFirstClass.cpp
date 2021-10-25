//
// Created by filip on 25.10.2021.
//

#include "../include/MyFirstClass.h"

void MyFirstClass::readAnswear() {
    cin>> answear;
}

void MyFirstClass::printQuestion() {
    cout << question << endl;
}

void MyFirstClass::askUser() {
    printQuestion();
    readAnswear();
}

MyFirstClass::MyFirstClass(string firstName, string secondName, string question, short points)
: secondName(secondName), question(question), points(points)
{
    this->firstName = firstName;
}

string MyFirstClass::getQuestion() {
    return question;
}

void MyFirstClass::setPoints(short points) {
    this->points = points;
}
