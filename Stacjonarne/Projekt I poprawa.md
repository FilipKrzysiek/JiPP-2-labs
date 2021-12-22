# Projekt I dla tych, co nie oddali w pierwszym terminie

# Zasady

Ten projekt jest podobny do poprzedniego, ale możesz za niego uzyskać ocenę maksymalnie 3.0. **Jeżeli nie oddasz go do
16.01.2022**, to zostaje on niezaliczony i dostajesz ocenę 2.0 bez możliwości poprawy.

## Zwróć na to uwagę

1. Nazwy funkcji muszą być takie same, jak zostaną tutaj podane, jeżeli zawierają literówkę, to ją zostaw.
2. Kolejność parametrów ma znaczenie! Twórz je tak, jak zostaną podane.
3. Jeżeli test nie przejdzie, ponieważ nazwa funkcji będzie inna, bądź parametry będą się nie zgadzać, to zostanie ten
   podpunkt **niezaliczony**.
4. Jeżeli test nie przejdzie z powodu błędów w implementacji, to zostanie ten podpunkt **niezaliczony**.
5. Przestrzegaj nazw "targetów" w CMake, jeżeli zostało powiedziane, że biblioteka ma mieć w cmake nazwę np `matrixLib`,
   to ma mieć taką, nazwę, ponieważ w przeciwnym wypadku nie jestem w stanie jej załączyć do testu, co skutkuje błędem
   pliku CMake, a w dalszej kolejności niezaliczeniem wszystkich testów, a jest to równoważne z oceną **2.0**.
6. Przestrzegaj wielkości liter w nazwach plików i folderów oraz w CMake. Testy są uruchamiane na Linuxie, gdzie `a`
   i `A` robi różnicę.
7. W głównym folderze musi się znajdować plik `CMakeLists.txt`, który dodaje katalogi w którym jest projekt.

&nbsp;

&nbsp;

&nbsp;

# Opis

Projekt będzie się składał z dwóch części, biblioteki statycznej i programu. Głównym jego celem jest napisanie
biblioteki do wykonywania obliczeń na macierzach.

&nbsp;

## Biblioteka

Stwórz bibliotekę statyczną, która będzie dokonywać obliczeń na macierzach. Funkcje powinny zwracać podwójny wskaźnik
służący do przekazywania macierzy (np `int **`). Biblioteka musi posiadać następujące funkcjonalności:

1. `matrixAdd` - dodawanie dwóch macierzy
    - macierz a
    - macierz b
    - rozmiar macierzy
2. `matrixSubtract` - odejmowanie macierzy
    - macierz a
    - macierz b
    - rozmiar macierzy
3. `matrixMultiply` - mnożenie dwóch macierzy
    - macierz a
    - macierz b
    - rozmiar macierzy a
    - rozmiar macierzy b
4. `matrixMultiplyByScalar` - mnożenie przez skalar
    - macierz a
    - rozmiar macierzy
    - skalar (taki sam typ, jak macierz)
5. `matrixTranspoze` - transponowanie macierzy
    - macierz a
    - rozmiar macierzy
6. `matrixPower` - potęgowanie macierzy, jako trzeci parametr przyjmuje stopień potęgi
    - macierz a
    - rozmiar macierzy
    - stopień potęgi (`unsigned short`)
