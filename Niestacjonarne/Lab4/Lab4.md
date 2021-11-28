# Laboratorium 4

#### Tematyka zajęć

- Operacje na plikach
- Przeciążenia operatorów
- Tablica obiektów

## Operacje na plikach w c++

[Źródło](https://cpp0x.pl/kursy/Kurs-C++/Dodatkowe-materialy/Obsluga-plikow/305)

[Dokumentacja](https://en.cppreference.com/w/cpp/io/basic_fstream)

Tworząc programy, nie raz zajedzie potrzeba skorzystania z plików zapisanych na dysku, czy też stworzenia ich samemu. Przykładowym tego zastosowaniem są pliki konfiguracyjne, logi, czy też proste bazy danych (zapisane np w formacie CSV (Coma Separated Values)).

Względem języka c, c++ wychodzi nam naprzeciw i dostarcza bibliotekę `fstream`, która w znaczący sposób ułatwia operacje na plikach. Pierwszą rzeczą, na którą warto zwrócić uwagę jest dziedziczenie klas tej biblioteki po `basic_iostream`. Zapewne nic Ci to nie mówi. Wskazówka `cout` i `cin`, należą do tej samej „rodziny” klas. Możesz zobaczyć [tutaj](https://en.cppreference.com/w/cpp/io/basic_fstream) i [tutaj](https://en.cppreference.com/w/cpp/io/basic_ostream). Są tam diagramy, które obrazują co się w czym zawiera. Co za tym idzie, możemy korzystać z nich w podobny sposób (używając operatorów `<<` i `>>`).

Przejdźmy do istotniejszych rzeczy, czyli jak z tego korzystać i jakie mamy możliwości.

&nbsp;

### Inicjowanie

Zanim zaczniemy pracować na plikach, wyróżnijmy klasy, które nam to umożliwiają:

- `istream` - input file stream - czytanie plików
- `ofstream` - output file stream - zapisywanie plików
- `fstream` - file stream - czytanie i zapisywanie plików

Drugą rzeczą jest tryb otwierania pliku, możemy wyróżnić następujące:

- `app` - append dopisywanie danych do końca pliku
- `ate` - ustawienie wskaźnika na koniec pliku
- `binary` - Strumień ma być traktowany jako strumień binarny, a nie tekstowy
- `in` - plik ma być odczytywany
- `out` - plik ma być zapisywany
- `trunc` - usuwana jest zawartość pliku przy otwieraniu

Flagi te należą do klasy `ios` i można je łączyć za pomocą binarnej alternatywy (`|`).

Otworzyć pliki możemy przy pomocy konstruktora, bądź używając metody open. Pierwszym argumentem jest nazwa/ścieżka do pliku, a drugim tryb otwarcia pliku.

```c++
fstream testFile;
testFile.open("plik.txt", ios::in | ios::binary);

fstream testFile2("plik.txt", ios::in | ios::binary);
```

Sprawdzanie, czy plik został poprawnie otwarty można wykonać za pomocą kilku metod:
- `good()`
- `is_open()`
- `fail()`


### Pobieranie/zapisywanie danych

Istnieje wiele sposobów na zarządzanie danymi w plikach, pierwszym jest używanie strumienie, czyli na podobnej zasadzie co przy `cin` i `cout`

```c++
ifstream input("input.txt");
ofstream output("out.txt");

string word;
input >> word;
output << word;
```

Kolejnym sposobem jest wywoływanie metod:

- `get(char &_ch)` - pobieranie pojedynczego znaku
- `read(char *s, size)` - pobieranie bloku znaków
- `put(char &_ch)` - zapisywanie pojedynczego znaku
- `write(char *s, size)` - zapisywanie bloku znaków

Ostatnim sposobem są funkcje z biblioteki `string:

- `getline(stream, line)` - pobieranie całej linii


### Kończenie pracy

Po zakończonych operacjach należy pamiętać o zamknięciu pliku za pomocą metody `close()`. Spowoduje to dokonanie zmian w pliku na dysku. Można tego dokonać także za pomocą `flush()`, jednak należy pamiętać, aby tego nienadużywać, ponieważ jest to dość kosztowna czasowo operacja.

Kiedy należy stosować flush?

Jeżeli potrzebujemy, aby nasze dane były co jakiś czas zapisywane (np w logerze, chcemy, aby dane były zapisywane na bieżąco, a nie pod koniec działania programu). Szczególnym przypadkiem jest nieoczekiwane zakończenie programu, może się wtedy okazać, że dane nie zostaną zapisane do pliku.

&nbsp;

&nbsp;

## Przykłady

Podstawowe wczytywanie pliku:

```c++
ifstream input("input.txt");
if(input.is_open()) {
    string word;
    while(!input.eof()) {
        input >> word;
        cout << word << " ";
    }
    input.close();
} else {
    cout << "Error on opening file" << endl;
    exit(1);
}
```

Wczytywanie pliku linia po linii

```c++
ifstream input("input.txt");
if(input.is_open()) {
    string line;
    while(!input.eof()) {
        getline(input, line);
        cout << line << endl;
    }
    input.close();
} else {
    cout << "Error on opening file" << endl;
    exit(1);
}
```

Zapisywanie pliku:

```c++
ofstream output("input.txt");
if(output.is_open()) {
    for(int i = 0; i < 100; ++i) {
        output<< i << " student" << endl;
    }
    output.close();
} else {
    cout << "Error on opening file" << endl;
    exit(1);
}
```

&nbsp;

&nbsp;

### Zapisywanie binarne

Zupełnie osobno przedstawię zapisywanie binarne.

```c++
ofstream output("binaryFile.dat", ios::binary | ios::out);

if(!output.is_open()) {
    cout << "Error on opening file!" << endl;
    exit(1);
}

double tab[] = {3,5, 5.1, 4, 6.2001};
char *ptr = reinterpret_cast<char *>(tab);

for(int i = 0; i < sizeof(tab), ++i) {
    output.put(ptr[i]);
}

output.close();
```

```c++
ifstream input("binaryFile.dat", ios::binary | ios::in);

if(!input.is_open()) {
    cout << "Error on opening file!" << endl;
    exit(1);
}

double tab1[5];
char *ptr1 = reinterpret_cast<char *>(tab1);

for(int i = 0; i < sizeof(tab1), ++i) {
    input.get(ptr1[i]);
}

input.close();
for(int i = 0; i < 5, ++i) {
    cout << tab1[i] << endl;
}

```

&nbsp;

&nbsp;

## Zadanie

### Zadanie 1

Przekopiuj implementacje poniższej klasy, stwórz tablicę, która będzie przechowywać 5 obiektów, wypełnij różnymi danymi te klasy. Następnie zapisz je do pliku w trybie binarnym i później wczytaj. Zapisu dokonaj w funkcji main zapisując obiekt, nie twórzy metody w klasie, która będzie to zapisywać. Sprawdź czy wszystkie dane zostały poprawnie zapisane.

```c++
class Student {
private:
    double tab[5] = {0,0,0,0,0};
    string firstName;
    string lastName;
    vector<unsigned short> gradesList;
    
public:
    Student(const string &firstName, const string &lastName) : firstName(firstName), lastName(lastName) {}
    
    Student::Student() {}
    
    void setNames(const string &firstName, const string &lastName) {
        this->firstName = firstName;
        this->lastName = lastName;
    }
    
    void changeTabValue(unsigned index, double newValue) {
        if (index < 5) {
            tab[index] = newValue;
        }
    }
    
    void addGrade(unsigned short grade) {
        gradesList.push_back(grade);
    }
    
    void printAllData() {
        cout << firstName << " " << lastName << endl;
        for (double n: tab) {
            cout << n << " ";
        }
        
        cout << endl << endl << "Grades list:" << endl;
        
        for (auto grade: gradesList) {
            cout << grade / 10 << "." << grade % 10 << endl;
        }
    }
};
```

### Zadanie 2

Stwórz program, który będzie wczytywał plik csv, w którym są zapisane kolejno:
- numer linii
- przystanek początkowy
- przystanek końcowy
- operator

Następnie zapisywał w osobnym pliku linie tramwajowe, a w osobnym autobusowe (linie tramwajowe mają 1 lub 2 cyfry, a autobusowe 3), w takim samym układzie (takie same kolumny, taka sama ich kolejność).


&nbsp;

&nbsp;

&nbsp;

&nbsp;


## Przeciążanie operatorów

### Zanim zaczniesz

Zaimplementuj klasę wektor. Pamiętaj o podziale na pliki nagłówkowe i implementacyjne.

```c++
class Vector{
private:
    double x, y;
    
public:
    Vector();
    
    Vector(double x, double y);
    
    double length();
};
```

```c++
Vector::Vector(): x(0), y(0) {}

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::length() {
        return sqrt(x * x + y * y);
    }

```


&nbsp;

&nbsp;

### Przeładowanie/przeciążanie operatorów

[Dokumentacja](https://en.cppreference.com/w/cpp/language/operators)

[WikiBooks](https://pl.wikibooks.org/wiki/C%2B%2B/Przeciążanie_operatorów)

[c++0x](https://cpp0x.pl/artykuly/Inne-artykuly/Przeciazanie-operatorow-w-C++/15)

[c++0x cz2](https://cpp0x.pl/kursy/Programowanie-obiektowe-C++/Podstawy/Operatory/498)

[Dokumentacja MS](https://docs.microsoft.com/pl-pl/cpp/cpp/operator-overloading?view=msvc-160)


Język c++ udostępnia wiele rodzajów typów zmiennych pozwalających przechowywać różnego rodzaju dane. Może jednak się zdarzyć, że będziemy potrzebowali użyć jeszcze niestworzonego typu, bądź typu złożonego. Stworzenie klasy, która miałaby przedstawiać dany typ nie byłoby trudne, lecz dokonywanie operacji arytmetycznych, bądź porównań mogłoby być już problematyczne, a raczej niewygodne. Dlatego warto skorzystać z funkcjonalności, które udostępnia nam c++, przeciążania/przeładowywania operatorów. Polega ona na możliwości stworzenia własnej implementacji zachowania klas, gdy zostanie wywołana przy danym operatorze. Przykładowo przy `+`, czyli dodaniu do siebie dwóch obiektów (`obiektKlasy1 + obiektKlasy2`).

C++ umożliwia nam przeciążenie/przeładowanie następujących operatorów:
`+` `-` `*` `/` `%` `^` `&` `|` `~` `!` `=` `<` `>` `+=` `-=` `*=` `/=` `%=` `^=` `&=` `|=` `<<` `>>` `>>=` `<<=` `==` `!=` `<=` `>=` `<=>` (since C++20) `&&` `||` `++` `--` `,` `->*` `->` `( )` `[ ]` `new` `new[]` `delete` `delete[]`

&nbsp;

Ogólny przepis na stworzenie implementacji dla przeładowania/przeciążenia operatorów wygląda następująco:

`zwracanyTyp operator@(typPrawegoOperandu &nazwaPrawegoOperandu);`

Gdzie `@`, to operator, który chcemy przeciążyć.

&nbsp;

Aby lepiej zrozumieć działanie i zachowanie, stwórzmy klasę `Vector`, która będzie obrazować wektor. Do jego zapisu posłużymy się dwoma polami `x, y`.

```c++
class Vector{
private:
    double x, y;
    
public:
    Vector() {};
    
    Vector(double x, double y) : x(x), y(y) {}
    
    double length() {
        return sqrt(x * x + y * y);
    }
};
```

Operacje, jakich możemy dokonywać na wektorach to:

- otrzymywać wektor przeciwny
- dodawać
- odejmować
- iloczyn skalarny
- mnożenie przez skalar
- porównywać wektory

Moglibyśmy dla każdego działania stworzyć normalną metodę, lecz wykorzystajmy do tego operatory (po coś one są).

Zacznijmy od stworzenia funkcjonalności dodawania dwóch wektorów, wykorzystamy do tego operator `+` oraz `+=`.

```c++
class Vector {
private:
    double x, y;
    
public:
    Vector() {};
    
    Vector(double x, double y) : x(x), y(y) {}
    
    double length() {
        return sqrt(x * x + y * y);
    }
    
    Vector operator+(const Vector &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }
    
    Vector &operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
    }
};
```

Stworzyliśmy deklarację metod według przepisu. Zagadkowy skrót `rhs` oznacza right hand side.

Omówmy przykład z operatorem `+`. Nasze dodawanie wektorów będzie zwracać wektor, więc typem zwracanym jest `Vector`, następnie użyliśmy słowa kluczowego `operator` i operatora, którego chcieliśmy użyć, czyli `+`. Następnie tak, jak w zwykłej metodzie przyjęliśmy parametr (u nas jest to prawa strona równania), którym jest statyczna referencja na wektor. Powiedzieliśmy, że ta metoda jest stała i zaimplementowaliśmy ją.

Jak wywołać to, co stworzyliśmy? Jest kilka sposobów, najprostszy, to tak, jakbyśmy dodawali dwie zmienne.

```c++
int main() {
    Vector v1, v2(5,10);
    Vector v3 = v1 + v2;
    v3 = v1.operator+(v2);
}
```

&nbsp;

&nbsp;

## Zadania

1. Stwórz metodę `print` wypisująca dane o wektorze na ekran.
2. Zaimplementuj operator mnożenia przez skalar.
3. Zaimplementuj wybrane 2 działania na wektorach.



&nbsp;

&nbsp;

&nbsp;

## Przeciążenia operatorów razem z funkcjami zaprzyjaźnionymi

Zanim zaczniesz analizować dalszą część tego konspektu, upewnij się, że zrobiłeś już operator służący do mnożenia wektora przez skalar.
Spróbuj użyć zaimplementowanego operatora. Co zauważyłeś? Mnożenie tutaj nie jest przemienne!

Naprawmy to za pomocą funkcji zaprzyjaźnionych. Stwórz funkcję zaprzyjaźnioną, która będzie przeciążać operator.

Szkielet implementacji funkcji:

```c++
Vector operator*(const double &lhs, const Vector &rhs) {
    //Implementacja
}
```

Dodaj ciało funkcji i zadeklaruj przyjaźń w klasie Vector.

Sprawdź działanie i czy już mnożenie stało się przemienne.

&nbsp;

## Zadania

1. Przeciąż operator `<<`, który będzie zwracał obiekt w postaci ciągu znaków. (Zwracał zmienną z danymi wektora.) Sprawdź, czy zadziała:
```c++
Vector v1;
cout << v1 << endl;
```

Jeżeli zadziałało gratulacje, w przeciwnym razie dokonaj odpowiednich poprawek (musisz tutaj użyć funkcji zaprzyjaźnionej). Podpowiedź po lewej stronie równania musy być typ `std::ostream & lhs`, a zwracany typ to `std::ostream &`.

&nbsp;

2. Zaimplementuj pozostałe działania na wektorach.
3. Zacznij implementować drugi etap projektu.

&nbsp;

&nbsp;

### Zadanie trudniejsze

Zaimplementuj inteligenty wskaźnik dla tablic, który ma tylko jedną instancję, nie może być współdzielony, ani kopiowany. Wymagania:

1. Poprzez szablon klasa przyjmuje typ.
2. W konstruktorze przyjmujesz rozmiar tablicy.
3. Odwoływanie się do elementów tablicy ma następować po przez operator `[]` oraz metodę `get(int index)`
4. Zaalokowana pamięć ma być usuwana przy usuwaniu obiektu.
5. Należy usunąć konstruktor kopiujący
6. Należy przeciążyć operator `=`, aby przy przypisywaniu nowego obiektu dealokować pamięć i alokować na nowo.

&nbsp;

&nbsp;

### Zadanie jeszcze trudniejsze

To samo co wyżej, tyle, że dla wskaźnika, który może być współdzielony i kopiowany. 






