//
// Created by Filip on 05.12.2021.
//

#ifndef JIPP_2_LABS_STOP_H
#define JIPP_2_LABS_STOP_H

#include <iostream>

using namespace std;

class Stop {
private:
    long id;
    string name;
    double latitude;
    double longitude;

public:
    Stop(long id, const string &name, double latitude, double longitude);

    Stop() {};

    void print();
};


#endif //JIPP_2_LABS_STOP_H
