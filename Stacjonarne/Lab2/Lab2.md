# Laboratorium 2

Celem tego laboratorium jest dalsza powtórka języka c, dodatkowo będzie poruszona tematyka alokacji pamięci, 
tworzenia i używania bibliotek oraz przekazywania parametrów do funkcji main.

## Przygotowanie do pracy

1. Stwórz repozytorium `JiPP2` na GitHubie.
2. Dodaj prowadzącego do repozytorium.
3. Otwórz repozytorium w CLion.
4. W głównym folderze stwórz folder `allocation_basics`.
5. Przenieś do nowostworzonego folderu pliki `main.cpp` oraz `CMakeLists.txt`.

## CMake

Cytując wikipedię:

> CMake – wieloplatformowe narzędzie do automatycznego zarządzania procesem kompilacji programu. Jego główna cecha to niezależność od używanego kompilatora oraz platformy sprzętowej. CMake nie kompiluje programu samodzielnie, lecz tworzy pliki z regułami kompilacji dla konkretnego środowiska; przykładowo w systemie GNU/Linux będą to pliki Makefile, natomiast pod Windowsem — pliki projektu dla Microsoft Visual Studio.

Jak można wyczytać w powyższej definicji, CMake służy do automatycznego zarządzania procesem kompilacji. Zamieniając 
na polskie, na podstawie konfiguracji wywołuje odpowiednie komendy, których efektem jest kompilacja. Dołącza on 
biblioteki, a nawet potrafi pobierać je z githuba.

### Podstawowe komendy

Deklaracja minimalnej wersji CMake, która będzie używana:

```cmake
cmake_minimum_required(VERSION 3.16)
```

Ustawianie używanej wersji języka c++:

```cmake
set(CMAKE_CXX_STANDARD 17)
```

Deklaracja nazwy projektu:

```cmake
project(ProjectName)
```

Deklarowanie listy plików, które mają byc skompilowane, jako program:

```cmake
add_executable(ProjectName main.cpp)
```

Deklarowanie listy plików, które mają byc skompilowane, jako biblioteka:

```cmake
add_library(ProjectName STATIC main.cpp)
```

Deklarowanie używanych bibliotek przez nasz program:

```cmake
target_link_libraries(ProjectName pthread)
```

Deklarowanie folderu, który ma być przeszukiwany pod kątem plikow nagłówkowych (mówienie, gdzie znajdują się pliki 
nagłówkowe):

```cmake
include_directories(include)
```

Dodawanie podfolderów z kolejnymi częściami aplikacji (gdzie znajduje się kolejny plik `CMakeLists.txt`)

```cmake
add_subdirectory(sth)
```

#### Stałe

`${CMAKE_CURRENT_LIST_DIR}` - zwraca absolutną ścieżkę do folderu aktualnego pliku CMakeLists.txt

`${CMAKE_SOURCE_DIR}` - zwraca absolutną ścieżkę do najwyższego folderu, w którym znajduje się plik CMakeLists.txt.



### Przykładowy plik

```cmake
cmake_minimum_required(VERSION 3.16)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)

add_executable(HelloWorld main.cpp)

target_link_libraries(HelloWorld pthread)
```

Analizując powyższy plik, można zauważyć, że będzie kompilowany w standardzie c++20 plik `main.cpp` oraz dołączana 
będzie biblioteka pthread.

```cmake
cmake_minimum_required(VERSION 3.16)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(HelloWorld 
        src/main.cpp 
        src/HelloWorld.cpp)

target_link_libraries(HelloWorld pthread)
```

### Komendy cmake

Używając CLion lub innego narzędzia z interfejsem graficznym można wszystko wyklikać, lecz jeżeli chcielibyśmy 
zrobić to z poziomu konsoli, to musielibyśmy użyć następujących komend.

> Załóżmy, że znajdujemy się w głównym folderze plików i struktura plików jest następująca:
> ```
> .
> ├── CMakeLists.txt
> ├── include
> │   └── HelloWorld.h
> └── src
>     ├── HelloWorld.cpp
>     └── main.cpp
> ```

Najpierw tworzymy folder na wyniki pracy CMake i skompilowane pliki oraz wchodzimy do niego:

