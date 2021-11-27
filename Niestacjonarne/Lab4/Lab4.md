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

Przekopiuj implementacje poniższej klasy, stwórz tablicę, która będzie przechowywać 5 obiektów, wypełnij różnymi danymi te klasy. Następnie zapisz je do pliku w trybie binarnym i później wczytaj. Sprawdź czy wszystkie dane zostały poprawnie zapisane.

```c++
class Student {
private:
    double tab[5];
    string firstName;
    string lastName;
    vector<unsigned short> gradesList;
    
public:
    Student(const string &firstName, const string &lastName) : firstName(firstName), lastName(lastName) {}
    
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

Następnie zapisywał w osobnym pliku linie tramwajowe, a w osobnym autobusowe (linie tramwajowe mają 2 cyfry, a autobusowe 3), w takim samym układzie (takie same kolumny, taka sama ich kolejność).


