# Laboratorium 3

Calem tego laboratorium jest nauka tworzenia bibliotek przy użyciu CMake. Dodatkowo będzie poruszana tematyka
przekazywania parametrów przez referencję oraz przeciążania funkcji.

## Tworzenie biblioteki

Tworząc różnego rodzaju aplikacje, są funkcjonalności, które wykorzystujemy wielokrotnie w różnych programach. Można
je implementować za każdym razem bądź kopiować kod, lecz w znaczącym stopniu utrudnia to nim zarządzanie, a w
szczególności aktualizowanie. Bardzo ważnym aspektem jest też konieczność ponownych kompilacji. Kolejnym aspektem
jest udostępnianie naszej funkcjonalności innym. Jeżeli nie zależy nam na utajnieniu jej budowy, to możemy udostępnić
kod, lecz w przeciwnym wypadku będziemy chcieli udostępnić skompilowaną wersję.

Możemy spróbować stworzyć prostą definicję biblioteki. Jest to zestaw funkcjonalności, które chcemy używać wielokrotnie.

Rodzaje bibliotek:
- heder only — biblioteka stworzona tylko i wyłącznie w plikach nagłówkowych
- static — biblioteka statyczna, musi ona zostać dołączona w trakcie kompilowania programu
- shared — biblioteka dynamiczna, może zostać dołączona w trakcie kompilowania programu, bądź załadowana w trakcie jego
  działania

Podczas zajęć będziemy się zajmować bibliotekami statycznymi.

Główne różnica biblioteki względem programów wykonywalnych:
- bibliotek nie da się uruchomić
- biblioteka nie zawiera funkcji `main`
- w pliku `CMakeLists.txt` zamiast używania `add_executable`, używamy `add_library`

&nbsp;

### Przykład prostej biblioteki

Przykład biblioteki i jej wywołania można zobaczyć w folderze `Examples/SimpleLib`.

Zacznijmy omawianie kodu biblioteki (`Examples/SimpleLib/Library`). Będzie ona udostępniać funkcjonalność
wczytywania i wypisywania naszego imienia na ekran. W pliku `include/simpleLib/lib.h` tworzymy przepis na naszą
bibliotekę, czyli definiujemy funkcję, natomiast w pliku cpp (`src/lib.cpp`) jej ciało. Najważniejsza część, która
nas interesuje, czyli plik [CMake](Example/SimpleLib/Library/CMakeLists.txt) (`Example/SimpleLib/Library/CMakeLists.txt`):

```cmake
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(simpleLibLib STATIC src/lib.cpp)
```
*<sup>Opis znajduje się w pliku.</sup>*

Plik nieznacznie różni się od wcześniej tworzonych. Zamiast `add_executable` używamy `add_library`, dodatkowo
dopisaliśmy w środku słowo `STATIC`, które definiuje jaki typ biblioteki będziemy chcieli uzyskać. W naszym
przypadku będzie to biblioteka statyczna.

&nbsp;

Część aplikacji, która używa naszej biblioteki (`Examples/SimpleLib/App`). Plik `main.cpp` załącza plik nagłówkowy
biblioteki, abyśmy znali przepis na naszą bibliotekę, wiedzieli jakie funkcjonalności ona oferuje. W funkcji `main`
wywołujemy naszą funkcję. <br/>
Najważniejsze, czyli plik [`CMakeLists.txt`](Examples/SimpleLib/App/CMakeLists.txt) (`Examples/SimpleLib/App/CMakeLists.txt`)

```cmake
cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD  17)

include_directories(../Library/include)

add_executable(simpleLibApp main.cpp)

target_link_libraries(simpleLibApp simpleLibLib)
```
*<sup>Opis znajduje się w pliku.</sup>*

Na początku wskazujemy, jaki folder ma być przeszukiwany pod względem plików nagłówkowych, następnie definiujemy,
które pliki mają być skompilowane. Kolejnym krokiem jest zalinkowanie biblioteki, której używamy za pomocą `target_link_libraries`
w parametrach podajemy nazwę celu (target name, czyli pierwszy parametr w komendzie `add_executable`), następnie
mówimy jaką bibliotekę chcemy zalinkować, w naszym przypadku podajemy nazwę z pierwszego parametru komendy
`add_library`.


