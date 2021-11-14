# Laboratorium 6 15/16.11.2021


# 1. Przeładowanie/przeciążanie operatorów

[Dokumentacja](https://en.cppreference.com/w/cpp/language/operators)

[WikiBooks](https://pl.wikibooks.org/wiki/C%2B%2B/Przeciążanie_operatorów)

[c++0x](https://cpp0x.pl/artykuly/Inne-artykuly/Przeciazanie-operatorow-w-C++/15)

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

Omówmy ten z operatorem `+`. Nasze dodawanie wektorów będzie zwracać wektor, więc typem zwracanym jest `Vector`, następnie użyliśmy słowa kluczowego `operator` i operatora, którego chcieliśmy użyć, czyli `+`. Następnie tak, jak w zwykłej metodzie przyjęliśmy parametr (u nas jest to prawa strona równania), którym jest statyczna referencja na wektor. Powiedzieliśmy, że ta metoda jest statyczna i zaimplementowaliśmy ją.

Jak wywołać to, co stworzyliśmy? Jest kilka sposobów, najprostszy, to tak, jakbyśmy dodawali dwie zmienne.

```c++
int main() {
    Vector v1, v2(5,10);
    Vector v3 = v1 + v2;
    v3 = v1.operator+(v2);
}
```

W dalszej części będzie o innych operatorach.

&nbsp;

&nbsp;

## Zadania

1. Stwórz metodę `print` wypisująca dane o wektorze na ekran.
2. Zaimplementuj pozostałe metody przy użyciu operatorów.
3. Zaplanuj implementację klasy dla liczb urojonych.
4. Zaimplementuj klasę dla liczb urojonych.
