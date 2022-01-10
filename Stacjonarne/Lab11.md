# Laboratorium 11 (10.01.2022/17.01.2022)

Celem tego laboratorium jest zapoznanie się z tematyką konwersji i wskaźników inteligentnych.

# 1. Konwersje 

Konwersja zmiennych z jednego typu na inny nazywana jest konwersją typu. Celem konwersji typów jest sprawienie, aby zmienne jednego typu danych współpracowały ze zmiennymi innego typu danych. Przeprowadzamy to, aby skorzystać z niektórych aspektów reprezentacji typów i hierarchii. Kiedy więc konwersja typu będzie korzystna?

Konwersje typów mogą służyć do wymuszenia prawidłowego typu obliczeń matematycznych, które należy wykonać. Znalezienie sumy dwóch zmiennych, jednej typu int, a drugiej typu float jest dobrym przykładem na zademonstrowanie użycia konwersji typu. Aby uzyskać sumę dwóch zmiennych, musisz przekonwertować zmienną int na zmiennoprzecinkową.

Mamy dwie formy konwersji typów:

- Niejawna konwersja typu
- Jawna konwersja typu

&nbsp;

### Niejawna konwersja typu

Niejawna konwersja typu, znana również jako automatyczna konwersja typu, jest przeprowadzana przez kompilator bez konieczności wykonywania akcji przez użytkownika. Ma to miejsce, gdy występuje wyrażenie więcej niż jednego typu danych, w takim przypadku następuje konwersja typu w celu uniknięcia utraty danych.

Typ danych każdej zmiennej jest zmieniany na typ danych zmiennej o największym typie danych.

Kolejność automatycznej konwersji typów jest podana poniżej:

```
bool -> char -> short int -> int -> unsigned int -> 
long int -> unsigned long int -> long  long int -> 
float -> double -> long double 
```

przykład:
```c++
int x = 20;  
short int y = 5;  
int z = x + y; 
```

W powyższym przykładzie istnieją dwie zmienne o różnych typach -  x i y, gdzie x jest typem int, a y jest typem short int.  owa zmienna z jest również typem całkowitym, który przechowuje zmienne x i y. Ale kompilator C++ automatycznie konwertuje wartość typu danych o niższej randze (short int) na wyższy typ (int) przed otrzymaniem sumy dwóch liczb. W ten sposób pozwala uniknąć utraty danych, przepełnienia lub utraty znaku w niejawnej konwersji.

Program do konwersji typu int na typ zmiennoprzecinkowy przy użyciu niejawnej konwersji typu

Stwórzmy program do konwersji mniejszych typów danych na wyższe typy przy użyciu niejawnej konwersji typów.

```c++
#include <iostream>  
using namespace std;   
int main ()  
{  
// wartość całkowitą
int num1 = 25;  
// wartość zmiennoprzecinkowa
float num2;  
// konwertujemy wartość int na zmienną zmiennoprzecinkową za pomocą niejawnej konwersji
num2 = num1;      
cout <<  " The value of num1 is: " << num1 << endl;  
cout <<  " The value of num2 is: " << num2 << endl;  
return 0; 
}  

```

Program do konwersji typu danych double na int przy użyciu niejawnej konwersji typu

Stwórzmy program do konwersji wyższego typu danych na niższy typ przy użyciu niejawnej konwersji typu.
```c++
#include <iostream>  
using namespace std;  
int main()  
{  
int num; // deklarujemy typ całkowity   
double num2 = 15.25; // deklarujemy typ zmiennoprzecinkowy oraz przypisujemy wartość
  
//używamy niejawnej konwersji typu
num = num2;  
cout << " The value of the int variable is: " << num << endl;  
cout << " The value of the double variable is: " << num2 << endl;  
return 0;  
} 
```

W powyższym programie zadeklarowaliśmy num jako typ całkowity, a num2 jako zmienną typu double, a następnie przypisaliśmy num2 wartość 15.25. Następnie przypisujemy wartość num2 do zmiennej num za pomocą operatora przypisania. Tak więc kompilator C++ automatycznie konwertuje double na typ całkowity przed przypisaniem jej do zmiennej num i wydrukowaniem wartości obciętej do 15.

&nbsp;

### Jawna konwersja typu

Konwersje wymagające interwencji użytkownika w celu zmiany typu danych jednej zmiennej na inną są nazywane konwersją typu jawnego. Innymi słowy, jawna konwersja umożliwia programiście ręczną zmianę lub rzutowanie typu danych z jednej zmiennej na inny typ. Dlatego jest również znany jako rzutowanie typu. Ogólnie rzecz biorąc, wymuszamy jawną konwersję typu, aby przekonwertować dane z jednego typu na inny, ponieważ nie jest ona zgodna z regułą konwersji niejawnej.

