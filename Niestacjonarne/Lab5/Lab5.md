# Laboratorium 5

###### Zadania stworzone na podstawie materiałów dr hab. Inż. Sergiy Fialko [link](https://torus.uck.pk.edu.pl/~fialko/index.html)

#### Tematyka zajęć

- RTTI
- klasa błędów
- polimorfizm znowu
- szablony - uzupełnienie wiadomości
- funkcje wirtualne

## Tablice obiektów

Tablicę obiektów deklarujemy tak samo, jak normalną tablicę, lecz zamiast jednego z podstawowych typów podajemy nazwę klasy (tak, jakbyś deklarowali nowy obiekt).

```c++
class MyClass {
    
};

int main() {
    MyClass array[10];
    return 0;
}
```

&nbsp;

&nbsp;

## Zadanie 1

Przeanalizuj kod znajdujący się [tutaj](examples/example1.cpp).

Analizę zacznij od funkcji main. Zastanów się, jakie konstruktory i destruktory zostaną wywołane i w jakiej kolejności.

Nie modyfikując funkcji main popraw program, tak aby zlikwidować wyciek pamięci.

&nbsp;

&nbsp;

## RTTI

> **RTTI (Run Time Type Information** – informacja o typie w trakcie wykonywania programu) jest techniką stosowaną w nowoczesnych obiektowych językach programowania. Technika ta polega na dołączeniu do kodu programu informacji o typach (klasach), czasami też ich własnościach i dostępnych metodach.
> 
> ## W C++
> W standardowym C++ każdej klasie towarzyszy struktura przechowująca nazwę klasy. Dostęp do niej uzyskuje się poprzez typeid.
>
> Wyrażenie `typeid(e).name()` zwraca nazwę klasy, do której należy obiekt `e`. Standard C++ nie określa co ma zawierać zwrócony napis.
>
> 
> *[Wikipedia](https://pl.wikipedia.org/wiki/RTTI)*
 
Znajdź w zadaniu 1 uzycie `typeid` i zobacz jak ono działa.

&nbsp;

&nbsp;

## Typ wyliczeniowy

Tworzymy aplikację, ktora ma kilka trybów działania np:

- pobieranie danych
- wypisywanie
- analizowani
- krzyczenie na użytkownika

Chcemy zapisać, w jakim aktualnie trybie ona działa, jakiego typu zmiennej byś użył?

`int` może `short`, albo klasa z kilkoma `bool`

&nbsp;

C++ przychodzi do nas z genialniejszym rozwiązaniem, typami wyliczeniowymi. Typ wyliczeniowy to taka zmienna, która posiada zadeklarowane swoje wartości, i tylko je można do niej przypisać.

```c++
enum nazwa_typu {
    //wartości
};
```

&nbsp;

Zadeklarujmy typ wyliczeniowy dla naszego przykładu.

```c++
enum appMode {
    DOWNLOADING_DATA,
    PRINTING_DATA,
    ANALYSING_DATA,
    SHOUT_AT_USER
};
```

Jak zapewne zauważyłeś, wszystkie „wartości” są pisane wielkimi literami. Jest tak robione, aby łatwo można było odróżnić nazwy zmiennych, bądź funkcji od „wartości” typów wyliczeniowych.

&nbsp;

Zadeklarujmy teraz zmienną z typem wyliczeniowym i przypiszmy mu wartość.

```c++
enum appMode {
    DOWNLOADING_DATA,
    PRINTING_DATA,
    ANALYSING_DATA,
    SHOUT_AT_USER
};

int main() {
    appMode actualMode = DOWNLOADING_DATA;
    cout << actualMode << endl;
    
    actualMode = PRINTING_DATA;
    cout << actualMode << endl;
    
    actualMode = ANALYSING_DATA;
    cout << actualMode << endl;
}
```

Jak pewnie zauważyłeś „wartościom” typów wyliczeniowych są przypisywane wartości liczbowe, każda kolejna deklaracja posiada zwiększoną o 1 wartość liczbową. Teraz zobacz na kolejny przykład, gdzie nadpisujemy wartości (tak można to robić).

```c++
enum dni {
    PON,
    WT,
    SR = 0,
    CZW = 0,
    PT = 0,
    SO,
    N
};

int main() {
    dni actualDay = PON;
    cout << actualDay << endl;
    
    actualDay = WT;
    cout << actualDay << endl;
    
    actualDay = SR;
    cout << actualDay << endl;
    
    actualDay = CZW;
    cout << actualDay << endl;
    
    actualDay = PT;
    cout << actualDay << endl;
    
    actualDay = SO;
    cout << actualDay << endl;
    
    actualDay = N;
    cout << actualDay << endl;
    
    actualDay = PON;
    dni actualDay1 = WT;
    
    cout << endl << "PON == WT" << endl;
    cout << (actualDay == actualDay1) << endl;
    
    actualDay = PON;
    actualDay1 = SR;
    
    cout << endl << "PON == SR" << endl;
    cout << (actualDay == actualDay1) << endl;
}
```


&nbsp;

&nbsp;

## Klasa obsługi błędów

Podczas działania naszej aplikacji mogą zdarzyć się błędy, nawet jeżeli wszystko dobrze zaprogramujemy. Naszym zadaniem, jako programistów jest zabezpieczyć aplikację, tak aby ona sobie z tym radziła, albo kończyła jej działanie w kontrolowany sposób dający jasny komunikat, co się stało.

> Obsługa błędów to bardzo poważna kwestia w prawdziwych programach, więc nic dziwnego, że powstało wiele różnych technik. Kiedy w funkcji wystąpi błąd i nie ma możliwości obsłużenia go lokalnie, funkcja ta musi o tym jakoś poinformować, moduł, który ją wywołał.
> 
> (...)
> 
> Aby poinformować o braku możliwości realizacji zadania, funkcja może:
> 
> - zgłosić wyjątek
> - zwrócić wartość oznaczającą niepowodzenie
> - zamknąć program (wywołując funkcję `terminate()`, `exit()`, lub `abort()`)
> 
> O błędzie za pomoca specjalnego kodu informujemy w następujących sytuacjach:
>
> - Awaria jest czymś normalnym i spodziewanym. Na przykład nie ma nic dziwnego w tym, że czasami nie udaje się otworzyć pliku (może po prostu nie ma pliku o takiej nazwie albo nie można go otworzyć z wymaganymi uprawnieniami).
> - Bezpośredni moduł wywołujący prawdopodobnie będzie w stanie poradzić z zaistniałą sytuacją.`` 
> 
> &nbsp;
> 
> *C++ Podróż po języku dla zaawansowanych - Bjarne Stroustrup*

&nbsp;

Stwórzmy prostą klasę, która będzie przechowywać komunikaty.

```c++
class myMess {
public:
    enum myMessage {
        ERR_ALLOC_MEM,  //memory allocation error
        WARN_ARR_FULL,  //array is full (last > ndim)
        WARN_ARR_EMPT,  //array is empty (last = 0)
        WARN_ARR_UNKN,  //invalid operation (interface)
        TOT_NUMB        //total number of messages
    };
    
    static string messageText[TOT_NUMB]; //array of messages
    
    void mess(enum myMessage ms);  // When this function is called, the message
                                    //appears on the screen. If this is an error,
                                    //the calculation must be finished, if not,
                                    //continue. ms - enumeration member that gives
                                    //the message number};
};

string myMess::messageText[] = {
        "E memory alloc error",         //ERR_ALLOC_MEM
        "W array is full",              //WARN_ARR_FULL
        "W array is empty",             //WARN_ARR_EMPT
        "W invalid operation"           //WARN_ARR_UNKN
};

void myMess::mess(enum myMessage ms) {
    if(messageText[ms][0] == 'E') {
        cout << "ERROR: " << messageText[ms].substr(1) << endl;
        system("pause");
        exit(1);
    } else if(messageText[ms][0] == 'W') {
        cout << "WARNING: " << messageText[ms].substr(1) << endl;
    }
}
```

&nbsp;

W tej klasie przechowujemy „kody” błędów oraz wiadomości je opisujące. Wywołując metodę `mess` wypisujemy na ekran błąd i w razie błędu krytycznego kończymy działanie aplikacji.

&nbsp;

&nbsp;

### Podział błędów

Jeden błąd nie jest równy innemu błędowi, dlatego możemy dokonać podziału na różne „stopnie” błędów:

- krytyczny — błąd, którego nie umiemy obsłużyć aby „naprawić” to co się zepsuło, należy wtedy zakończyć działanie aplikacji
- błąd — poważny błąd, ale potrafimy go obsłużyć i „naprawić” to co się zepsuło, następnie możemy kontynuować działanie aplikacji
- ostrzeżenie — ostrzeżenie, że coś się stało, należy o tym poinformować użytkownika, umiemy to obsłużyć, ale nie musimy nic „naprawiać”

&nbsp;

&nbsp;

## Wyjątki

Jednym ze sposobów obsługi błędów są wyjątki. Posiadają one 2 bloki `try`, w którym próbujemy wykonać kod i `catch`, który wykonujemy w razie zaistnienia błędu.

```c++
try {
    int f = std::stoi("ABBA");
} catch (const invalid_argument& e) {
    cout << "Allocation failed: " << e.what() << '\n';
} catch (...) {
    cout << "Caught exception in default block" << endl;
}
```

Oczywiście nie jesteśmy skazani na łapanie wyjątków tylko i wyłącznie z bibliotek, możemy sami wyrzucać wyjątki, a nawet je tworzyć. Wyrzucanie wyjątku będzie wyglądało następująco:

```c++
throw invalid_argument("try block argument not found");
```

&nbsp;

&nbsp;

&nbsp;

&nbsp;

# Szablony — uzupełnienie wiadomości

Jeżeli deklarujemy szablony, to implementacja musi znajdować się w tym samym pliku (najprostsze rozwiązanie). Oczywiście istnieją wyjątki od reguły, np. używanie forward declarations, czyli deklarowanie jakie typy mogą zostać przekazane do szablonu. [Tutaj możesz zobaczyć przykład](examples/forwardDeclarations).

> **Kiedy tego użyć?**
> 
> Tworzymy bibliotekę do obsługi plików i chcemy stworzyć uniwersalną metodę do odczytywania wartości, ale chcemy, aby można było odczytywać wybrane typy wartości. Oczywiście można stworzyć przeciążenia metod.

&nbsp;

&nbsp;

&nbsp;

&nbsp;

# Polimorfizm i szablony — utrwalenie wiadomości

Stwórz klasę `ListI`, która będzie interfejsem (będzie posiadać tylko wirtualne metody). Ma ona zawierać metody:

- dodawania elementu na koniec
- usuwania ostatniego elementu
- dostępu do elementu na podanym indeksie

Następnie stwórz klasy pochodne, które będą wykorzystywały następujące kontenery do przechowywania informacji:

- vector
- list
- map
- array

&nbsp;

Stwórz w funkcji main wskaźnik do obiektu typu `ListI`. Przypisz do niego jedną ze stworzonych klas pochodnych, przetestuj działanie, a następnie przetestuj pozostałe klasy pochodne.

Czy zauważyłeś jakąś różnicę?

&nbsp;

**P.S.**

Tak wiem, to zadanie ma średni sens teoretyczny, ale skupcie się na polimorfizmie.


&nbsp;

&nbsp;

&nbsp; 

&nbsp;

Na następnych zajęciach kolokwium i oddawanie projektów.

Główna tematyka kolokwium, to polimorfizm.
