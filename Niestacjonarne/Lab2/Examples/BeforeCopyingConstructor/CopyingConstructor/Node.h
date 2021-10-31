#pragma once
#include <iostream>

using namespace std;

class Node {
private:
    double x, y;
    double* array;
    size_t size = 0;

public:
    Node();
    Node(double x, double y);

    ~Node();

    void display();

    void updateValue(double x, double y);

    void addNewValue(double n);

    void printValues();

    void changeValueOn(double newValue, int indx);
};

