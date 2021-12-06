# Laboratorium 9 (6/7.12.2021)

Celem tego laboratorium jest zapoznanie się z kontenerami, pętlami foreach oraz iteratorami.

## Kontenery

Korzystanie z tablic, gdy nie znamy ilości danych, które chcemy w niej zapisać jest bardzo nie wygodne i problematyczne. Dodatkowo powinniśmy w osobnej zmiennej przechowywać jej rozmiar (najprostsze rozwiązanie). Jednakże c++ przychodzi z rozwiązaniem. Kontenery. Pozwalają one na przechowywanie w nich dowolnej ilości obiektów, dowolnego typu (deklarowanego przy tworzeniu obiektu), dając możliwość poznania rozmiaru „tablicy”. Najpopularniejsze/najbardziej podstawowe kontenery to:

- `vector`
- `list`
- `map`

Kontenery można spróbować nazwać tablicą, albo inteligentną tablicą, lecz nie będzie to do końca poprawne.

&nbsp;

### Vector

Jest to jeden z najbardziej przydatnych kontenerów, który jest bardzo zbliżony do tablicy, ponieważ dane przechowywane są w sąsiadujących komórkach pamięci, czyli w ciągłości, tak jak tablica.

Deklarowanie:

```c++
vector<typ> nazwaObiektu;
```

Przykładowa deklaracja:
```c++
#include <vector>

vector <int> elements;
```

&nbsp;

Najpopularniejsze metody:

- `push_back` - dodawanie elementu na koniec
- `emplace_back` - tworzenie elementu na końcu (będzie przykład później)
- `pop_back` - usuwanie ostatniego elementu
- `size` - pobieranie rozmiaru wektora
- `at` - dostęp do elementu na podanym indeksie


&nbsp;

#### Zarządzanie wielkością tablicy

Przeanalizuj poniższy kod i wynik jego działania.

```c++
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vect;
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;

    return 0;
}
```

Zanim zapytam co zauważyłeś, to spieszę z wyjaśnieniami, co robi metoda `capacity`. Zwraca ona rozmiar fizycznie zaalokowanej pamięci, natomiast `size` używanej ilości elementów.

Co dostrzegłeś/aś? Size za każdym się zmienia, natomiast `capacity` zmieniał się tylko się zwiększał. Dzieje się tak, gdyż vector realokuje pamięć, jeżeli występuje konieczność zwiększenia rozmiaru tablicy kontenera. Początkowo nasz vector miał rozmiar i pojemność 0 elementów, chcąc dodać do niego jeden element, musieliśmy dokonać zwiększania jego rozmiaru, ponieważ nowy dodatkowy element się nie mieścił.

Powyższy przykład pokazuje nam kilka słabych punktów vectora, czyli realokowanie pamięci podczas dodawania elementów, jeżeli rozmiar tablicy jest niewystarczający oraz nie zwalnianie pamięci, przy usuwaniu elementów.

Nie jest tak kolorowo, jak się zapowiadało ☹ . Jest jednak cień nadziei. Przeanalizuj kolejny przykład. Dokonano w nim porównania czasu wykonania różnego sposobu tworzenia vectora.️

```c++
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void simpleVector() {
    vector<int> vect;
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.shrink_to_fit();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
}

void smarterVector() {
    vector<int> vect;
    vect.reserve(20);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
    
    vect.shrink_to_fit();
    cout<< "Size: " << vect.size() << " \tCapacity: " << vect.capacity() << endl;
}

void simpleVectorNoCout() {
    vector<int> vect;
    
    vect.push_back(1);
    
    vect.push_back(1);
    
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    
    vect.pop_back();
    
    vect.pop_back();
    
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    
    vect.shrink_to_fit();
}

void smarterVectorNoCout() {
    vector<int> vect;
    vect.reserve(20);
    
    vect.push_back(1);
    
    vect.push_back(1);
    
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    vect.push_back(1);
    
    vect.pop_back();
    
    vect.pop_back();
    
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    vect.pop_back();
    
    vect.shrink_to_fit();
}

int main()
{
    simpleVector();
    
    cout << endl << endl;
    smarterVector();
    
    cout << endl << endl;
    auto start = chrono::steady_clock::now();
    for(int i =0; i < 1000; ++i)
        simpleVectorNoCout();
    auto end = chrono::steady_clock::now();
    
    auto start1 = chrono::steady_clock::now();
    for(int i =0; i < 1000; ++i)
        smarterVectorNoCout();
    auto end1 = chrono::steady_clock::now();

    cout << "Simple vector called 1000x time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
    cout << "Smarter vector called 1000x time: " << chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count() << endl;

    return 0;
}
```