Jawna konwersja typu jest podzielona na dwa sposoby:
- Jawna konwersja za pomocą operatora rzutowania
- Jawna konwersja za pomocą operatora przypisania


Program do konwersji wartości zmiennoprzecinkowej na typ int za pomocą operatora rzutowania

Operator rzutowania: w języku C++ operator rzutowania jest operatorem jednoargumentowym, który wymusza konwersję jednego typu na inny.

C++ obsługuje cztery typy rzutowania:
- static cast - dla typów prostych (nie są wskaźnikami ani referencjami)
- dynamic cast - konwersja wskaźników i klas na ich klasy pochodne, można tego dokonywać w górę i w dół
- const cast - konwersja stałych na zmienne, zmiennych na stałe lub stałych jednego typu na inny typ
- reinterpret cast - umożliwia konwertowanie dowolnego wskaźnika na dowolny typ innego wskaźnika


Rozważmy przykład konwersji typu danych float na typ int przy użyciu operatora rzutowania jawnej konwersji w języku C++.

```c++
#include <iostream>  
using namespace std;  
int main ()  
{  
float f2 = 6.7;  
// używamy operatora rzutowania, aby przekonwertować dane z jednego typu na inny
int x = static_cast <int> (f2);  
cout << " The value of x is: " << x;  
return 0;  
} 
```


Program do konwersji jednego typu danych na inny za pomocą operatora przypisania

Rozważmy przykład konwersji typu danych jednej zmiennej na inną za pomocą operatora przypisania.

```c++
#include <iostream>  
using namespace std;  
int main ()  
{  
// ddeklarujemy zmienną typu float
float num2;  
// inicjujemy zmienną int 
int num1 = 25;  
  
// konwertujemy typ danych z int na float 
num2 = (float) num1;  
cout << " The value of int num1 is: " << num1 << endl;  
cout << " The value of float num2 is: " << num2 << endl;  
return 0;  
}  
```

&nbsp;

Zalety konwersji typu:

- Ma to na celu wykorzystanie pewnych cech hierarchii typów lub reprezentacji typów.
- Pomaga obliczać wyrażenia zawierające zmienne o różnych typach danych.

Zadanie:
1) Napisz program, który pokaże mechanizm jawnej konwersji typu przez zmianę wartości double na liczbę całkowitą i użyj tej wartości całkowitej, aby znaleźć pole kwadratu.


&nbsp;

&nbsp;

# 2. Wskaźniki inteligentne

Bardzo często się zdarza, że potrzebujemy współdzielić jakiś element pomiędzy różnymi obiektami, a do tego jednym z najlepszych rozwiązań są wskaźniki. Jednakowoż pamiętanie o alokacji i dealokacji pamięci jest kłopotliwe i męczące. Może nieść ze sobą też widmo wycieku pamięci. Czy twórcy c++ nie znaleźli na to rozwiązania i skazali nas na bycie strażnikiem i pilnowanie, aby zawsze zwolnić pamięć? Oczywiście, że nie! Stworzyli oni inteligentne wskaźniki. Spróbujmy sami je opracować.

## RAII

RAII - Resource acquisition is initialization (zajęcie zasobów oznacza inicjalizację) jest techniką zajmowania zasobów za pomocą konstruktora i zwalniania ich za pomocą destruktora.


&nbsp;

## Unikalny wskaźnik - reprezentujący własność na wyłączność

Pierwszym wskaźnikiem, jakim się zajmiemy, będzie unikalny wskaźnik, czyli oznacza to, że tylko jeden wskaźnik będzie mógł wskazywać na miejsce, w którym znajduje się obiekt.

Opracuj zasadę działania i zaimplementuj taki wskaźnik.

&nbsp;

- Tylko jeden wskaźnik (ten inteligentny, który zaprogramujemy) może wskazywać na adres obiektu
- Nie skupiaj się na robieniu zabezpieczeń, tylko na zablokowaniu kopiowania obiektu z definicji (jak ktoś będzie chciał stworzyć kopię, to i tak jakoś to zrobi)
- Technika RAII przy tym zadaniu będzie bardzo potrzebna

Usuwanie domyślnego konstruktora:

```c++
class Test {
public:
    Test() = delete;
};
```

&nbsp;

&nbsp;

## Współdzielony wskaźnik - reprezentujący własność wspólną

Unikalny wskaźnik ułatwia nam życie, nie musimy pamiętać o zwalnianiu pamięci, ale narzuca na nas dość duże ograniczenia.
Jednakże bardzo często potrzebujemy wskaźnik, który może współdzielić wartość swojego obiektu, czyli kilka takich wskaźników może wskazywać na jeden obiekt w pamięci.
Zastanów się, jakbyś go zaimplementował, jeżeli nie masz pomysłu, to pomocne dla Ciebie może być laboratorium z konstruktorów kopiujących.

