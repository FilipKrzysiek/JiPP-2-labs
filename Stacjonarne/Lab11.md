# Laboratorium 11 (10.01.2022/17.01.2022)

Celem tego laboratorium jest zapoznanie się z tematyką konwersji, wskaźników inteligentnych i wielowątkowości.

# 1. Konwersje 

Konwersja zmiennych z jednego typu na inny nazywana jest konwersją typu. Celem konwersji typów jest sprawienie, aby zmienne jednego typu danych współpracowały ze zmiennymi innego typu danych. Przeprowadzamy to, aby skorzystać z niektórych aspektów reprezentacji typów i hierarchii. Kiedy więc konwersja typu będzie korzystna?

Konwersje typów mogą służyć do wymuszenia prawidłowego typu obliczeń matematycznych, które należy wykonać. Znalezienie sumy dwóch zmiennych, jednej typu int, a drugiej typu float jest dobrym przykładem na zademonstrowanie użycia konwersji typu. Aby uzyskać sumę dwóch zmiennych, musisz przekonwertować zmienną int na zmiennoprzecinkową.

Mamy dwie formy konwersji typów:

- Niejawna konwersja typu
- Jawna konwersja typu


Niejawna konwersja typu

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

&nbsp;

# 2. Wskaźniki inteligentne

Alokowanie pamięci wiąże się z pilnowaniem tego, aby ją zwolnić. No to stwórzmy obiekt, który będzie robił to za nas. Zacznijmy od pierwszego inteligentnego wskaźnika `unique`.

Spróbujmy sami wymyślić, jak on miałby działać. Jego cechy to:

- nie może być kopiowany
- przypisanie do niego wartości usuwa poprzednią

Postaraj się teraz go zaimplementować.

&nbsp;

&nbsp;

### Współdzielony wskaźnik

Poprzedni wskaźnik zabezpieczył nas przed wyciekami pamięci, ale w znaczący sposób nas zablokował, nie możemy mieć kilku wskaźników wskazujących na to samo miejsce w pamięci. Spróbujmy teraz takowy stworzyć. Aby tego dokonać, wróćmy się do przykładu z konstruktora kopiującego. Jeżeli tworzyliśmy kopię obiektu, gdzie był wskaźnik, to kopii ulegał wskaźnik, a nie jego wartość. Wykorzystaj to, aby stworzyć swój inteligentny wskaźnik, który może mieć wiele kopii.

&nbsp;

&nbsp;

### Inteligentne wskaźniki w bibliotece

[Dokumentacja](https://en.cppreference.com/w/cpp/header/memory)

[Artykuł](https://cpp-polska.pl/post/kompendium-wiedzy-o-smart-pointerach)

[c++0x](https://cpp0x.pl/kursy/Kurs-C++/Poziom-5/Wskazniki-inteligentne-C++11/582)

Oczywiście to co przed chwilą wymyśliłeś i zaimplementowałeś (mam nadzieję, że to zrobiłeś) zostało już stworzone w c++. Takie funkcjonalności oferuje biblioteka `memory`. Oferuje ona nam kilka inteligentnych wskaźników:

- `unique_ptr` - inteligentny wskaźnik, którego obiekt jest unikalny, czyli istnieje tylko jeden
- `shared_ptr` - inteligentny wskaźnik, który może dzielić to co przechowuje z wieloma wskaźnikami
- `weak_ptr` - jest to słaba referencja do `shared_ptr`, ale nie gwarantuje ona tego, że dany obiekt jeszcze tam istnieje

Inteligentne wskaźniki można podzielić na dwie grupy, będące unikatem i mogące mieć kopie. Te drugie są o tyle ciekawe, że mamy do nich dostęp na podstawie `shared_ptr` i `weak_ptr`. Dlaczego? Tworzenie kolejnego `shared_ptr` nie jest aż tak tanie, jak zwykłego wskaźnika. Wskaźnik współdzielony udostępnia między sobą ilość dowiązań do swojego obiektu, natomiast `weak_ptr` pozwala wskazywać na ten obiekt bez zwiększania ilości dowiązań.

&nbsp;

#### Tworzenie wskaźnika unikalnego

Tworzenie wskaźnika inteligentnego polega na wywołaniu jego konstruktora, gdzie alokujemy pamięć dla jego zawartości.

```c++
#include <memory>

using namespace std;

int main() {
    unique_ptr<int []> p(new int[100]);
    unique_ptr<int []> pp(new int[200]);
    
    //pp = p; //Odkomentuj to i sprawdź, czy działa
    
    p(new int);
}
```


&nbsp;

&nbsp;

# 3. Wielowątkowość

