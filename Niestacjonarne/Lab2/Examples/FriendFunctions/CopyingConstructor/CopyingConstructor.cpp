// CopyingConstructor.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Node.h"
#include "Triangle.h"

using namespace std;

int main() {
    Node n1(83, 5);
    n1.addNewValue(80);
    n1.addNewValue(85.1);
    n1.addNewValue(603.945);

    Node n1_1 = n1;

    cout << "n1" << endl;
    n1.display();
    n1.printValues();

    cout << "n1_1" << endl;
    n1_1.display();
    n1_1.printValues();

    n1.changeValueOn(0, 0);
    n1.changeValueOn(1, 1);
    n1.changeValueOn(1, 2);

    cout << "n1" << endl;
    n1.display();
    n1.printValues();

    cout << "n1_1" << endl;
    n1_1.display();
    n1_1.printValues();

    system("PAUSE");

    Node a, b(5, 8), c(1, 16);
    Triangle triangle(a, b, c, "First Triangle");

    cout << "Distance between first and second point is " << triangle.distance(0, 1) << endl;

    system("PAUSE");

    showTriangleData(triangle);
    showTriangleData(&triangle);

    system("PAUSE");
    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