Opracuj zasadę działania i zaimplementuj wskaźnik współdzielący swoją własność.

&nbsp;

&nbsp;

## Inteligentne wskaźniki z biblioteki std

[Dokumentacja](https://en.cppreference.com/w/cpp/header/memory)

[Artykuł](https://cpp-polska.pl/post/kompendium-wiedzy-o-smart-pointerach)

[c++0x](https://cpp0x.pl/kursy/Kurs-C++/Poziom-5/Wskazniki-inteligentne-C++11/582)

[YouTube](https://www.youtube.com/watch?v=e2LMAgoqY_k)

Po zaimplementowaniu własnych wskaźników (mam nadzieję, że to zrobiłeś) omówmy teraz te zdefiniowane w bibliotece. Dzielą się one tak samo na dwie grupy, posiadające własność na wyłączność i współdzielące własności. Aby móc z nich korzystać najpierw należy załączyć bibliotekę (w sumie bardziej plik angłówkowy) `memory`. Dostajemy wtedy do dyspozycji:

- `unique_ptr` - własność wskaźnika jest na jego wyłączność
- `shared_ptr` - własność wskaźnika jest współdzielona
- `weak_ptr` - jest to słaba referencja do `shared_ptr`, czyli w przeciwienstwie do poprzednich wskaźników nie gwarantuje tego, że coś spod jego adresu nie zostanie usunięte
- `auto_ptr` - zapomnijmy o tym w c++11 był on już przestarzały i powinno się go przestać używać, natomiast w c++17 został usunięty

Ważną rzeczą, o której należy pamiętać, jest optymalizacja. Wskaźniki unikalne są praktycznie tak samo optymalne, jak standardowe wskaźniki, które byśmy deklarowali ręcznie. Natomiast współdzielone (jak można tak to nazwać), już mają pewien narzut, ponieważ muszą pilnować tego, czy ma już zwalniać pamięć, czy nie jest jeszcze ostatnim dowiązaniem.

**Omawiane poniżej przykłady będą wymagać co najmniej c++14**

&nbsp;

### Wskaźniki unikalne

Stwórzmy wskaźnik unikalny dla inta. Możemy go stworzyć po przez alokacje pamięci w konstruktorze wskaźnika, albo użyć wprowadzonej w *c++14* funkcji `make_unique`.

W zależności od kompilatora, jeżeli do `cout` przekażesz bezpośrednio wskaźnik inteligentny, to na windowsie zostanie wypisany adres, a na linuxie zgłoszony błąd kompilacji.

```c++
#include <iostream>
#include <memory>

using namespace std;

int main() {
    unique_ptr<int> p(new int);
    //unique_ptr<int> p(new int(100)); //Ustawianie wartości domyślnej zmiennej
    unique_ptr<int> pp = make_unique<int>();
    //unique_ptr<int> pp = make_unique<int>(69); //ustawienie wartości domyślnej zmiennej
    
    cout << "p adres:" << p.get() << "\t\tp wartość:" << *p <<endl;
    cout << "p adres:" << pp.get() << "\t\tp wartość:" << *pp <<endl;
}
```

&nbsp;

Sprawdźmy teraz jak to jest z tą unikalnością, czy możemy tworzyć kopię.

```c++
unique_ptr<int> p = make_unique<int>(6666);
cout << "p adres: \t" << p.get() << endl;
unique_ptr<int> p_copy = p;
//unique_ptr<int> p_copy = move(p); //Przeniesienie własności z obiektu p do p_copy

cout << "p adres: \t" << p.get() << endl;
cout << "p_copy adres:\t" << p_copy.get() << endl;
```

No nie udało się stworzyć kopii własności obiektu, ale jak odkomentowałeś linię z przeniesieniem własności, to obiekt z pierwszego wskaźnika został przeniesiony do drugiego.

&nbsp;

### Wskaźniki unikalne, a klasy

Jak zapewne pamiętacie szablony, to umożliwiają one przekazanie dowolnego typu do obiektu, tak więc ze stworzeniem unikalnego wskaźnika dla klasy nie będzie problemu.

```c++
class MyTheBestClass {
public:
    MyTheBestClass() {
        cout<< "Hello, I'm MyTheBestClass constructor" << endl;
    }
    
    ~MyTheBestClass() {
        cout<< "Hello, I'm MyTheBestClass destructor" << endl;
    }
    
    void function() {
        cout<< "Hello, I'm MyTheBestClass method" << endl;
    }
};

int main() {
    {
        unique_ptr<MyTheBestClass> mtbc = make_unique<MyTheBestClass>();
        mtbc->function();
        cout<< "Teraz będzie cin, aby zatrzymać program" <<endl;
        string temp;
        cin >> temp;
    }
    cout << "End app" << endl;
}
```

&nbsp;

### Co z polimorfizmem?

Oczywiście, że nadal działa.

```c++
class Figure {
public:
    virtual void printData() {
        cout << "I'm figure only, that mean I'm nothing?" << endl;
    }
};

class Square: public Figure {
public:
    void printData() {
        cout << "I'm proud square!" << endl;
    }
};

int main() {
    unique_ptr<Figure> ptr = make_unique<Square>();
    ptr->printData();
}
```

&nbsp;

&nbsp;

### Wskaźniki nieposiadające własności na wyłączność

Wskaźniki współdzielone posiadają w sobie informację o ilości obiektów, przez które są używane (ile inteligentnych wskaźników wskazuje na tę jedną własność). Przeanalizuj poniższy przykład.

```c++
class MyTheBestClass {
public:
    MyTheBestClass() {
        cout<< "Hello, I'm MyTheBestClass constructor" << endl;
    }
    
    ~MyTheBestClass() {
        cout<< "Hello, I'm MyTheBestClass destructor" << endl;
    }
    
    void function() {
        cout<< "Hello, I'm MyTheBestClass method" << endl;
    }
};

int main() {
    {
        shared_ptr<MyTheBestClass> mtbc = make_shared<MyTheBestClass>();
        cout << "Shared count: " << mtbc.use_count() << endl << endl;
        
        shared_ptr<MyTheBestClass> mtbc_copy1 = mtbc;
        cout << "Shared count base: " << mtbc.use_count() << endl;
        cout << "Shared count copy: " << mtbc_copy1.use_count() << endl << endl;
        
        {
            shared_ptr<MyTheBestClass> mtbc_copy2 = mtbc;
            cout << "Shared count base: " << mtbc.use_count() << endl;
            cout << "Shared count copy1: " << mtbc_copy1.use_count() << endl;
            cout << "Shared count copy2: " << mtbc_copy2.use_count() << endl << endl;
        }
        cout << "Shared count base: " << mtbc.use_count() << endl;
        cout << "Shared count copy1: " << mtbc_copy1.use_count() << endl;
    }
    cout << "End app" << endl;
}
```

&nbsp;

&nbsp;

### `weak_ptr` - słaba referencja

Inteligentny wskaźnik będący słabą referencją, jest używany w parze z `shared_ptr`. W przeciwieństwie do współdzielonego wskaźnika nie zwiększa on ilości dowiązań, więc nie dba o to, aby obiekt był żywy. Co nam daje `weak_ptr`? Optymalizację, wiemy, że obiekt nie zostanie usunięty, ale potrzebujemy go przekazać, nie ma sensu uruchamiać całej machiny związanej z utrzymaniem własności obiektu przy życiu.

```c++
class MyTheBestClass {
public:
    MyTheBestClass() {
        cout<< "Hello, I'm MyTheBestClass constructor" << endl;
    }
    
    ~MyTheBestClass() {
        cout<< "Hello, I'm MyTheBestClass destructor" << endl;
    }
    
    void function() {
        cout<< "Hello, I'm MyTheBestClass method" << endl;
    }
};

int main() {
    {
        shared_ptr<MyTheBestClass> mtbc = make_shared<MyTheBestClass>();
        cout << "Shared count: " << mtbc.use_count() << endl << endl;
        
        weak_ptr<MyTheBestClass> wp1 = mtbc;
        cout << "Shared count base: " << mtbc.use_count() << endl;
        
        {
            weak_ptr<MyTheBestClass> wp2 = mtbc;
            cout << "Shared count base: " << mtbc.use_count() << endl;
        }
        cout << "Shared count base: " << mtbc.use_count() << endl;
    }
    cout << "End app" << endl;
}
```

&nbsp;

&nbsp;

### Dlaczego nie używać inteligentnych wskaźników do tworzenia tablic i macierzy?

Istnieją dużo lepsze struktury do przechowywania tablic i macierzy. Jeżeli potrzebujemy zwykłą tablicę, to użyjemy kontenera `array`, w przypadku macierzy użyjemy kontenera w kontenerze. Są one w o wiele większym stopniu przystosowane do przechowywania takowych rzeczy, a niż inteligentne wskaźniki. (Po za tym kontenery przechowują rozmiar tablicy, a inteligenty wskaźnik, to nadal tylko wskaźnik, tyle że inteligentniejszy.)

&nbsp;

&nbsp;