Simple vector zwiększa swój rozmiar przy dodaniu każdego elementu, natomiast smarter vector zwiększa pojemność vectora a na końcu zmniejsza swój rozmiar. Która wersja jest optymalniejsza, która działała szybciej?

&nbsp;

&nbsp;

#### Przykład z użyciem obiektu

Oczywiście zamiast podstawowych typów do vectora możemy przekazać naszą klasę. Stwórzmy przykładową:

```c++
class Stop {
private:
    long id;
    string name;
    double latitude;
    double longitude;
    
public:
    Stop(long id, const string &name, double latitude, double longitude);
};
```

Teraz stwórzmy vector:

```c++
vector<Stop> stopsList;
```

&nbsp;

#### Różnica pomiędzy `push_back` i `emplace_back`

Różnica pomiędzy `push_back`, a `emplace_back` polega na tym, że do `push_back` przekazujemy obiekt, albo wartość, natomiast dla `emplace_back` przekazujemy wartości, które przyjąłby konstruktor.

```c++
vector<Stop> stopsList;
stopsList.push_back(Stop(1, "Test", 5.1, 5.2));
stopsList.emplace_back(1, "Test", 5.1, 5.2);
```


&nbsp;

### Przykład uzycia

Przeanalizuj przykład dostępny [tutaj](Examples/StopExample). Sprawdź jak on działa, zdebuguj go.

Kod działa prawidłowo? Dlaczego? Wiesz? Jeżeli nie, to cofnij się do momentu, zarządzanie wielkością tablicy.

## Listy

Kolejnym kontenerem jest lista. Ona w przeciwieństwie do vectora nie trzyma wszystkich elementów zwartch, tak jak w tablicy. Posiada ona element i wskaźnik na poprzedni i następny element. Posiada część wspólnych metod z vectorem:

- `push_back` - dodawanie elementu na koniec
- `emplace_back` - tworzenie elementu na końcu (będzie przykład później)
- `pop_back` - usuwanie ostatniego elementu
- `size` - pobieranie rozmiaru wektora

Jak już pewnie zauważyłeś/aś nie posiada metody `at`, czyli dostępu do konkretnego elementu. Jest to realizowane przy pomocy iteratora, o którym będzie za chwilę.

Lista nie będzie szczególnie omawiana, ponieważ jest ona bardzo podobna do vectora, tylko w inny sposób przechowuje wartości.

## Zadanie

Po przeczytaniu o iteratorach popraw przykład `StopExample`.

## Foreach

Pętla foreach w języku C ++, jest to pętla for oparta na zakresie. Została wprowadzona w C ++ 11. Ten typ struktury pętli for ułatwia przechodzenie przez iterowalny zestaw danych. Czyni to poprzez eliminację procesu inicjalizacji i przechodzenie przez każdy element, a nie przez iterator. Zagłębmy się więc w odpowiednią strukturę pętli foreach.

### Działanie pętli foreach w C++

Pętla for-each iteruje po elementach tablic, wektorów lub dowolnych innych zestawów danych. Przypisuje wartość bieżącego elementu do iteratora zmiennej zadeklarowanego wewnątrz pętli. Przyjrzyjmy się bliżej składni:

```c++
for(typ nazwa_zmiennej : tablica/nazwa_wektora)
{
    instrukcje petli
    ...
}
```

Jak możemy zobaczyć:

- Podczas inicjalizacji pętli deklaracja zmiennej elementarnej jest tą częścią, w której musimy zadeklarować zmienną, która będzie iterować po tablicy lub wektorze. Tutaj typem jest typ danych zmiennej nazwa_zmiennej
- Nazwa tablicy/wektora to nazwa odpowiedniego zestawu danych, po którym będzie iterowana pętla,
- Instrukcje pętli to różne operacje, które użytkownik może wykonać na odpowiednich elementach za pomocą zmiennej iteracyjnej.

Uwaga: Sugeruje się, aby typ danych zmiennej był taki sam jak w tablicy lub wektorze. Jeśli typ danych nie jest taki sam, elementy zostaną rzutowane na typ, a następnie zapisane w zmiennej.

Przykłady pętli foreach

1. Przykład pętli foreach dla tablic w C++
Poniższy kod ilustruje użycie pętli for-each w C++

```c++
#include<iostream>
using namespace std; 
int main() 
{ 
    int arr[]={1,2,3,4,5};   //inicjalizacja tablicy
    cout<<"Elementy: ";
    for(int i : arr)
    {
        cout<<i<<" ";
    }
    return 0;
}
```
Sprawdź wynik działania kodu.