&nbsp;

### Przetestuj sam

1. W głównym folderze repozytorium stwórz nowy folder `firstLib`, w którym utwórz strukturę projektu.
2. Utwórz plik `lib.h` oraz `lib.cpp` w odpowiednich folderach
3. Stwórz plik `CMakeLists.txt` i dodaj odpowiedni wpis w głównym folderze.
4. Stwórz funkcję typu `void` o nazwie `itIsWork`, która będzie wypisywać `Yes it work!`.
5. W głównym folderze repozytorium stwórz nowy folder `firstLibCall`, utwórz plik `CMakeLists.txt` i dodaj
   odpowiedni wpis w głównym folderze. Stwórz także plik `main.cpp`.
6. W pliku `main.cpp` stwórz funkcję main.
7. W `firstLibCall/CMakeLists.txt` dodaj wpis dołączania biblioteki oraz przeszukiwania pod kątem
   plików nagłówkowych.

```cmake
include_directories(${CMAKE_SOURCE_DIR}/firstLib/include)
add_executable(firstLibCall main.cpp)
target_link_libraries(firstLibCall firstLib)
```

8. Sprawdź, czy działa.

### Przykład, gdy nie mamy implementacji biblioteki

**Przykład był kompilowany pod systemem linux, uważaj na rozszerzenia plików**

Nie zawsze mamy kod biblioteki, którą chcemy użyć. Rozważmy przypadek, kiedy do dyspozycji mamy już przygotowaną,
skompilowana bibliotekę. Struktura jej plików wygląda następująco:

```console
.
├── CMakeLists.txt
├── include
│   └── ExampleLib
│       └── lib.h
└── libexampleLib.a
```

W folderze include znajduje się przepis na tę bibliotekę, a plik `libExampleLib.a` zawiera jej implementację. W
takim przypadku należy w inny sposób ją wywołać w pliku CMake.

```cmake
cmake_minimum_required(VERSION 3.16)

# tworzone pod linuxem, jeżeli uruchamiasz pod innym systemem zmień rozszerzenie pliku
add_library(exampleLibCall INTERFACE)
target_link_libraries(exampleLibCall INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/libexampleLib.a)
```

Póki co tego przykładu nie musisz się uczyć, po prostu wiedz, gdzie to znaleźć.

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

## Przeciązanie funckji

Funkcje można w C++ (ale nie w C) przeciążać. Oznacza to sytuację, gdy w tym samym zakresie są widoczne deklaracje/definicje kilku funkcji o tej samej nazwie. Oczywiście, aby na etapie kompilacji było wiadomo, o wywołanie której funkcji nam chodzi, wszystkie wersje funkcji muszą się wystarczająco różnić. Co to znaczy wystarczająco? Generalnie, muszą się różnić na tyle, aby można było jednoznacznie wybrać jedną z nich na podstawie wywołania. Warunkiem koniecznym, choć niewystarczającym jest, aby funkcje o tej samej nazwie różniły się sygnaturą.

Do sygnatury funkcji należy jej nazwa oraz liczba i typ parametrów nie licząc tych z wartościami domyślnymi. Typ funkcji, czyli typ wartości zwracanej, zwykle do sygnatury nie jest zaliczany.

PRZYKLAD:
```c++
  int fun(double x, int k =0);
  double fun(double z);
```
To dwie deklaracje różnych funkcji, ale o takiej samej sygnaturze, a mianowicie o sygnaturze fun(double). I rzeczywiście, wywołanie fun(1.5) byłoby najzupełniej legalnym i nie wymagającym żadnej niejawnej konwersji wywołaniem zarówno pierwszej, jak i drugiej z tych funkcji. Takie przeciążenie jest zatem nielegalne.

