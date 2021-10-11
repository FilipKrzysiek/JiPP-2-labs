//
// Created by Filip on 11.10.2021.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    int l = stoi(argv[2]);
    cout << l <<endl;

    int *n;
    n = new int;
    int k;
    cout << n << endl << *n << endl << &n << endl << &k << endl;

    delete n;

    int *tab = new int[5];
    delete[] tab;

    int **tab2 = new int *[5];

    for (int i = 0; i < 5; ++i) {
        tab2[i] = new int[5];
    }

    int tab3[3] = {3, 2, 1};

    tab3[1] = 3 ;
    tab3[2] = 201;

    return 0;
}