Rozłóżmy kod i spójrzmy na niego linijka po linijce:

- Tablica arr[] jest inicjowana pewnymi wartościami {1 , 2 , 3 , 4 , 5}
- Wewnątrz struktury pętli „i” jest zmienną, która przechowuje wartość bieżącego elementu tablicy
- arr to nazwa tablicy, która służy również jako adres bazowy odpowiedniej tablicy
- Jak widać, wypisanie „i” dla każdej iteracji daje nam odpowiednie elementy tablicy w przeciwieństwie do indeksów tablicy w przypadku normalnej pętli for

Uwaga: podczas deklarowania zmiennej „i” moglibyśmy również użyć typu danych auto zamiast int. Gwarantuje to, że typ zmiennej jest dedukowany z typu tablicy i nie występują konflikty typów danych.

Na przykład:
```c++
#include<iostream>
using namespace std; 
int main() 
{ 
    int array[]={1,4,7,4,8,4};
    cout<<"Elementy: ";
    for(auto var : array)
    {
        cout<<var<<" ";
    }
    return 0;
}
```
Pętla foreach - automatyczny typ danych

2. Przykład pętli foreach dla wektorów w C++
Poniższy kod ilustruje użycie pętli for-each do iteracji po wektorze

```c++
#include<iostream>
#include<vector>
using namespace std; 
int main() 
{ 
    vector<int> vec={11,22,33,44,55,66};
    cout<<"Elementy: ";
    for(auto var : vec)
    {
        cout<<var<<" ";
    }
    return 0;
}
```

Pętla for-each dla wektora działa w taki sam sposób, jak w przypadku tablicy. Ponadto jedyne różnice to deklaracja wektora, inicjalizacja i różne operacje, które można na nim wykonać.

Zalety i wady pętli foreach w C++
1. Zalety pętli foreach
Eliminuje możliwość błędów i sprawia, że kod jest bardziej czytelny.
Łatwe do wdrożenia
Nie wymaga wstępnej inicjalizacji iteratora
2. Wady pętli foreach
Nie można uzyskać bezpośredniego dostępu do odpowiednich indeksów elementów
Nie można przejść elementów w odwrotnej kolejności
Nie pozwala użytkownikowi pominąć żadnego elementu, gdy przechodzi on przez każdy z nich


Wniosek
Pętla foreach w C++ ma swoje wady i zalety. Kod jest łatwy do odczytania, ale ogranicza niektóre działania oferowane przez normalną pętlę for. W związku z tym całkowicie zależy od użytkownika, co chce, aby pętla wykonała i odpowiednio wybrać.

## Iteratory

Iteratory to w zasadzie obiekty, które pomagają programistom uzyskać dostęp do elementów danych z kontenerów. Wskazuje na określoną pozycję indeksu (adres pamięci) kontenera Standard Template Library i umożliwia dostęp do elementu danych w tej pozycji.

Składnia:
```
container-name<data-type>::iterator iterator-name
```

Przykład:
```
list<int>::iterator A;
```

W ten sposób iteratory pomagają nam poruszać się i przechodzić przez elementy kontenerów.

### Rodzaje iteratorów w C++
Na początkowym etapie Iteratory i wskaźniki mogą być podobne do Ciebie pod względem funkcjonalności. Ale pod koniec poznasz różnice między iteratorem a wskaźnikiem w C++.

Iteratory działają inaczej niż wskaźniki. Poniżej typy iteratorów, które oferują różne funkcje:

- Iterator wejściowy
- Iterator wyjściowy
- Iterator do przodu
- Iterator dwukierunkowy
- Iterator o dostępie swobodnym

### Input Iterator
Input iterator jest podstawowym typem iteratora, który służy wyłącznie do przechodzenia przez elementy kontenera.

Pomaga nam poruszać się po elementach kontenera, ale nie daje nam dostępu do modyfikacji wartości danych kontenera.

Poniżej znajduje się lista operatorów, których można używać wraz z iteratorami wejściowymi:

Operator dereferencji (*)
Operator przyrostu (++)
Równe operatorowi (==)
Nie równa się operatorowi (!=)


Przykład:

```c++ 
#include <iostream> 
#include <list> 
using namespace std; 
int main() 
{ 
    list<int> li= { 10, 20, 42, 50, 75 }; 
 
 
    list<int>::iterator x; 
    cout<<"Wynik: ."<<endl;
 
    for (x = li.begin(); x != li.end(); x++) { 
         
        cout << (*x) << " "; 
    } 
    return 0; 
} 
```