Natomiast:
```c++
double fun(int);
double fun(unsigned);
```
to deklaracje funkcji różniących się sygnaturą. Wywołanie fun(15) jest wywołaniem pierwszej z nich, bo '15' jest literałem wartości typu int i do przekształcenia tej wartości do typu unsigned potrzebna byłaby konwersja. Zatem takie przeciążenie jest prawidłowe.

Z drugiej strony, różne sygnatury nie są jeszcze warunkiem dostatecznym na legalność przeciążenia. Widzimy to na przykładzie funkcji.

```c++
void fun(int i);
void fun(int& i);
```
które mają różną sygnaturę, ale wywołanie fun(k), gdzie k jest typu int, może być traktowane jako wywołanie zarówno pierwszej, jak i drugiej z nich. Zatem takie przeciążenie byłoby nieprawidłowe. Podobnie nieprawidłowe byłoby przeciążenie:
```c++
void fun(int tab[]);
void fun(int * p);
```
lub
```c++
void fun(tab[3][3]);
void fun(tab[5][3]);
```
bo pierwszy wymiar tablicy wielowymiarowej nie ma znaczenia do określenia typu (jest i tak pomijany w tego rodzaju deklaracji/definicji). Natomiast:

```c++
void fun(tab[3][3]);
void fun(tab[3][5]);
```
prawidłowo deklaruje dwie przeciążone funkcje fun, gdyż tablice wielowymiarowe różniące się wymiarem innym niż pierwszy są różnych typów i pomiędzy tymi typami nie ma niejawnej konwersji.


ZADANIE:
1) Napisz funkcję, która będzie liczyła pole figury. Pole będzie zależne od ilości oraz typu argumentów.


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
ZADAANIA:
1) Napisz funkcję zwracającą liczbę losową z przedziału <a, b>, gdzie a i b
   to argumenty tej funkcji
2) Napisz funkcję, która zwraca największą wartość przechowywaną w
   tablicy jednowymiarowej. Przetestuj ją w prostym programie (użyj tablicy
   alokowanej dynamicznie, wypełnionej liczbami losowymi z przedziału <1, 100>).
3) Napisz funkcję, która zmienia kolejność elementów tablicy (odwraca tablicę), podanej do funkcji jako argument.


## Przekazywanie przez wskaźnik

Funkcje nie byłyby tak użyteczne, gdyby nie dało się do nich przekazywać argumentów.

Przekazywanie argumentów przez wskaźnik jest możliwe zarówno w języku C++ jak i C. Użycie wskaźników razem z funkcjami jest bardzo wygodne i ekonomiczne. Zdarzają się sytuacje, kiedy skorzystanie ze wskaźników jest niezbędne do osiągnięcia odpowiedniego efektu.

Przekazując argumenty przez wartość, funkcja może zwrócić tylko jeden parametr za pomocą return. Oznacza to, że możliwe jest zmodyfikowanie wartości tylko jednej zmiennej występującej poza wywoływaną funkcją. Co w przypadku gdy podczas wywołania jednej funkcji chcemy zmienić kilka zmiennych? – tutaj niezbędne są wskaźniki. Jest to najlepszy przykład na zobrazowanie tego, dlaczego wskaźniki są przydatne

Podsumowując przekazywanie przez wskaźnik:
- argumenty wskaźnikowe wskazują na zmienne z poza funkcji, więc wewnątrz funkcji nie są tworzone kopie
- funkcja może zmodyfikować wiele zmiennych z poza funkcji (bez użycia return)
- wskaźniki także przekazujemy przez wartość, wynika to z faktu że wskaźnik też jest typem zmiennej (zmienna wskaźnikowa), jednak mimo że wskaźnik (adres miejsca w pamięci) zostanie skopiowany  to wartość wyłuskana ze wskaźnika nie jest już kopią