7. `matrixDeterminant` - wyznacznik macierzy (funkcja powinna zwracać wartość (typu takiego, jakiego są macierze), w tym
   przypadku wynik nie jest przekazywany przez wskaźnik)
   . [Tutaj znajdziesz](https://www.naukowiec.org/wiedza/matematyka/macierz-trojkatna_620.html), jak obliczyć wyznacznik
   macierzy bez używania rekurencji
    - macierz a
    - rozmiar macierzy
8. `matrixIsDiagonal` - sprawdzanie, czy macierz jest diagonalna (funkcja powinna zwracać `bool`, w tym przypadku wynik
   nie jest przekazywany przez wskaźnik) zwracane jest `true`, jeżeli macierz jest diagonalna i `false`, jeżeli nie jest
    - macierz a
    - rozmiar macierzy
9. `swap` - zamiana dwóch wartości miejscami (parametry przekazywane przez referencję)
    - liczba a
    - liczba b
10. `sortRow` - sortowanie tablicy za pomocą sortowania bąbelkowego (porównywanie każdej wartości z każdą)
    - tablica
    - ilość kolumn
11. `matrixSortRows` - sortowanie wszystkich wierszy w macierzy — posortuj osobno każdy wiersz w macierzy. Sortowanie ma
    być rosnące
    - macierz a
    - rozmiar macierzy
12. `matrixGenerate` - tworzenie macierzy z losowymi wartościami
    - rozmiar macierzy
    - minimalna wartość - dolny zakres losowania liczb (dolna granica)
    - maksymalna wartość - górny zakres losowania liczb (górna granica)

&nbsp;

Wszystkie funkcjonalności powinny zostać zaimplementowane dla zmiennych typu `float` i `long` (przeciążanie funkcji).

Macierze są przekazywane jaki podwójny wskaźnik i nie powinny być modyfikowane w funkcji.

**Założenia**

Zakładamy, że przekazywane macierze i ich rozmiar są poprawne dla danego obliczenia.

&nbsp;

### Rozmiar macierzy

Rozmiar macierzy ma być typu `pair`, gdzie pierwszym elementem jest ilość wierszy, a drugim ilość kolumn.

```c++
//deklarowanie pair
pair<int, int> matrixSize;

//dostęp do pierwszej zmiennej
matrixSize.first;

//dostęp do drugiej zmiennej
matrixSize.second;

//modyfikowanie wartości
matrixSize.first = 5;
matrixSize.second = 5;
```

&nbsp;

&nbsp;

## Program

Stwórz program, który będzie wykorzystywał powyższą bibliotekę. Będzie on wczytywał wartości lub je generował, dokonywał
obliczeń, a następnie wyświetlał wynik na ekran. Dodatkowo musi istnieć funkcjonalność wyświetlania pomocy (help), która
może zostać wywołana poprzez parametr `help` lub podczas podania złego parametru, lub złej ich ilości. Jako parametr
uruchamiania, będzie przyjmował nazwę funkcjonalności, która ma być uruchomiona, które będą odpowiadały nazwą funkcji z
biblioteki, czyli:

1. `matrixAdd`
2. `matrixSubtract`
3. `matrixMultiply`
4. `matrixMultiplyByScalar`
5. `matrixTranspoze`
6. `matrixPower`
7. `matrixDeterminant`
8. `matrixIsDiagonal`
9. `swap`
10. `sortRow`
11. `matrixSortRows`
12. `matrixGenerate`
13. `help` - wyświetlanie helpa

Dodatkowo przy funkcjach:

1. `matrixAdd`
2. `matrixSubtract`
3. `matrixMultiply`
4. `matrixMultiplyByScalar`
5. `matrixTranspoze`
6. `matrixPower`
7. `matrixDeterminant`
8. `matrixIsDiagonal`
9. `matrixSortRows`

może zostać podany drugi parametr `generate`, który będzie oznaczał, że dane wejściowe do macierzy mają zostać
wygenerowane.

Jeżeli nie zostanie podany parametr `generate`, to wartości do macierzy mają być wczytywane z klawiatury za pomocą `cin`
.

### Wczytywanie macierzy

Sposób wczytywania macierzy opracuj sam. Użytkownik ma mieć możliwość samemu wybierania ich rozmiarów oraz typu.
Pamiętaj o napisaniu w help, jak działa wczytywanie.

&nbsp;

&nbsp;

&nbsp;

# Struktura projektu

1. Biblioteka ma się znajdować w folderze `betterMatrixLib`, który znajduje się bezpośrednio w głównym folderze
   repozytorium.
2. Nazwa targetu w CMake dla biblioteki: `betterMatrixLib`.
3. Program ma się znajdować w folderze `betterMatrixApp`, który znajduje się bezpośrednio w głównym folderze
   repozytorium.
4. Nazwa targetu w CMake dla programu: `betterMatrixApp`.
5. W głównym folderze repozytorium musi być plik `CMakeLists.txt`, który ładuje pozostałe podfoldery.

Sprawdzanie zadań będzie dokonywane za pomocą testów, więc jeżeli powyższe punkty nie zostaną spełnione, to testy się
nie uruchomią, kompilacja również i będzie to równoznaczne z oceną 2.0.

&nbsp;

&nbsp;

&nbsp;

## O czym musisz pamiętać

1. Napisaniu dokumentacji do każdej funkcji w pliku nagłówkowym (doxygen).

```c++
/**
 * Opis funkcji
 * @param a opis parametru
 * @param name opis parametru
 * @return opis tego co jest zwracane
 */
int exampleFunction(int a, string name);
```

2. Używaniu nazw zmiennych, które mówią, co przechowują.
3. Czystości kodu (na ile ją umiecie).
4. Strukturze plików.
5. Napisaniu zabezpieczenia podczas tworzenia macierzy (jeżeli tworzymy macierz 4x4, to musimy podać 16 liczb).
6. Napisaniu zabezpieczenia przed podaniem tekstu zamiast liczb.
7. Napisaniu zabezpieczeń przed podaniem złej ilości bądź złych parametrów wywołania aplikacji.
8. Używaniu nazw funkcji, takich, jak zostały podane.
9. Używaniu typów dla funkcji, takie, jakie zostały podane.
10. Jeżeli program się nie będzie kompilował, to nie będzie sprawdzany (dostajesz **2.0**).
11. Jeżeli testy **nie będą się uruchamiać** z powodu złych nazw bądź typów, te podpunkty **nie będą sprawdzane**.
12. Jeżeli używasz np `pow`, bądź innych funkcji matematycznych, to załącz bibliotekę `cmath` (kompilator visual studio
    nie wiedzieć czemu sam to załącza, lecz na Linuxie się to nie dzieje).

&nbsp;

&nbsp;

&nbsp;

# Terminy

Projekt należy oddać (wgrać na swojego githubu) do 16.01.2022, chyba że zostanie warunkowo ustalone (przed terminem
oddania) z prowadzącym inaczej. Projekty oddane później zostana ocenione na 2.0 bez możliwości poprawy.

