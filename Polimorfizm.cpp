//
// Created by Filip on 30.11.2021.
//

#include <iostream>

using namespace std;

class Vehicle {
protected:
    unsigned short amountOfWheels;

public:
    Vehicle(unsigned short amountOfWheels) : amountOfWheels(amountOfWheels) {

    }

    unsigned short getAmountOfWheels() const {
        return amountOfWheels;
    }

    virtual void printAllData () = 0;
};

class Car: public Vehicle {
protected:
    unsigned short amountOfDoors;

public:
    Car(unsigned short amountOfWheels, unsigned short amountOfDoors) : Vehicle(amountOfWheels),

                                                                       amountOfDoors(amountOfDoors) {}
    void printAllData () {
        cout << "Im Car" << endl;
    }

    void run() {
        cout << "run " << endl;
    }

    void breaking() {
        cout << "Break" << endl;
    }
};

class Motor: public Vehicle {
protected:
    double engineVolume;

public:
    Motor(unsigned short amountOfWheels, double engineVolume) : Vehicle(amountOfWheels), engineVolume(engineVolume) {}

    void printAllData () {
        cout << "Im Motor" << endl;
    }

};

class Task {
public:
    virtual void run() = 0;
};

class TaskFunction: public Task {
private:
    void (*function)();

public:
    void run() {
        function();
    }
};

class TaskTemplateClass {
public:
    virtual void execute() = 0;
};

class TaskClass: public Task {
private:
    TaskTemplateClass *taskClass;

public:
    void run() {
        taskClass->execute();
    }
};



int main() {
//    Vehicle v(2);
//
//    Car c1(4, 5);
//
//    v.printAllData();
//    c1.printAllData();

    Vehicle *v = new Car(5,5);
    Vehicle *v1 = new Motor(5,5);

    Vehicle *vTab[5];
    vTab[0] = new Car(6,6);
    vTab[1] = new Motor(6,6);


    Task *tasks[10];
    //Dodawanie tasków
    tasks[0] = new TaskFunction ...;
    tasks[1] = new TaskClass ... ;
    for(int i = 0; i < 10; ++i) {
        tasks[i]->run();
    }
    return 0;
}