PRZYKŁADOWY KOD:
```c++
#include <iostream>
#include <cstdlib>

using namespace std;

void zwieksz_kilka(int *dl, int *wys, int *waga)
{
    // zmienna '*dl', '*wys' i '*waga' nie są kopiami
    // operowanie na nich zmienia ich wartość w "całym" programie
    // funkcja nie zwraca nic - bo nie ma sensu
    
    *dl = *dl * 2;
    *wys = *wys * 2;
    *waga = *waga * 2;
}

int main()
{
    // zmienne
    int dlugosc = 125;
    int wysokosc = 300;
    int waga = 20;
    
    // wskaźniki do zmiennych
    int *wsk_dlugosc = &dlugosc;
    int *wsk_wysokosc = &wysokosc;
    int *wsk_waga = &waga;
    
    // wywołanie funkcji
    zwieksz_kilka(wsk_dlugosc, wsk_wysokosc, wsk_waga);
    
    // wyświetlenie nowych wartości
    cout << dlugosc << endl;
    cout << wysokosc << endl;
    cout << waga << endl;
    
    system("pause >nul");
    return 0;
}
```
Argumenty funkcji to zmienne wskaźnikowe czyli “adresy do zmiennych”. Gwiazdka w argumentach nie jest operatorem wyłuskania, informuje ona kompilator że zmienna jest wskaźnikiem (czyli “adresem”). Jak można wykorzystać ten fakt? Nie trzeba deklarować zmiennych wskaźnikowych aby przekazywać argument funkcji przez wskaźnik. Można przekazać bezpośrednio adres za pomocą operatora pobrania adresu (&).

PRZYKŁADOWY KOD:
```c++
#include <iostream>
#include <cstdlib>

using namespace std;

void zwieksz_kilka(int *dl, int *wys, int *waga)
{
    // zmienna '*dl', '*wys' i '*waga' nie są kopiami
    // operowanie na nich zmienia ich wartość w "całym" programie
    // funkcja nie zwraca nic - bo nie ma sensu
    
    *dl = *dl * 2;
    *wys = *wys * 2;
    *waga = *waga * 2;
}

int main()
{
    // zmienne
    int dlugosc = 125;
    int wysokosc = 300;
    int waga = 20;
    
    // wywołanie funkcji z (&) (tak jak byśmy przekazywali wskaźniki)
    zwieksz_kilka(&dlugosc, &wysokosc, &waga);
    
    // wyświetlenie nowych wartości
    cout << dlugosc << endl;
    cout << wysokosc << endl;
    cout << waga << endl;
    
    system("pause >nul");
    return 0;
}
```
ZADANIA:
1) Do napisania jest program pobierający 2 liczby oraz ustawi wskaźniki na ich adresach, a także obliczy ich średnią. Należy wykorzystać wskaźniki.
2) Do napisania program gdzie wczytamy i wypiszemy na ekran elementy tablicy większe od 0 (należy użyć wskaźników).
3) Do napisania jest funkcja do sortowania liczb, które są zapisane w zmiennych w rosnącej kolejności. Należy użyć wskaźników.
4) Proszę stworzyć funkcję, której argumentami będą liczba całkowita x oraz intowy wskaźnik w. Powinna ona wpisywać wartość x do zmiennej wskazywanej przez wskaźnik.

## Róznica między referencją oraz wskaźnikiem

Wskaźnik jest typem zmiennej, czyli zmienną wskaźnikową. Do wskaźnika możemy przypisać dowolny adres pamięci, na którą ten wskaźnik będzie wskazywał. Dlatego przekazując wskaźnik do funkcji, zostaje on przekazany przez wartość (a więc skopiowany), jednak prawdziwą wartością wskaźnika jest właśnie adres pamięci. Próbując wyświetlić wskaźnik ukaże się naszym oczom adres pamięci. Aby natomiast dostać się do prawdziwej wartości wskaźnika, trzeba posłużyć się operatorem wyłuskania (gwiazdka), czyli operatorem pobrania wartości wskaźnika.

Skoro wskaźnik jest typem zmiennej, to w dowolnym momencie możemy zmienić adres na jaki wskazuje. Referencja natomiast jest bezpośrednim adresem pamięci danej zmiennej. Oznacza to, że nie można jej zmienić, skasować ani uszkodzić. Usunięcie wskaźnika, nie spowoduje utraty zmiennej na jaką wskazywał. Jakiekolwiek nadpisanie referencji, spowoduje natychmiastową utratę danych.

