//
// Created by filip on 07.01.2022.
//

#include <iostream>
#include <cstring>
#include "windows.h"
#include <tchar.h>

using namespace std;

static int count_alloc = 0;  //licznik - ile razy była alokowana pamięć

class A {
    char *str;
public:
    A(char *sstr);

    ~A();

    friend ostream &operator<<(ostream &strm, const A &ob);
};

A::A(char *sstr) {
    try {
        str = new char[128];
        count_alloc++;
        memset(str, 0, _msize(str));
        strcpy_s(str, _msize(str), sstr);
    }
    catch (bad_alloc) {
        cerr << "error: bad_alloc";
    }
}

A::~A() {
    cout << "~A(): " << str << "\n";
    if (str)
        delete[] str;
    count_alloc--;
    str = NULL;
}

ostream &operator<<(ostream &strm, const A &ob) {
    strm << "   " << ob.str << endl;
    return strm;
}

class B {
protected:
    A ob_AB;
public:
    B(char *sstr) : ob_AB(sstr) {}

    ~B();

    virtual void disp() { cout << typeid(*this).name() << ob_AB; }
};

B::~B() {
    cout << "~B()\n";
}


class D : public B {
protected:
    A ob_AD;
public:
    D(char *sstr1, char *sstr2) : B(sstr1), ob_AD(sstr2) {};

    ~D();

    virtual void disp() { cout << typeid(*this).name() << ob_AD << endl; }
};


D::~D() {
    cout << "~D()\n";
}

int _tmain(int argc, _TCHAR *argv[]) {
    B *ptr_BB = NULL;
    try {
        B *ptr_B = new B("base_bbb");
        D *ptr_D = new D("bbb", "dedede"); //powstaje obiekt klasy pochodnej
        count_alloc += 2;
        ptr_BB = ptr_B;
        ptr_BB->disp();
        ptr_BB = ptr_D;                     //wskaźnik klasy bazowej wskazuje do obiektu klasy pochodnej
        cout << "Typ dla B: " << typeid(*ptr_BB).name() << endl;
        ptr_BB->disp();
        delete ptr_BB;                     //jakie destruktory będą wywołane ?
        ptr_BB = ptr_B;                     //wskaźnik klasy bazowej wskazuje do obiektu klasy bazowej
        cout << "Typ dla D: " << typeid(*ptr_BB).name() << endl;

        delete ptr_BB;                     //jakie destruktory będą wywołane ?
        count_alloc -= 2;
        if (count_alloc)
            cout << "error: leak of memory !!!!!!!!!!!!!!!!!!!! \n";
    }
    catch (bad_alloc) {
        cerr << "error: bad_alloc";
    }

    system("pause");
    return 0;
}
