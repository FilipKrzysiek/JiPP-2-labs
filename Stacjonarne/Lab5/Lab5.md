# Laboratorium 5 (8/9.11.2021)

Celem tego laboratorium jest poznanie konstruktorów kopiujących oraz dowiedzenie się, dlaczego są ważne. Dodatkowo
poznanie przeciążenia/przeładowania operatorów i poznanie działania `static` oraz wskazania różnicy względem `const`.

# 1. Konstruktory kopiujące

Zanim zaczniemy omawiać tematykę konstruktorów kopiujących przetestujmy działanie kodu znajdującego
się [tutaj](Examples/E1NoCopyingConstructor).

Jakie anomalie zauważyłeś?<sup id="answear1Sourece">[1](#answear1)</sup>

Dodaj destruktor, który będzie zwalniał pamięć (dla `x` i `y`). Co się stało? Czy program działa poprawnie i
dlaczego?<sup id="answear2Sourece">[2](#answear2)</sup>

### Deklaracja

Deklaracja konstruktora kopiującego wygląda podobnie do zwykłego, tylko tyle, że przekazywana w parametrze (przez referencję — z &) jest druga klasa. Jej ciało powinno zawierać w sobie przepisanie wartości i jeżeli występuje taka konieczność zaalokowanie pamięci.

```c++
ClassName(ClassName &className) {
    //copy values
}
```

Taki konstruktor można wywołać, tak samo, jak inny konstruktor, albo pop przez przypisanie wartości za pomocą znaku = (tylko przy deklarowaniu obiektu (zmiennej)).

```c++
ClassName c1;
ClassName c2(c1);
Classname c3 = c1;
```

Stwórz konstruktor kopiujący we wcześniej analizowanym przykładzie. Sprawdź, czy program teraz działa poprawnie.

&nbsp;

&nbsp;

## 1.1. Konstruktor kopiujący teoria
#### To samo, co przed chwilą, tylko opisane, a nie zademonstrowane na przykładzie.

Konstruktory kopiujące mają za zadanie wykonywanie kopii obiektu. Kompilator domyślnie tworzy konstruktory kopiujące, lecz dokonuje kopii wartości każdej zmiennej. Problem z jego działaniem zaczyna być widoczny przy alokowaniu pamięci w klasie, ponieważ domyślny konstruktor kopiujący kopiuje wskaźnik, a nie alokuje na nowo pamięć i dopiero później dokonuje kopii.

Konstruktor kopiujący jako parametr przyjmuje **referencję** do klasy tego samego typu jakiej jest. W jej ciele należy samemu, ręcznie zadeklarować kopiowanie każdej wartości, bądź alokowanie pamięci.

```c++
class ExampleClass{
private:
    double p1;
    double *p2;
    
public:
    ExampleClass() {
        p2 = new double;
    }

    ExampleClass(ExampleClass& exampleClass) {
        p1 = exampleClass.p1;
        p2 = new double;
        *p2 = *exampleClass.p2;
    }
    
    ~ExampleClass() {
        delete p2;
    }
};
```



&nbsp;

&nbsp;

## 1.2. Zadania

1. Popraw implementację z przykładu (folder examples).
3. Stwórz klasę pojazd. Musi ona posiadać pola:
   1. numer rejestracyjny
   2. nazwa
   3. ilość miejsc
   4. tablicę alokowaną dynamicznie. Ma ona przechowywać imię i nazwisko pasażera, bądź informacje o tym, że miejsce jest puste (np „puste”). Alokuj ją w konstruktorze.
   6. markę i typ
4. Stwórz konstruktor przyjmujący powyższe wartości. Nie musisz przekazywać listy miejsc, w konstruktorze ustaw, że wszystkie są puste.
5. Stwórz metodę wypisującą na ekran wszystkie informacje.
6. Stwórz metodę zmieniającą informację o pasażerze na konkretnym miejscu (pierwszy parametr, to numer miejsca, a drugi informacja o pasażerze).
7. Stwórz konstruktor kopiujący.
8. Stwórz gettery dla nazwy, numeru rejestracyjnego oraz marki i typu.
9. Stwórz setter dla nazwy i numeru rejestracyjnego.

&nbsp;

&nbsp;

&nbsp;

&nbsp;


# 2. Stałe i static

[Tutaj o tym przeczytasz](http://wojtek-m.blogspot.com/2010/08/wszystko-co-musisz-wiedziec-o-const-w-c.html)

## 2.1. Stałe

Wydawać by się mogło, że jest to bardzo prosty temat, deklarowanie stałej, czyli wartości, która nie będzie ulegać modyfikacjom podczas życia zmiennej. Niestety (albo na szczęście) jest wiele „ciekawostek” i niuansów związanych z nimi. Zacznijmy od zdefiniowania dwóch pojęć:

> - `const` - oznacza mniej więcej „obiecuję, że nie zmienię tej wartości”...
> - `constexpr` - oznacza mniej więcej „wartość zostanie obliczona w czasie kompilacji”...

*C++ podróż po języku dla zaawansowanych Wydanie II - Bjarne Stroustrap*

&nbsp;

### 2.1.1. Stałe zmienne

Najbardziej intuicyjna dziedzina stałych. Zdefiniowana zmienna może zostać zainicjowana tylko i wyłącznie podczas deklaracji zmiennej, później nie może być już modyfikowana.

```c++
const int k = 0;
cout << k << endl;

const int k1; //błąd kompilacji error: uninitialized const
k = 10;  //błąd kompilacji error: assignment of read-only variable
```

&nbsp;

### 2.1.2. Stałe pola klas


Deklarowanie stałych wartości pól podczas implementacji klas jest oczywiste i wygląda tak samo, jak w poprzedniej części. Zauważmy jednak, że wartość jest przypisywana podczas tworzenia tej zmiennej. Rodzi się pytanie, czy wartość stałej zmiennej można przypisać w konstruktorze. Spróbuj skompilować poniższy kod:

```c++
class TestClass {
private:
    const int t = 0;

public:
    TestClass(const int t) {
        this->t = t;
    }
};
```

Udało się? No nie, to teraz spróbuj ten przykład:

```c++
class TestClass {
private:
    const int t = 0;

public:
    TestClass(const int t) : t(t) {}
};
```

Teraz się udało? Tak, zadziałało. Różnica wynika z tego, że w drugiej wersji podaliśmy listę inicjalizyjną, czyli zanim obiekt został stworzony, to przypisane zostały zamiast domyślnych wartości, to te przekazane przez parametry.

Mówiąc łopatologicznie, w pierwszej wersji został stworzony obiekt, gdzie wartości pól dostały wartości domyślne, a następnie próbowaliśmy im przypisać nowe wartości. Drugi przykład podczas tworzenia obiektu, zamiast przypisać wartości domyślne, przypisał przekazane wartości. 

&nbsp;

### 2.1.3. Stałe metody

Niektóre metody w naszych klasach nie modyfikują pól naszej klasy albo wręcz oczekujemy, aby tego ine robiły. W takim przypadku możemy zadeklarować stałą metodę. Robi się to poprzez dodanie na końcu deklaracji słowa `const` i oznacza to, że metoda nie modyfikuje żadnych atrybutów klasy. Znasz jakieś takie metody?

```c++
class TestClass {
private:
    const int t = 0;

public:
    TestClass(const int t) : t(t) {}
    
    void print() const {
        cout << t << endl;
    }
};
```

&nbsp;

### 2.1.4. Stałe wskaźniki

Najtrudniejsza część stałych. Należy nauczyć się rozróżniać stały wskaźnik i wskaźniki na stałe. Poniższe dwa zapisy wygladają bardzo podobnie, lecz znaczą zupełnie coś innego.

```c++
const int * k;
int *const k1;
```

Zanim zaczniemy szukać różnicy pomiędzy tymi dwoma zapisami, to zdefiniujmy sobie operacje, jakie możemy chcieć na nich wykonywać:
- odczyt wartości
- odczyt adresu
- modyfikacja wartości
- modyfikacja adresu

W stałych zabroniona jest modyfikacja, a odczyt jest zawsze dostępny, więc dwa pierwsze warunki będą zawsze spełnione.

&nbsp;

Zacznijmy od **wskaźnika na stałą**, jak nazwa wskazuje: wskaźnik wskazuje na stałą wartość.

```c++
int cVal = 314;
const int *p = &cVal;
```

Czy będzie można zmodyfikować wartość zmiennej `p`? Jest ona stałą, więc nie możemy tego zrobić.  

Czy będzie można zmodyfikować adres zmiennej `p`? Adres nie jest stały, więc będzie to możliwe.

Przetestuj, czy faktycznie tak to działa:

```c++
int cVal = 314;
const int *p = &cVal;

*p = 628;

const int cVal2 = 666;
p = &cVal2;
```

> Możemy modyfikować wskaźnik, ale nie możemy modyfikować wartości.

&nbsp;

Przejdźmy teraz do **stałego wskaźnika**, czyli jak nazwa nam wskazuje: wskaźnik jest niezmienny.

```c++
int cVal = 314;
int *const p = &cVal;
```

Czy będzie można zmodyfikować wartość zmiennej `p`? Zmienna nie jest stała, więc będzie to możliwe.

Czy będzie można zmodyfikować adres zmiennej `p`? Adres jest stały, więc nie będzie to możliwe.

Przetestuj, czy faktycznie tak to działa:

```c++
int cVal = 314;
int *const p = &cVal;

*p = 628;

int cVal2 = 666;
p = &cVal2;
```

> Możemy modyfikować wartość, ale nie możemy modyfikować wskaźnika.

&nbsp;

**Czy można połączyć obydwie własności?**

Oczywiście, że tak, stworzymy wtedy zmienną, gdzie nie będzie można modyfikować wartości i wskaźnika (adresu).

```c++
int cVal = 314;
const int* const youCantModifyMe = cVal; 
```

&nbsp;


|                  | Modyfikowanie wartości | Modyfikowanie wskaźnika |
|------------------|------------------------|-------------------------|
| `const int*`       | <center>❌ </center> |  <center>✔ </center>  |
| `int *const`       | <center>✔ </center>  | <center>❌ </center>  |
| `const int* const` | <center>❌ </center>  | <center>❌ </center> |

&nbsp;

### 2.1.5. Referencja do stałych

Referencja z definicji jest stała, czyli nie można zmienić jej adresu, na jaki wskazuje. Zostaje nam jedynie referencja do stałych, która jest analogiczna do wskaźnika na stałe, tylko tyle, że używamy `&` zamiast `*`.

```c++
int cVal = 314;
const int& k = cVal;
```

W powyższym przypadku nie można zmienić adresu, na jaki wskazujemy, ani wartości zmiennej.


&nbsp;

### 2.1.6. Po co to wszystko?    

W przypadku stałych zmiennych, stałych pól i stałych metod sposób użycia dość łatwo sobie wyobrazić. Natomiast wskaźniki i referencja, po co się z tym męczyć?

Zacznijmy od referencji na stałe, jak wiemy referencja do zmiennej, pozwala na nie tworzenie kopii zmiennej, tylko bezpośrednim „pracowaniu” na niej. Idealnym przykładem jest przekazywanie zmiennej do funkcji bądź metody. Przekazując przez referencję, oszczędzamy na tworzeniu kopii zmiennej, czyli nasz program jest optymalniejszy.

```c++
double doSth(double &a) {
    //doSth
}

double doSth1(const double &a) {
    //doSth
}
```

W pierwszym przypadku jesteśmy narażeni na zmianę wartości zmiennej `a`, natomiast w drugim przypadku zabezpieczyliśmy się przed tym, a zyskaliśmy na optymalności naszej aplikacji.

&nbsp;

&nbsp;

```c++
double calc(double * array) {
    //doSth
}

double calc1(const double * array) {
    //doSth
}
```

Powyższy przypadek obrazuje nam, kiedy można użyć wskaźnika na stałą. Pozwala on nam zabezpieczyć wartości przekazane przez wskaźnik przed modyfikacjami.

&nbsp;

&nbsp;

## 2.2. Static

### 2.2.1. Funkcje

Deklaracja zmiennej statycznej w funkcji pozwala na nieusuwanie jej wartości wraz z zakończeniem funkcji. Działa to tak, ponieważ zmienna statyczna zostaje zapisana w tej samej pamięci co zmienne globalne, lecz dostęp do niej jest tylko z poziomu funkcji, w której została stworzona.

```c++
int counter() {
    static int i = 10;
    ++i;
    return i;
}

int main () {
    cout<< "Wywołanie 1: " << counter() <<endl;
    cout<< "Wywołanie 2: " << counter() <<endl;
    cout<< "Wywołanie 3: " << counter() <<endl;
    cout<< "Wywołanie 4: " << counter() <<endl;
    cout<< "Wywołanie 5: " << counter() <<endl;
    cout<< "Wywołanie 6: " << counter() <<endl;
}
```

Wynik działania:

```console
Wywołanie 1: 11
Wywołanie 2: 12
Wywołanie 3: 13
Wywołanie 4: 14
Wywołanie 5: 15
Wywołanie 6: 16
```


&nbsp;

### 2.2.2. Klasy

W klasie mamy możliwość tworzenia statycznych pól i metod. Zacznijmy od pól, będą one funkcjonowały podobnie, jak przy funkcjach, ale dodatkowo będzie istniała jedna ciekawa funkcjonalność. Statyczne pola będą współdzieliły swoja wartość pomiędzy obiektami. Przeanalizuj poniższy przykład.

```c++
class Kasa {
private:
    static long moneyAmountAll;
    long moneyInCashRegister = 0;

public:
    void addTransaction(long amount) {
        moneyAmountAll += amount;
        moneyInCashRegister += amount;
    }

    void printData() {
        cout << "All money: " << moneyAmountAll << "gr\n";
        cout << "Money in this cash register: " << moneyInCashRegister << "gr\n";
    }
};

long Kasa::moneyAmountAll = 1000;

int main () {
    Kasa kasa1;
    Kasa kasa2;

    cout << "Kasa1" << endl;
    kasa1.printData();

    cout << "Kasa2" << endl;
    kasa2.printData();

    cout << "Transactions" << endl << endl;
    kasa1.addTransaction(5000);
    kasa2.addTransaction(120);

    cout << "Kasa1" << endl;
    kasa1.printData();

    cout << "Kasa2" << endl;
    kasa2.printData();
}
```

Wynik działania:

```console
Kasa1
All money: 1000gr
Money in this cash register: 0gr
Kasa2
All money: 1000gr
Money in this cash register: 0gr
Transactions

Kasa1
All money: 6120gr
Money in this cash register: 5000gr
Kasa2
All money: 6120gr
Money in this cash register: 120gr
```

Stworzyliśmy klasę, gdzie zadeklarowaliśmy zmienną statyczną. Następnie została ona zdefiniowana pod klasą i przypisana początkowa wartość, jest to wymagane, aby zadeklarować zmienną statyczną poza klasą, jeżeli tego nie zrobimy nasz program nie skompiluje się. Przeanalizujmy teraz działanie. Stworzyliśmy dwie kasy, w których początkowo było po 0gr. Dodaliśmy transakcje na różne kwoty do obydwóch kas, zwiększyła się ilość pieniędzy w poszczególnych kasach, jak i ilość wszystkich pieniędzy. Zadziałało to jak oczekiwaliśmy.

&nbsp;

&nbsp;

Statyczne metody, głównym ich atutem jest możliwość ich wywoływania bez potrzeby tworzenia obiektu, niestety niesie to ze sobą pewną cenę. Nie można w nich odwoływać się do niestatycznych pól i metod klasy.

```c++
class TestClass{
public:
    static void printHelloWorld() {
        cout << "Hello world!" << endl;
    }   
};

int main() {
    TestClass::printHelloWorld();
    return 0;
}
```

&nbsp;

&nbsp;

## 2.3. Zadania

1. Dla przykładu z części pierwszej stwórz gettery i settery zgodnie z powyższymi informacjami.
2. Przetestuj wszystkie przykłady z rozdziału 2.1.4.
3. Do klasy z zadania 2. (klasa samochód) dodaj statyczne prywatne pole `najnowsza wersja oprogramowania` oraz prywatne zwykłe pole `zainstalowana wersja oprogramowania` (przechowuje liczbę, albo string np `v1.0`).
4. Zainicjuj pola.
5. Stwórz metody: wypisz wersję oprogramowania oraz zaktualizuj oprogramowanie (zmienia wartość zmiennej `zainstalowana wersja oprogramowania` na wartość z `najnowsza wersja oprogramowania`).
6. Stwórz statyczną metodę `opublikujNoweOprogramowanie`, która będzie przyjmować nową wersję oprogramowania (numer, albo nazwę) i będzie podmieniać tę informację w polu `najnowsza wersja oprogramowania`.
7. Przetestuj działanie



&nbsp;

&nbsp;

&nbsp;

&nbsp;


# 3. Przeładowanie/przeciążanie operatorów

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












&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

&nbsp;

### Odpowiedzi

<b id="answear1">[1]</b> program działa niepoprawnie, ponieważ zmieniając wartości w punktach `p1` i `p2` zmieniają się
również wartości w punktach `p1c` i `p2c`. [↩](#answear1Sourece)

<b id="answear2">[2]</b> Program powinien działać nie poprawnie, powinien kończyć działanie zaraz po wyjściu z sekcji,
gdzie zostały zadeklarowane zmienne `p1c` i `p2c` (zaraz przed coutem z komunikatem `End program`). Dzieje się tak,
ponieważ domyślny konstruktor kopiujący kopiuje referencję do zmiennej i przy utworzeniu kopii klasy mamy 2 wskaźniki
odwołujące się do tego samego adresu. Zwalniając raz pamięć, nie możemy zrobić tego po raz drugi i dlatego pojawia się
błąd, który mówi nam dosłownie co jest nie tak (`free(): double free detected in tcache 2` - wykryto podwójne zwalnianie pamięci) [↩](#answear2Sourece)

