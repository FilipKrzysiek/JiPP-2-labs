#include "Student.h"

Student::Student(const string& firstName, const string& lastName): firstName(firstName), lastName(lastName) {}

Student::Student() {}

void Student::setNames(const string& firstName, const string& lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
}

void Student::changeTabValue(unsigned index, double newValue) {
    if (index < 5) {
        tab[index] = newValue;
    }
}

void Student::addGrade(unsigned short grade) {
    gradesList.push_back(grade);
}

void Student::printAllData() {
    cout << firstName << " " << lastName << endl;
    for (double n : tab) {
        cout << n << " ";
    }

    cout << endl << endl << "Grades list:" << endl;

    for (auto grade : gradesList) {
        cout << grade / 10 << "." << grade % 10 << endl;
    }
}