W powyższym fragmencie kodu użyliśmy listy jako kontenera i zadeklarowaliśmy „x” jako iterator tej listy „li”. Funkcje begin() i end() służą do wskazywania pierwszej i ostatniej pozycji kontenera. Iterator przemierza listę w kierunku do przodu (w górę).

Przetestuj powyższy kod

### Output iterator

Output iterator są komplementarne do iteratorów wejściowych, tj. są przeciwne względem siebie pod względem funkcjonalności.

Można ich używać do przypisywania i manipulowania wartościami elementów danych kontenera. Ale nie można ich używać do uzyskiwania dostępu lub przechodzenia przez elementy kontenera.

Poniżej znajduje się lista operatorów, których można używać wraz z iteratorami wyjścia:

Operator wyłuskiwania (* , ->)
Operator przyrostu (++)
Równe operatorowi (==)
Nie równa się operatorowi (!=)

Przykład:

```c++
#include <iostream> 
#include <list> 
using namespace std; 
int main() 
{ 
    list<int> li= { 10, 20, 42, 50, 75 }; 
 
 
    list<int>::iterator x; 
    cout<<"Wynik: "<<endl;
 
    for (x = li.begin(); x != li.end(); x++) { 
//iterator wyjścia do zmiany lub przypisania nowych wartości do wszystkich
// elementów listy
        *x = 4;
    } 
    for (x = li.begin(); x != li.end(); x++) { 
//używanie iteratora wejściowego do przechodzenia przez listę
        cout << (*x) << " "; 
    } 
     
    return 0; 
} 

```
Jak widać powyżej, przypisaliśmy wartość = 4 wszystkim elementom kontenera za pomocą iteratora wyjścia

Sprawdź działanie kodu


### Bi-directional Iterator

Iterator dwukierunkowy jest dość podobny do iteratora wejściowego. Jedyna różnica polega na tym, że iterator dwukierunkowy może przemierzać elementy w obu kierunkach, tj. do przodu i do tyłu (wstecz).

Poniżej znajduje się lista operatorów, których można używać wraz z iteratorami wejściowymi:

Operator wyłuskiwania (* , ->)
Operator przyrostu (++)
Równe operatorowi (==)
Nie równa się operatorowi (!=)
Operator dekrementacji (–)

Przykład:

```c++
#include <iostream> 
#include <list> 
using namespace std; 
int main() 
{ 
    list<int> li= { 10, 20, 42, 50, 75 }; 
 
 
    list<int>::iterator x; 
    cout<<"Przejście po elementach listy do przodu."<<endl;
 
     
    for (x = li.begin(); x != li.end(); x++) { 
//używanie iteratora wejściowego do przechodzenia przez listę
        cout << (*x) << " "; 
    } 
  cout<<endl;
    cout<<"Przechodzenie przez elementy listy w kierunku wstecznym"<<endl;
 
  for (x=li.end();x!=li.begin();--x) 
    { 
        if (x != li.end()) 
        { 
            cout << (*x) << " "; 
        } 
    } 
    cout << (*x); 
     
    return 0; 
} 
```

Sprawdź działanie kodu.

### Forward Iterator

Forward Iterator może być określany jako kombinacja odpowiednio iteratora wejścia i wyjścia. Pozwala nam na modyfikację wartości pozycji danych kontenerów, a także przechodzenie przez elementy kontenera.

Ale w przeciwieństwie do iteratora dwukierunkowego, forward iterator nie pozwala na przechodzenie elementów w kierunku wstecznym.

Poniżej znajduje się lista operatorów, których można używać wraz z iteratorami wejściowymi:

Operator wyłuskiwania (* , ->)
Operator przyrostu (++)
Równe operatorowi (==)
Nie równa się operatorowi (!=)

Przykład:
```c++
#include <iostream> 
#include <list> 
using namespace std; 
int main() 
{ 
    list<int> li= { 10, 20, 42, 50, 75 }; 
 
 
    list<int>::iterator x; 
    cout<<"Przejście po elementach lsty"<<endl;
  for (x = li.begin(); x != li.end(); ++x) { 
         
        cout << (*x) << " "; //używanie iteratora wejściowego do przechodzenia przez listę
    } 
     
 
    for (x = li.begin(); x != li.end(); x++) {
// użycie iteratora wyjścia do zmiany lub przypisania nowych wartości do wszystkich
// elementów listy
                  *x = 4;   
    } 
  cout<<endl;
  cout<<"Traversing elements of the list after assigning a new value to the list.."<<endl;
    for (x = li.begin(); x != li.end(); ++x) { 
         
        cout << (*x) << " "; //używanie iteratora wejściowego do przechodzenia przez listę
    } 
     
    return 0; 
} 
```
Sprawdź działanie kodu

