# Laboratorium 12 (17.01.2022/24.01.2022)




## 1. Typ wyliczeniowy


&nbsp;

&nbsp;

## 2. Wielowątkowość

Dotychczas wszystkie tworzone przez nasz aplikacje były jednowątkowe, jedno zadanie było wykonywane w tym samym czasie.
C++ ma wbudowana wielowątkowość i stosunkowo łatwo ją używać, wystarczy załączyć bibliotekę `thread` i przypisać zadanie do wątku.

```c++
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void function() {
    cout << "I'm very slow function" << endl;
    this_thread::sleep_for(chrono::seconds(10));
    cout << "Ohhh, this is very hard work" << endl;
}

int main()
{
    //Funkcja wywolana bez wielowątkowości
    function();
    cout << "I try do this in the same time!" << endl;
    
    cout << endl << endl << endl;
    
    //funkcja wywołana w wnowym atku
    thread th(function);
    cout << "I try do this in the same time!" << endl;
    th.join();
    
    cout << "end" <<endl;

    return 0;
}
```

Stworzona została funkcja, która „działa” bardzo powoli (no wiem, że śpi, ale jakoś musimy to symulować), a zaraz pod nią zostało wywołane wypisanie na ekranie. W pierwszym wypadku wykonało się wszystko sekwencyjnie, a w drugim jednocześnie.

- `thread th(function)` - tworzenie i uruchamianie funkcji function w nowym wątku
- `th.join()` - oczekiwanie na zakończenie działania wątku `th`

&nbsp;

### Deklarowanie nowego wątku

Jak zapewne zauważyłeś w przykładzie, deklaracja wątku jako pierwszy argument przyjmuje nazwę funkcji, która ma zostać uruchomiona w nowym wątku. Co, jeżeli nasza funkcja przyjmuje jakieś argumenty? Przekazujemy je jako kolejne argumenty przy tworzeniu wątku:

```c++
void function1(string text, unsigned short times) {
    for(int i = 0; i < times; ++i) {
        cout << i << ". " << text << endl;
    }
}

int main() {
    cout << "The best people ranking:" << endl;
    thread th(function1, "me", 10);
    th.join();
}
```

&nbsp;

### Co z wątkami w klasach?

Używanie metody klasy jako zadania do wykonania w nowym wątku jest nieco bardziej skomplikowane, ponieważ nie wystarczy przekazać tylko nazwy funkcji. Należy przekazać nazwę obiektu, a jako kolejny parametr obiekt, na którym ma być to wywołane:

```c++
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

class MyClass {
private:
    vector<vector<double>> matrix;
    
    double max;
    
    void findMaxInRow(size_t row) {
        for(auto &cell: matrix[row]) {
            if(max > cell) {
                max = cell;
            }
        }
    }
    
public:
    MyClass(unsigned short columns, unsigned short rows) {
        matrix.resize(rows);
        
        default_random_engine defEngine;
        uniform_real_distribution<double> intDistro(-2000,2000);
        
        for(auto &row: matrix) {
            row.resize(columns);
            
            for(auto &cell: row) {
                cell = intDistro(defEngine);
            }
        }
    }
    
    void printMatrix () {
        for(auto &row: matrix) {
            for(auto &cell: row) {
                cout << setw(10) << cell << "\t";
            }
            cout << endl;
        }
    }
    
    double findMax() {
        max = matrix[0][0];
        vector<thread> thTab;
        
        for(int i = 0; i < matrix.size(); ++i) {
            thTab.emplace_back(&MyClass::findMaxInRow, this, i);
        }
        
        for(int i = 0; i < matrix.size(); ++i) {
            thTab[i].join();
        }
        
        return max;
    }
    
};

int main() {
    MyClass mc(5,10);
    mc.printMatrix();
    
    cout << mc.findMax() << endl;
    return 0;
}
```

Czy powyższa funkcja działa dobrze?

&nbsp;

### Sekcja krytyczna

Są miejsca w kodzie, podczas działania wielowątkowego, które nie mogą się wykonywać równocześnie, ponieważ mogłoby to doprowadzić do błędów. Takie miejsca nazywamy sekcją krytyczną. Aby zabezpieczyć takie miejsce, należy użyć klasy, która działa na zasadzie semafora. `mutex` posiada 2 stany otwarty i zamknięty.

```c++
#include <mutex>

mutex criticalSection;

criticalSection.lock();
// cRITICAL SECTION CODE
criticalSection.unlock();
```

Powyższy kod zabezpiecza sekcję krytyczną przed tym, aby w jej środku mógł być tylko i wyłącznie jeden wątek.

&nbsp;

### Zadanie

1. Popraw przykład z wyszukiwanie maksimum.
2. Uruchom program [który znajduje się tutaj](Examples/Matrix) wielowątkow.

&nbsp;

&nbsp;

## 3. Debug, release

Tryb debug i release to różne konfiguracje do tworzenia projektu. Programiści zazwyczaj używają trybu debug do debugowania krok po kroku swojego projektu 
i wybierają tryb release dla ostatecznej kompilacji. 

Tryb debug oznacza, że uruchamiamy aplikację z dołączonym debugerem. Dzięki temu możemy korzystać z pełnego zestawu funkcji debugowania, 
które ułatwiają znajdowanie usterek w aplikacji. 

Tryb debugowania nie optymalizuje tworzonego pliku binarnego, ponieważ związek między kodem źródłowym a wygenerowanymi instrukcjami jest bardziej złożony. Pozwala to na dokładne ustawienie breakpointów. Konfiguracja debugowania programu jest kompilowana z pełnymi symbolicznymi informacjami debugowania, które pomagają debugerowi określić, gdzie się znajduje w kodzie źródłowym.





