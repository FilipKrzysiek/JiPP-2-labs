//
// Created by filip on 03.01.2022.
//

#include <iostream>
#include "TaskClass.h"
#include "TaskFunction.h"
#include <vector>

using namespace std;

void funct() {

}

class MyJob: public TaskClassTemplate {
    //jakieś zmienne

    //jakieś metody

    //Metoda, która robi całą robotę
    void doJob();

    void execute() {
        doJob();
    }
};

int main() {
    Task *task = new TaskClass(5, new MyJob());

    vector<Task *> tasksList;
    tasksList.push_back(new TaskFunction(5, *funct));
    tasksList.push_back(new TaskClass(5, new MyJob()));

    return 0;
}