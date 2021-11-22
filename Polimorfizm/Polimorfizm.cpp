//
// Created by Filip on 22.11.2021.
//

//
// Created by Filip on 22.11.2021.
//

#include <iostream>

using namespace std;

class Product {
protected:
    string name;
    unsigned price;
    string idNumber;

public:
    Product(const string &name, unsigned int price, const string &idNumber) : name(name), price(price),
                                                                              idNumber(idNumber) {}

    Product() {}

    virtual void printAllData() = 0;
};

class Owoc : public Product {
protected:
    string country;
    string date;
    string family;

public:
    Owoc(const string &name, unsigned int price, const string &idNumber, const string &country, const string &date,
         const string &family) : Product(name, price, idNumber), country(country), date(date), family(family) {}

    void printAllData() {
        cout << "all owoc data" <<  endl;
    }

};

class Phone : public Product {
protected:
    string marka;
    string color;
    unsigned short przekatna;

public:
    Phone(const string &name, unsigned int price, const string &idNumber, const string &marka, const string &color,
          unsigned short przekatna) : Product(name, price, idNumber), marka(marka), color(color),
                                      przekatna(przekatna) {}

    void printAllData() {
        cout << "all phone data" << endl;
    }
};


int main() {
//    Product p1("Nothing", 1000, "001");
    Owoc o1("Mandarynka", 120, "002", "Hiszpania", "2021-01-01", "cytrusy");
    Phone ph1("Telefon", 1000000, "003", "telefon", "black", 621);

    Product *list[10];
    list[0] = new Owoc("Mandarynka", 120, "002", "Hiszpania", "2021-01-01", "cytrusy");
    list[1] = new Phone("Telefon", 1000000, "003", "telefon", "black", 621);

    list[0]->printAllData();
    list[1]->printAllData();

    return 0;
}





