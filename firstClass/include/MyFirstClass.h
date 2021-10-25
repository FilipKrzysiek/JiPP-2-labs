//
// Created by filip on 25.10.2021.
//

#ifndef JIPP_2_LABS_MYFIRSTCLASS_H
#define JIPP_2_LABS_MYFIRSTCLASS_H

#include <iostream>

using namespace std;

class MyFirstClass {
private:
    string firstName;
    string secondName;
    string question = "No question";
    string answear;
    short points;

    void readAnswear();

public:
    MyFirstClass(string firstName, string secondName, string question, short points);

    void printQuestion();

    void askUser();

    string getQuestion();

    void setPoints(short points);
};


#endif //JIPP_2_LABS_MYFIRSTCLASS_H
