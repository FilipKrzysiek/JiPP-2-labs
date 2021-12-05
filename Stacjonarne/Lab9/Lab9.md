# Laboratorium 8 (6/7.12.2021)

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




