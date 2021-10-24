# Laboratorium 3

###### Zadania stworzone na podstawie materiałów dr hab. Inż. Sergiy Fialko [link](https://torus.uck.pk.edu.pl/~fialko/index.html)

#### Tematyka zajęć

- kontenery
- szablony
- dziedziczenie
- polimorfizm


# Kontenery

Korzystanie z tablic alokowanych dynamicznie jest nie wygodne, a szczególnie wtedy, gdy nie znamy ich wielkości i będzie się ona zwiększać.
Tutaj z pomocą przychodzą nam kontenery. Podstawowym, o którym warto wspomnieć jest `vector`. W [dokumentacji](https://en.cppreference.com/w/cpp/container)
możesz zobaczyć jakie inne kontenery mamy jeszcze do dyspozycji.

Omówmy teraz podstawowe funkcje `vectora`.

Do jego poprawnego działania musimy zaimportować odpowiednią bibliotekę:

```c++
#include <vector>
```

Zadeklarujmy vector intów:

```c++
vector<int> intVector;
```

Dodajmy element na koniec:

```c++
intVector.push_back(5);
```

Pobierzmy jego rozmiar:

```c++
intVector.size();
```

Odczytajmy wartość na indeksie 1:

```c++
cout << intVector[1] << endl;
```

### Zadania

1. Stwórz nowy projekt.
2. Stwórz wektor, który będzie przechowywał długości boków.
3. Wczytuj długości boków, dopóki nie zostanie podana liczba <= 0.
4. Wypisz na ekranie liczbę boków.
5. Wypisz na ekran długości wszystkich boków.
6. Oblicz obwód figury.
7. Oblicz sumę długości parzystych boków.
8. Oblicz sumę długości nieparzystych boków.
9. Oblicz somę boków połowy boków i drugiej połowy.

&nbsp;

&nbsp;

&nbsp;

# Szablony

Język c++ wymaga od nas zawsze deklarowania typów obiektów, jest to plusem, ale i niestety zarazem minusem. 
Rozważmy przykładowy przypadek. Chcemy stworzyć prostą funkcję dodającą dwie liczby. Powstaje pierwsze pytanie
jakiego typu będą to zmienne, czyli musimy użyć przeciążenia, ale zajmie to nam wiele czasu i wiele linii kodu
na pisaniu tego samego.
Z rozwiązaniem tego problemu dąży do nas c++ z szablonami. W szablonie możemy zadeklarować, jakiego 
typu będą nasze elementy wewnątrz klasy, bądź funkcji. Zobaczmy prosty przykład:

```c++
template <typename type>
type add(type a, type b) {
    return a + b;
}
```

Stworzenie naszego szablonu polegało na dopisaniu linii `tempalte ...` przed deklaracją funkcji. W nawiasach znajduje się
deklaracja typu. Wywołanie takiej funkcji:

```c++
int a = 5, b = 6;
cout << add<int>(a, b) << endl;
```

Szablony również można używać z klasami, bądź przekazywać inne parametry i inną ich ilość.

```c++
template<typename type, type value>
class Container {
private:
    type myVal = value; 
    
    public:
    type getValue() {
        return myVal;
    }
};
```

### Zadania

1. Stwórz klasę


# Dziedziczenie

Dziedziczenie najprościej określić, jako deklarowanie najpierw bardziej ogólnego obiektu, a następnie
bardziej wyspecjalizowanego. 

# Polimorfizm

Najprościej rzecz ujmując możemy przechowywać inną klasę w innej. Najważniejsze, aby zgadzały się metody, które będą używać,
ponieważ przepis na klasę będzie brany z klasy bazowej (zadeklarowanego typu). Przykładowa deklaracja:

```c++
Figure fig = Circle();
```

Klasa Figure jest klasą bazową i posiada przepis na naszą klasę, część metod pokrywa się z klasą Circle.
Przykładem niech będzie `Figure`.

1. Stwórz klasę `Figure`.
2. Zadeklaruj metodę virtualną `double getArea()`.
3. Stwórz klasę `Circle` z konstruktorem, który przyjmuje promień.
4. Odziedzicz klasę `Figure`, zaimplementuj `getArea`.
5. Stwórz klasę `Rectangle` z konstruktorem, który przyjmuje długości boków.
6. Odziedzicz klasę `Rectangle`, zaimplementuj `getArea`.
7. Użyj następującego pliku main
```c++
int main() {
    Figure circle = Circle(5);
    Figure rectangle = Rectangle(5, 18);
    
    cout << "Circle area: " << circle.getArea() << endl;
    cout << "Rectangle area: " << rectangle.getArea() << endl;
}
```




