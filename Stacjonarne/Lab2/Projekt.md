# Projekt

Projekt będzie się składał z dwóch części, biblioteki i programu. Głównym jego celem jest napisanie biblioteki do wykonywania obliczeń na macierzach.

Celem projektu (pod względem osiągania efektów uczenia się) jest dalsza powtórka podstaw języka c++ i utrwalenia zdobytych umiejętności. 

## Biblioteka

Stwórz statyczną bibliotekę dokonująca obliczeń na macierzach. Funkcje powinny zwracać podwójny wskaźnik (np `int **`)
. Biblioteka powinna zawierać następujące funkcjonalności:
1. `addMatrix` - dodawanie dwóch macierzy
   - macierz a
   - macierz b
   - ilość wierszy
   - ilość kolumn
2. `subtractMatrix` - odejmowanie dwóch macierzy
   - macierz a
   - macierz b
   - ilość wierszy
   - ilość kolumn
3. `multiplyMatrix` - mnożenie dwóch macierzy
   - macierz a
   - macierz b
   - ilość wierszy pierwszej macierzy
   - ilość kolumn pierwszej macierzy
   - ilość kolumn drugiej macierzy
4. `multiplyByScalar` - mnożenie przez skalar
   - macierz a
   - ilość wierszy
   - ilość kolumn
   - skalar (taki sam typ, jak macierz)
5. `transpozeMatrix` - transponowanie macierzy
   - macierz a
   - ilość wierszy
   - ilość kolumn
6. `powerMatrix` - potęgowanie macierzy, jako drugi parametr przyjmuje wartość potęgi
   - macierz a
   - ilość wierszy
   - ilość kolumn
   - stopień potęgi (unsigned)
7. `determinantMatrix` - wyznacznik macierzy (funkcja powinna zwracać wartość (typu takiego, jakiego są macierze), w tym przypadku wynik nie jest przekazywany przez referencję)
   - macierz a
   - ilość wierszy
   - ilość kolumn
8. `matrixIsDiagonal` - sprawdzanie, czy macierz jest diagonalna (funkcja powinna zwracać `bool`, w tym przypadku wynik
   nie jest przekazywany przez referencję)
   - macierz a
   - ilość wierszy
   - ilość kolumn
9. `swap` - zamiana dwóch wartości miejscami (parametry przekazywane przez referencję)
   - liczba a
   - liczba b
10. `sortRow` - sortowanie tablicy za pomocą sortowania bombelkowego (porównywanie każdej wartości z każdą)
    - tablica
    - ilość kolumn
11. `sortRowsInMatrix` - sortowanie wszystkich wierszy w macierzy 
    - macierz a
    - ilość wierszy
    - ilość kolumn


Wszystkie funkcjonalności powinny mieć możliwość dokonywania obliczeń na zmiennych typu `double` oraz `int`
(przeciążanie funkcji).

Macierze są przekazywane jako podwójny wskaźnik, a ilość kolumn oraz wierszy jest typu int.

#### Założenia

Zakładamy, że przekazujemy macierze, które są poprawne dla danego obliczenia.


&nbsp;

&nbsp;

## Program

Stwórz program, który będzie wykorzystywał powyższą bibliotekę. Jako parametr uruchamiania go będzie przyjmował
nazwę funkcjonalności, a następnie za pomocą `cin` wczytywał liczby do macierzy. Dokonaj obliczeń i wyświetl wynik.
Program powinien wyświetlać dokumentację (help) po podaniu pierwszego parametru o wartości `help`, bądź 
wywołaniu programu ze złą wartości parametru.

### Wczytywanie macierzy

Sposób wczytywania macierzy opracuj sam. Użytkownik ma mieć możliwość samemu wybierania ich rozmiarów.
Pamiętaj o napisaniu w `help` jak działa wczytywanie.


## Założenia

1. Biblioteka musi się znajdować w folderze `matrixLib`.
2. Nazwa targetu w CMake dla biblioteki: `matrixLib`.
3. Program musi się znajdować w folderze `matrixApp`.
4. Nazwa targetu w CMake dla programu: `matrixApp`
5. W głównym folderze repozytorium musi być plik `CMakeLists.txt` który ładuje pozostałe podfoldery.

Sprawdzanie zadań może być dokonywane przy pomocy testów, dlatego używanie powyżej zdefiniowanych nazw jest bardzo ważne.


## O czym musisz pamiętać

1. Napisaniu dokumentacji do każdej funkcji.
2. Używaniu nazw zmiennych, które mówią, co przechowują.
3. Czystości kodu (na ile ją umiecie).
4. Strukturze plików.
5. Napisaniu zabezpieczenia podczas tworzenia macierzy (jeżeli tworzymy macierz 4x4, to musimy podać 16 liczb).
6. Napisaniu zabezpieczenia przed podaniem tekstu zamiast liczb.
7. Używaniu nazw funkcji, takich, jak zostały podane.
8. Używaniu typów dla funkcji, takie, jakie zostały podane.


# Terminy oddawania

Projekt należy oddać (wgrać na swojego githuba) do **29.10.2021**.

Dodatkowo projekt należy zaliczyć u prowadzącego.
 

| Termin wrzucenia na gita | Maksymalna ocena  |
|----------------|-------------------|
| do 29.10.2021  | 5.0               |
| do 31.10.2021  | 4.5               |
| do 03.11.2021  | 4.0               |
| do 07.11.2021  | 3.5               |
| do 14.11.2021  | 3.0               |
| po 14.11.2021  | 2.0 - projekt niezaliczony |

Jeżeli ktoś nie zaliczy projektu (dostanie ocenę 2.0), to musi oddać dodatkowy projekt.

Wszystkie podane terminy są do godziny 23:59:59.


## Wskazówki

**Czystość kodu** <br/>
Clion posiada skrót klawiszowy, który reformatuje kod, jest to `ctrl+shift+L`.