Przekazywanie argumentów przez referencję jest łatwiejsze, ponieważ nie trzeba operować na gwiazdkach i ampersandach. To jedyna różnica między referencją a wskaźnikami w argumentach funkcji. Przez to początkujący programiści często mylą lub wręcz nie wiedzą, z którego sposobu chcą skorzystać.

W funkcji tworzymy dowolną ilość argumentów wraz z typami. Nazwy argumentów poprzedzone są ampersandem (&). Zmienne wewnątrz funkcji nie są kopią, oznacza to że operując na zmiennych referencyjnych operujemy także na zmiennej oryginalnej z pod której wywołana została funkcja.

```c++
#include <iostream>
#include <cstdlib>

using namespace std;

void zmien(int &liczba)
{
    // modyfikując referencję modyfikujemy też zmienną oryginalną
    
    liczba = 123456;
}

int main()
{
    int test = 0;
    
    // wywołanie funkcji (referencja zmiennej 'test')
    zmien(test);
    
    // wyświetlenie nowej wartości
    cout << test << endl;
    
    system("pause >nul");
    return 0;
}
```


## Obsługa błędów

W trakcie działania programu zawsze może dojść do powstania sytuacji nietypowej. Uniknąć się tego nie da. Można jednak przewidywać iż taka sytuacja wystąpi i się na nią przygotować. W języku C++ wprowadzono mechanizm pozwalający programiście na reagowanie na sytuacje błędne czy nietypowe.
Gdy taka sytuacja wystąpi, programista może wygenerować wyjątek.
- Wyjątek (ang. exception) to obiekt pewnej klasy. Wygenerowanie wyjątku polega na przekazaniu obiektu pisującego wyjątek z fragmentu kodu, w którym wystąpił problem, do fragmentu, w którym przewidziano jego obsługę.
- Wygenerowanie (zgłoszenie) wyjątku powoduje przerwanie wykonywania sprawiającego problemy kodu i przejście do obsługi sytuacji problematycznej. Obsługa ta może znajdować się w innym miejscu kodu.
- Wyjątek jest obiektem, jego klasa określa typ sytuacji wyjątkowej. Obiekt może w sobie posiadać pola oraz funkcje składowe, pozwalające na sprecyzowanie informacji o zaistniałej sytuacji wyjątkowej.

Polecenia try, throw, catch
SKŁADNIA:
 ```c++
 try 
 {      
 <instrukcje>; 
 throw <obiekt>; 
 } catch(<obiekt>)  
 {                        
 <instrukcje>;
 }
 ```

Przykład 1. Polecenie try, throw & catch

```c++
void main() { 
try       { 
throw"tekst z obszaru try"; // wyrzuć tekst       
} 
catch(constchar * msg) // złap wyrzucony tekst i przypisz do wskaźnika msg       
{                                                
cout << msg << endl;       
}  
} 
```

Do przeczytania:
https://docs.microsoft.com/pl-pl/cpp/cpp/errors-and-exception-handling-modern-cpp?view=msvc-160


ZADANIA:
1) Do napisania jest program wczytuje od użytkownika dwie liczby naturalne a i b. Program ma wypisać na ekran wynik dzielenia a przez b, a jeśli jest to niemożliwe to ma wypisać odpowiedni komunikat. Dzielenie będzie odbywać się w zbiorze liczb naturalnych, dlatego wynikiem dzielenia nie może być ułamek.
2) Do napisania jest funkcja, która wczyta od użytkownika linijkę zawierającą ciąg znaków. Program powinien następnie spróbować przekonwertować wprowadzony tekst na liczbę typu int. W trakcie konwersji program może zwrócić dwa wyjątki: Wprowadzony ciąg zawiera nieprawidłowe znaki oraz Wprowadzona liczba jest za duża. Na sam koniec program powinien wypisać skonwertowaną liczbę na ekran.
 
