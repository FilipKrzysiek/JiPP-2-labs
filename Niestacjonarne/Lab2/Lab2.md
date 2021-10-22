# Laboratorium 2

###### Zadania stworzone na podstawie materiałów dr hab. Inż. Sergiy Fialko [link](https://torus.uck.pk.edu.pl/~fialko/index.html) 

#### Tematyka zajęć

- konstruktor kopiujący
- debugowanie
- kontenery
- szablony

# Konstruktor

Konstruktor jest to funkcja wywoływana przy tworzeniu obiektu. Jeżeli żadnego nie zadeklarujemy, to wywoływany jest 
domyślnie konstruktor bezparametrowy.

Wzór klasy:

```c++
class Person{
private:
    string firstName;
    string lastName;
    unsigned short brithYear;
    
public:
    Person(string fisrtName, string lastName, unsigned short brithYear);
};
```

Deklaracja konstruktora:

**Sposób 1**
```c++
Person::Person(string fisrtName, string lastName, unsigned short brithYear): fisrtName(fisrtName), lastName(lastName),
                brithYear(brithYear) {}
```

**Sposób 2**
```c++
Person::Person(string fisrtName, string lastName, unsigned short brithYear) {
    this->fisrtName = fisrtName;
    this->lastName = lastName;
    this->brithYear = brithYear;
}
```

# Destruktor

Destruktor jest wywoływany przy niszczeniu, usuwaniu obiektu, nie przyjmuje żadnych parametrów. Kiedy należy go używać?

&nbsp;


# Konstruktor kopiujący

Jeżeli nie zadeklarujemy konstruktora kopiującego, kompilator sam go wygeneruje. Z klasy wzorcowej utworzone zostaną 
kopie wszystkich obiektów w niej będących.

Przeanalizujmy prosty przypadek.

Deklaracja klasy (`Node.h`):

```c++
class Node {
private:
    double x, y;
    
public:
    Node();
    Node(double x, double y);
    
    void display();
    
    void updateValue(double x, double y);
};
```

Implementacja klasy (`Node.cpp`):

```c++
Node::Node() {
    x = 0;
    y = 0;
}

Node::Node(double x, double y): x(x), y(y) {}

void Node::display() {
    cout << "x: " << x << "\ty: " << y << endl;
}

void Node::updateValue(double x, double y) {
    this->x = x;
    this->y = y;
}
```

Funkcja main  (`main.cpp`):

```c++
int main() {
    Node n1;
    Node n1_1 = n1;
    
    n1.display();
    n1_1.display();
    n1.updateValue(1,1);

    n1.display();
    n1_1.display();
    
    system("PAUSE");
    return 0;
}
```

Czy program działa dobrze?

Dokonajmy teraz małych zmian:
- Dodaj dynamicznie alokowaną tablicę przechowującą wartości typu double
- Dodaj zmienną przechowującą ilość tych wartości
- Dodaj Destruktor czyszczący pamięć
- Dodaj metodę dodającą do tych wartości jeszcze jedną
- Dodaj metodę wypisująca zawartość tej tablicy
- Dodaj metodę zmieniającą wartość w tej tablicy na podanym indeksie

```c++
void addNewValue(double n);

void printValues();

void changeValueOn(double newValue, int indx);
```

Użyj nowego pliku main:

```c++
int main() {
    Node n1(83, 5);
    n1.addNewValue(80);
    n1.addNewValue(85.1);
    n1.addNewValue(603.945);
    
    Node n1_1 = n1;
    
    n1.print();
    n1.printValues();

    n1_1.print();
    n1_1.printValues();
    
    n1.changeValueOn(0, 0);
    n1.changeValueOn(1, 0);
    n1.changeValueOn(1, 0);

    n1.print();
    n1.printValues();

    n1_1.print();
    n1_1.printValues();
    
    system("PAUSE");
    return 0;
}
```


Przetestuj działanie. Jeżeli nie działa/działa źle odpowiedz na pytanie, dlaczego i napraw.

&nbsp;

&nbsp;

&nbsp;

# Funkcje zaprzyjaźnione

Funkcje zaprzyjaźnione pozwalają na dostęp do prywatnych/chronionych składowych klasy. 

## Zadania

1. Stwórz klasę `Traingle` (plik nagłówkowy osobno implementacja osobno). Ma zawierać ona następujące pola:
   - 3 `Node`, które będzie przechowywać informacje o wierzchołkach
   - nazwa, która będzie przechowywać nazwę trójkąta
2. Stwórz metodę `display`, która wyświetla informacje o wszystkich wierzchołkach.
3. Dodaj do funkcji main:

```c++
Node a, b(5,8), c(1, 16);
Triangle triangle(a, b, c, "First Triangle");

triangle.display();
```

4. Sprawdź działanie
5. Pod deklaracją klasy zadeklaruj funkcję `double pointsDistance(Node a, Node b);`
6. W klasie `Node` zadeklaruj przyjaźń z funkcją z powyższego punktu
7. W tej funkcji obliczaj odległość pomiędzy dwoma punktami
8. W klasie `Triangle` dodaj metodę `double distance(int firstPointIndex, int secondPointIndex);`. Przyjmuje ona 
   numery wierzchołków, pomiędzy którymi ma być policzona odległość.
9. Sprawdź działanie, dodając następujące wywołania do funkcji main.

```c++
cout << "Distance between first and second point is " << triangle.distance(0,1) << endl;
```

10. Pod klasą `Triangle` stwórz funkcje wraz z jej przeciążeniami:
   - `void showTriangleData(Triangle triangle);`
   - `void showTriangleData(Triangle &triangle);`
   - `void showTriangleData(Triangle *triangle);`
11. Powyższe funkcje powinny wykonywać to samo zadanie, czyli wyświetlać wszystkie punkty w trójkącie (metoda `display`)
12. Używając debugowania, wskaż różnice pomiędzy wywołaniami.  






