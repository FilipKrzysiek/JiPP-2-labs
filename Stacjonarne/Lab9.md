## Szablony

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
template<typename type, int value>
class Container {
private:
    type myVal = value; 
    
    public:
    type getValue() {
        return myVal;
    }
};
```

&nbsp;

### Zadania

1. Stwórz klasę przechowującą x elementów typu przekazanego przez szablon. Klasa mw:
    - W konstruktorze przyjmować ilość elementów, które będzie przechowywać
    - Posiadać metodę do odczytywania wartości na podanym indeksie
    - Ustawiania wartości na podanym indeksie
    - Pobieranie wielkości tablicy
2. Sprawdź, czy działa powyższa klasa.
3. Stwórz funkcję wypisującą na ekran rozmiar typu przekazanego przez szablon. Do sprawdzania rozmiaru służy `sizeof`.