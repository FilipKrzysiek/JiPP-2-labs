#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    double tab[5];
    string firstName;
    string lastName;
    vector<unsigned short> gradesList;

public:
    Student(const string& firstName, const string& lastName);

    Student();

    void setNames(const string& firstName, const string& lastName);

    void changeTabValue(unsigned index, double newValue);

    void addGrade(unsigned short grade);

    void printAllData();
};