```console
mkdir build
cd build
```

Wywołujemy komendę, aby CMake utworzył konfiguracje projektu:

```console
cmake ..
```

Uruchamianie kompilacji projektu `HelloWorld`:

```console
make HelloWorld
```


### Dokumentacja CMake

[Dokumentacja CMake](https://cmake.org/cmake/help/latest/index.html)

[Tutorial CMake](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)

<div style="page-break-after: always;"></div>


## Alokacja pamięci
Do tej pory pisząc programy w których organizowałeś dane, byłeś zmuszany do określania górnej granicy danych, jakie może pomieścić Twój program. Takie ograniczanie bardzo często nie jest jednak komfortowe i skuteczną alternatywą jest tu dynamiczne zarządzanie pamięcią. W języku C do przydzielania i zwalniania pamięci służyły głównie funkcje malloc() i free(). Korzystanie z nich było i jest nadal bardzo popularne, jednak w C++ zostały one zastąpione operatorami new i delete.

### Dynamiczne przydzielenie pamięci
W języku C++ do przydzielania nowego bloku pamięci służy operator new. Jego składnia wygląda następująco:
```c++
wskaznik1 = new typ_zmiennej;
wskaznik2 = new typ_zmiennej[ ilosc_elementow_danego_typu ];
```

### Zwalnianie pamięci przydzielonej dynamicznie
Zwalnianie pamięci przydzielonej dynamicznie jest jeszcze prostsze od jej przydziału i służy do tego operator delete. Jeśli pamięć dla danych, na które wskazuje zmienna wskaznik została przydzielona bez parametru określającego ilość elementów w tablicy, to usuwana jest następującą składnią:

```c++
delete wskaznik;
```


Funkcji malloc() nie można stosować zamiennie z operatorem new.
Funkcji free() nie można stosować zamiennie z operatorem delete.
Zamiana operatora new na funkcję malloc() może spowodować nieprawidłowe funkcjonowanie programu - operator new wykonuje czynności, które przy użyciu funkcji malloc() trzeba wywołać ręcznie.
Jeśli dokonujesz zamiany funkcji malloc() na operator new, pamiętaj aby pozamieniać również funkcję free() na operator delete (lub delete[] w zależności od sytuacji).

W ramach ciekawostki warto ajrzeć tutaj:
https://en.cppreference.com/w/cpp/memory

Wskaźnik poprzedzony jest gwiazdką (*) i przechowuje adres pamięci (a nie wartość) zmiennej, na którą wskazuje. Deklarując wskaźnik postępujemy tak jak ze zwykłymi zmiennymi, jednak nazwę wskaźnika poprzedzamy gwiazdką.

```c++
int liczba; //zmienna liczbowa
int *wsk; //wskaźnik
```

Bardzo ważne jest aby nie korzystać ze wskaźnika który nie wskazuje na żadną zmienną! Prowadzi to zawsze do błędów i niesie ze sobą nieprzewidziane konsekwencje w działaniu programu. 

```c++
int liczba = 5;
int *wsk =&telefon;
```

Za pomocą operatora pobrania adresu (&) pobrany został adres zmiennej liczba. Za pomocą operatora pobrania adresu (&) pobraliśmy adres zmiennej telefon. Adres zmiennej został przypisany wskaźnikowi wsk. Pamiętaj że gwiazdka przed nazwą wskaźnika to nie operator wyłuskania! Chcąc wyświetlić wartość wskaźnika posłużymy się operatorem wyłuskania czyli gwiazdką ()*.

```c++
#include <iostream>

using namespace std;

int main()
{
    int telefon = 12345;    //zmienna liczbowa
    int *wsk = &telefon;    //wskaźnik wsk zawiera adres zmiennej telefon
    
    cout << *wsk << endl;
    
    return 0;
}
```

Powyższy przykład wyświetli na ekranie wartość zmiennej liczba. Przed wyświetleniem wskaźnika został użyty operator wyłuskania. Pobiera on wartość zmiennej spod adresu ze zmiennej wskaźnikowej. Bez użycia operatora wyłuskania, została by wyświetlona wartość zmiennej wskaźnikowej wsk czyli adres zmiennej liczba:

```c++
int liczba = 12345;         //zmienna liczbowa
int *wsk = &liczba;         //przypisanie wskaźnikowi adresu zmiennej liczba
										         
cout << *wsk << endl;        //wyświetlenie wyłuskanej wartości wskaźnika (12345)
cout << wsk << endl;         //wyświetlenie adresu zmiennej liczba
cout << &wsk << endl;        //wyświetlenie adresu wskaźnika
cout << &liczba << endl;    //wyświetlenie adresu zmiennej liczba
```

Proszę poszukać dlaczego jeżeli nie inicjujemy wartości we wskaźniku, warto przypisać nullptr?

## Przypomnienie pętli for

Ćwiczenie ma na celu przypomnienie prostej pętli for. 
```c++
Składnia
for (inicjalizacja; warunek_pętli; krok_pętli)
{
treść
}
```

Proszę napisać pętle, która wyświetli 5 razy napis JiPP2.


Zastanówcie się dlaczego lepiej stosować ++i zamiast i++?

## Alokowanie pamięci dla tablic

Aby dobrze poznać tablice dynamiczne należy zrozumieć działanie zwykłych statycznych tablic. Inicjowanie tablicy jest bardzo proste, podczas inicjacji możemy z góry określić elementy jakie zawiera tablica. 

```c++
int tablica[5] = { 10, 11, 12, 13, 14};
```

Ciekawostką może okazać się fakt, że nazwa tablicy jest jednocześnie wskaźnikiem na jej pierwszy element.
```c++
int tablica[5] = { 10, 11, 12, 13, 14};

cout << *tablica;   // wyświetli tablica[0];
cout << tablica;    // wartość wskaźnika, adres pierwszego elementu
```

Tablice statyczne nie dają nam możliwości decydowania o ich wymiarach podczas działania programu. Oznacza to że musimy znać wielkość tablicy na poziomie tworzenia aplikacji. Kolejną wadą takowych tablic jest fakt, iż generując tablicę dwuwymiarową musi być ona prostokątna.

```c++
int tablica[2][3];
```

Deklarując tablicę dynamiczną należy zadeklarować wskaźnik tego samego typu co elementy tablicy. Następnie rezerwujemy miejsce w pamięci o określonym typie (takim samym jak wskaźnik). Służy do tego rozkaz new. Tablicy dynamicznej używamy tak samo jak zwykłą tablice statyczną, nie trzeba operować wskaźnikami, wskaźniki potrzebne są tylko przy deklaracji. Wynika to z faktu opisanego wyżej - tablica statyczna to też wskaźniki chociaż nie są do końca widoczne.

```c++
int * tablica = new int[3];

tablica[0] = 11;
tablica[1] = 12;
tablica[2] = 13;

delete [] tablica;
```
Każdy dynamiczny obiekt utworzony podczas działania programu należy na końcu  usunąć poleceniem delete. Przy usuwaniu tablicy dodatkowo dodajemy kwadratowy nawias czyli delete []. Dzięki użyciu tablicy dynamicznej użytkownik ma możliwość decydowania o rozmiarze tablicy podczas działania programu:
```c++
int rozmiar;

cout << "Podaj rozmiar tablicy:" << endl;
cin >> rozmiar;

int * tablica = new int[rozmiar];

delete [] tablica;
```

Zadanie: proszę utworzyć dwolną tablicę dwuwymiarową oraz dla chętnych trójwymiarową.


## Przekazywanie parametrów podczas uruchamiania aplikacji

Uruchamiając aplikacje konsolowe, często się zdarza, że przekazujemy różne parametry, zaraz po nazwie programu, aby 
odpalić różne funkcjonalności, przykładowo w systemie Linux użyjemy komendy `ls -l`, aby wyświetlić pliki znajdujące 
się w folderze w formie listy.

Tworząc aplikacje też możemy dodać takową funkcjonalność, zgodnie z [dokumentacją funkcji main](https://en.cppreference.com/w/cpp/language/main_function) musimy dodać do niej 2 parametry:

* `int argc` - ilość przekazanych parametrów
* `char *argv[]` - parametry wpisane w konsoli

**Ważne** nazwa programu jest pierwszą wartością w zmiennej `argv` (znajduje się w `argv[0]`). Parametry podawane 
podczas wywoływania są rozdzielane spacjami.

Stwórzmy przykładowy program wypisujący wszystkie przekazane parametry:

```c++
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    for(int i = 0; i < argc ; ++i) {
        cout << argv[i] <<endl;        
    }
    
    return 0;
}
```

Skompilujmy nasz program i go wywołajmy za pomocą następującej komendy (nazwa naszego programu, to a.exe):

```console
a.exe 5 tarka Pelikan
```

Otrzymamy wynik:

```console
a.exe
5
tarka
Pelikan
```

### Zadanie

Stwórz program, który będzie dokonywał obliczeń, na podstawie przekazanych do niego parametrów (nie używamy cin). 
Pierwszy z nich 
będzie decydował, jakie to będzie działanie:
1. `add` - dodawanie dwóch liczb 
2. `subtract` - odejmowanie dwóch liczb
3. `volume` - obliczanie objętości graniastosłupa prostego o podstawie trapezu
4. `help` - wyświetlanie dokumentacji

Jeżeli przekazano zły bądź złą ilość parametrów powinien zostać wyświetlony komunikat o błędzie i dokumentacja, 
która powinna wyglądać w następujący sposób (tu jest tylko kawałek):

```console
Simple calculatur
simpleCalc [nazwa działania]

Działania:
add [a] [b]
    Dodawanie dwóch liczb ([a] i [b]) całkowitych.    
```

**Założenie**

Zawsze podajemy liczby tam, gdzie mają być liczby, nie wpisujemy tam tekstu.

<div style="page-break-after: always;"></div>

## Tworzenie biblioteki

Tworząc różnego rodzaju aplikacje, nie zawsze będziemy tworzyć programy, które będą uruchamiane. Czasem stworzymy 
bibliotekę, czyli zestaw funkcji, których ktoś może użyć przy tworzeniu własnej aplikacji. Podstawową różnicą 
względem wcześniej pisanych programów jest brak funkcji `main` oraz w pliku cmake nie używamy `add_executable`, 
tylko `add_library`.

#### Przygotowanie

1. W głównym folderze repozytorium stwórz nowy folder `firstLib`, w którym utwórz strukturę projektu.
2. Utwórz plik `lib.h` oraz `lib.cpp` w odpowiednich folderach
3. Stwórz plik `CMakeLists.txt` i dodaj odpowiedni wpis w głównym folderze.
4. Stwórz funkcję typu `void` o nazwie `itIsWork`, która będzie wypisywać `Yes it work!`.
5. W głównym folderze repozytorium stwórz nowy folder `firstLibCall`, utwórz plik `CMakeLists.txt` i dodaj 
   odpowiedni wpis w głównym folderze. Stwórz także plik `main.cpp`.
6. W pliku `main.cpp` stwórz funkcję main.
7. W `firstLibCall/CMakeLists.txt` dodaj wpis dołączania biblioteki oraz przeszukiwania przeszukiwania pod kątem 
   plików nagłówkowych.

```cmake
include_directories(${CMAKE_SOURCE_DIR}/firstLib/include)
add_executable(firstLibCall main.cpp)
target_link_libraries(firstLibCall firstLib)
```

8. Sprawdź, czy działa.

## Przekazywanie parametrów przez referencję

[Dokumentacja](https://en.cppreference.com/w/cpp/language/reference)

Głównym założeniem przekazywania parametru przez referencję jest to, że możemy zmieniać jego wartość nie tylko w 
funkcji, ale też w miejscu, w którym go wywołujemy. Dodatkowo może mieć to pozytywny wpływ na wydajność, ponieważ 
nie jest tworzona kopia przekazywanego parametru, tylko jest przekazywana referencja. Aby lepiej zrozumieć tego 
działanie, stwórzmy funkcję, która dodaje do siebie dwie liczby.

```c++
int add(int a, int b) {
    return a + b;
}
```

Wywołanie:

```c++
int w = add(5,5);
cout << w << endl;
```

Teraz do przekazania wyniku użyjmy referencji. Względem wcześniejszego przykładu będziemy potrzebować o jeden 
parametr więcej.

```c++
void add(int a, int b, int &c) {
    c = a + b;
}
```

Wywołanie:

```c++
int k;
add(5, 5, k);
cout << k << endl;
```

<div style="page-break-after: always;"></div>

Proszę utworzyć przeciążenie do powyższej funkcji

## Funkcja przyjmująca tablicę i dokonująca na niej obliczeń
Zadanie ma na cedlu przedstawienie i omówienie jak działa przekazywanie tablicy do wnętrza funkcji poprzez jej argumenty.


Konstrukcja nagłówka funkcji dla tablicy jednowymiarowej
```c++
typ_funkcji nazwa(typ_elementów_tablicy nazwa_tablicy[]);

void funkcja(int tablica[10]);
```

Dla przypomienia:
Nazwa tablicy jest wskaźnikiem na jej pierwszy element. Oznacza to, że przekazując tablicę jako argument funkcji, będziemy pracować na jej oryginalnym adresie (wszelkie zmiany w modyfikacji tablicy będą widoczne w miejscu, gdzie ją stworzyliśmy).


Program zamieniający wartosci tablicy na ich kwadraty:

```c++
#include<iostream>
using namespace std;
 
void zamiana(int tab[])
{
        for(int i=0; i<10; i++)
                tab[i]*=tab[i]; //lub tab[i] = tab[i] * tab[i];
}
 
int main()
{
        //inicjacja tablicy
        int tablica[10] = {0, 3, 4, 3, 6, 7, 11, -5, -10, 87}; 
        
        //wypisanie elementów tablicy
        for(int i=0;i<10;i++)
                cout<<tablica[i]<<" ";
        
        cout<<endl; //wstawienie znaku końca linii (enter)
        
        //wykonanie polecenia
        zamiana(tablica); //przekazując tablicę, podajemy tylko jej nazwę
        
        //ponowne wypisanie elementów tablicy
        for(int i=0;i<10;i++)
                cout<<tablica[i]<<" ";
        
        return 0;
}
```

# Projekt

## Biblioteka

Stwórz statyczną bibliotekę dokonująca obliczeń na macierzach. Zwracanie wyników powinno być wykonywane za pomocą 
referencji. Biblioteka powinna zawierać następujące funkcjonalności:
1. `addMatrix` - dodawanie dwóch macierzy
2. `subtractMatrix` - odejmowanie dwóch macierzy
3. `multiplyMatrix` - mnożenie dwóch macierzy
4. `multiplyByScalar` - mnożenie przez skalar
5. `transpozeMatrix` - odwracanie macierzy
6. `powerMatrix` - potęgowanie macierzy
7. `determinantMatrix` - wyznacznik macierzy (funkcja powinna zwracać `double` oraz `int`, w tym przypadku wynik nie 
   jest 
   przekazywany przez referencję)
8. `matrixIsDiagonal` - sprawdzanie, czy macierz jest diagonalna (funkcja powinna zwracać `bool`, w tym przypadku wynik 
   nie jest przekazywany przez referencję)

Wszystkie funkcjonalności powinny mieć możliwość dokonywania obliczeń na zmiennych typu `double` oraz `int` 
(przeciążanie funkcji). 

## Program

Stwórz program, który będzie wykorzystywał powyższą bibliotekę. Jako parametr uruchamiania go będzie przyjmował 
nazwę funkcjonalności, a następnie za pomocą `cin` wczytaj macierze. Dokonaj obliczeń i wyświetl wynik.

### Wczytywanie macierzy

#### Założenie

Podczas wczytywania danych, jeżeli ma być wczytana liczba, to nie będzie podawany tekst.

## O czym musisz pamiętać

1. Napisaniu dokumentacji do każdej funkcji.
2. Używaniu nazw zmiennych, które mówią, co przechowują.
3. Czystości kodu (na ile ją umiecie).
4. Strukturze plików.
5. Napisaniu zabezpieczenia podczas tworzenia macierzy (jeżeli tworzymy macierz 4x4, to musimy podać 16 liczb).








