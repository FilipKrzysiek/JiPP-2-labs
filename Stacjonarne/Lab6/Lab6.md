# Laboratorium 6 15/16.11.2021

# Zanim zaczniesz

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

# 1. Funkcje zaprzyjaźnione

Funkcja zaprzyjaźniona z klasą to funkcja, która nie jest składnikiem klasy oraz ma dostęp do wszystkich - w tym prywatnych - składników klasy
Wewnątrz definicji klasy wystarczy umieścić deklarację tej funkcji poprzedzoną słowem friend. Funkcje zaprzyjaźnione pozwalają na dostęp do prywatnych/chronionych składowych klasy.

To nie funkcja się zaprzyjaźnia - tylko klas adeklaruje przyjaźń z funkcją.


```c++
 class K {
   //poprzez domniemanie jest private: 
   friend void fun( K& ); // deklaracja przyjaźni
   friend void Y::fun( K& ); // deklaracja przyjaźni funkcji składowej klasy 'Y'
   int x;
 };

 void fun( K& obiekt ) {
   obiekt.x = 12; // nie byłoby możliwe to przypisanie bez określenia przyjaźni
   cout << obiekt.x;
 }
```

&nbsp;

## Zadania

Klasę [`Node` znajdziesz tutdaj.](Code)

1. Pod deklaracją klasy `Node` zadeklaruj funkcję `double pointsDistance(Node a, Node b);`
2. W klasie `Node` zadeklaruj przyjaźń z funkcją z powyższego punktu
3. W tej funkcji obliczaj odległość pomiędzy dwoma punktami
4. Sprawdź działanie tej funkcji.


&nbsp;

&nbsp;


# 2. Przeładowanie/przeciążanie operatorów

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
2. Zaimplementuj pozostałe metody przy użyciu operatorów.
3. Zaplanuj implementację klasy dla liczb urojonych.
4. Zaimplementuj klasę dla liczb urojonych.



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

&nbsp;

## Zadania funkcje zaprzyjaźnione część dalsza

1. Stwórz klasę `Traingle` (plik nagłówkowy osobno implementacja osobno). Ma zawierać ona następujące pola:
   - 3 `Node`, które będzie przechowywać informacje o wierzchołkach
   - nazwa, która będzie przechowywać nazwę trójkąta
2. Stwórz metodę `display`, która wyświetla informacje o wszystkich wierzchołkach.
3. Stwórz przeciążenie operatora `<<`, które pozwoli za pomocą `cout` wypisać dane na ekran.
4. Dodaj do funkcji main:

```c++
Node a, b(5,8), c(1, 16);
Triangle triangle(a, b, c, "First Triangle");

triangle.display();
cout << triangle << endl;
```

4. Sprawdź działanie
5. W klasie `Triangle` dodaj metodę `double distance(int firstPointIndex, int secondPointIndex);`. Przyjmuje ona 
   numery wierzchołków, pomiędzy którymi ma być policzona odległość.
6. Sprawdź działanie, dodając następujące wywołania do funkcji main.

```c++
cout << "Distance between first and second point is " << triangle.distance(0,1) << endl;
```

10. Pod klasą `Triangle` stwórz funkcje wraz z jej przeciążeniami:
   - `void showTriangleData(Triangle triangle);`
   - `void showTriangleData(Triangle &triangle);`
   - `void showTriangleData(Triangle *triangle);`
11. Powyższe funkcje powinny wykonywać to samo zadanie, czyli wyświetlać wszystkie punkty w trójkącie (metoda `display`). Sprawdź, czy można użyć takiego przeciążenia.
12. Używając debugowania, wskaż różnice pomiędzy wywołaniami.