### Random-Access Iterator

Iteratory o dostępie swobodnym umożliwiają użytkownikom dostęp do elementów danych z dowolnego losowego indeksu/pozycji w kontenerze. Ponadto zawiera wszystkie właściwości kontenera dwukierunkowego.

Ponadto iteratory o dostępie swobodnym mają dostęp do odejmowania i dodawania wskaźników ze względu na losowy dostęp do elementów danych.


Operacje wykonywane przez Iteratory w C++

Poniżej przedstawiono niektóre z podstawowych i najczęściej używanych funkcji do manipulowania elementami danych za pomocą iteratorów:

- begin(): Ta metoda zwraca początkowy/początkowy indeks elementów danych w kontenerze.
- end(): Zwraca indeks końcowy elementów danych w kontenerze.
- prev(int): Zwraca nowy iterator, który wskazuje element danych, który jest obecny przed pozycją wymienioną w parametrze funkcji.
- next(int): Zwraca nowy iterator, który wskazuje na element danych, który jest obecny po pozycji wymienionej w parametrze funkcji.
- inserter(container, int): Ta funkcja dodaje/wstawia wartość w określonym indeksie lub pozycji w kontenerze.
- Advance(int): Zwiększa się o liczbę określoną w parametrze i wskazuje element danych określony w tym indeksie.

Przykład:
```c++
#include <iostream> 
#include <list> 
using namespace std; 
int main() 
{ 
    list<int> li= {10, 20, 42, 50, 75}; 
    list<int>::iterator x; 
   
    cout<<"Przejście po elementach listy do przodu "<<endl;
 
     
    for (x = li.begin(); x != li.end(); x++) { 
         
        cout << (*x) << " "; //używanie iteratora wejściowego do przechodzenia przez listę
    } 
    cout<<endl;
   
list<int>::iterator ee = li.begin(); 
       
    advance(ee, 3); 
    cout << "Element wskazywany przez iterator po użyciu metody Advance():"; 
    cout << *ee << " "; 
cout<<endl;
list<int>::iterator A = li.begin(); 
list<int>::iterator B = li.end(); 
      
   auto aa = next(A, 2); 
       
     
   auto  bb = prev(B, 2); 
   
   cout << "Element wskazany za pomocą next() to : "; 
    cout << *aa << " "; 
    cout << endl; 
       
    cout << "Element wskazany za pomocą prev() to : "; 
    cout << *bb << " "; 
    cout << endl; 
     
    return 0; 
} 
```

Sprawdź działanie kodu.


Zalety iteratorów w C++
Łatwość programowania: przy pomocy iteratorów nie musimy prowadzić konta o różnej wielkości kontenera, dzięki czemu możemy łatwo przejść przez kontener za pomocą metod begin() i end().
Wysoki poziom ponownego wykorzystania kodu.
Dynamicznie dodawanie lub usuwanie elementu danych z kontenera.



Zadania:
1) Użyj iteratora, aby zamienić każdy element ciągu znakowego na wielką literę.
2) Odtwarzacz muzyki. Powinien mieć obsługiwane następujące funkcje:

Utwórz listę odtwarzania, korzystając z wielu utworów.
Dodaj utwory do listy odtwarzania.
Usuń utwór z listy odtwarzania.
Odtwarzaj utwory w pętli (w tym ćwiczeniu wszystkie utwory zostaną wydrukowane raz).

Kroki, aby wykonać ćwiczenie:
- Najpierw zaprojektuj podstawową strukturę, która obsługuje cykliczną reprezentację danych.
- Następnie zaimplementuj w strukturze funkcje wstawiania i usuwania, aby obsługiwać różne operacje.
- Musimy napisać niestandardowy iterator. To trochę trudne. Ważne jest, aby upewnić się, że jesteśmy w stanie przejść przez kontener przy użyciu podejścia opartego na zakresie dla pętli. Stąd begin() i end() powinny zwracać różne adresy, chociaż struktura jest cykliczna.
- Po zbudowaniu kontenera zbuduj na nim opakowanie, które będzie przechowywać różne utwory na liście odtwarzania i wykonywać odpowiednie operacje, takie jak następny, poprzedni, drukuj wszystko, wstawiaj i usuwaj.



