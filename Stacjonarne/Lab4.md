# Laboratorium 4 (25/26.10.2021)

## 1. Struktury 

W pewnych sytuacjach, rodzaje typów zmiennych, które oferuje język C++, mogą być niewystarczające. Mamy do dyspozycji szereg typów prostych takich jak int, char, bool czy typy złożone zwane tablicami. Tablica to taka struktura danych, która przechowuje wiele elementów tego samego typu. Co jeśli potrzebujemy pracować na obiektach, których składowe są różnych typów? Na ratunek przychodzą nam struktury, czyli złożone typy danych, które definiuje programista.

Tworzenie struktury

Struktury tworzymy za pomocą słowa kluczowego struct podając jej nazwę (tak będzie nazywał się typ przez nas stworzony), a następnie w nawiasie klamrowym definiujemy jej elementy:

```c++
struct nazwa{
	typ nazwa_elementu;
	typ nazwa_drugiego_elementu;
	typ nazwa_trzeciego_elementu;
	...
};
```

Przykład:

```c++
struct czlowiek{
	char imie[20]; //elementy struktury
	char nazwisko[20];
	int wiek;
	double wzrost;
};
```

Jeśli strukturę zdefiniujemy przed funkcją main(), będzie ona widoczna dla wszystkich bloków programu (będzie globalna). Na końcu stawiamy średnik. 
Po stworzeniu struktury mamy nowy typ - w naszym przypadku będzie nazywał się on człowiek. Możemy teraz tworzyć zmienne na jego podstawie. Nie różni się ono niczym od tworzenia zmiennych opartych na typach wbudowanych takich jak int, char itp. Przykład:


```c++
int main()
{
	int a; //tworząc zmienną podajemy jej typ i nazwę
	
	czlowiek osoba; //w tym przypadku jest tak samo, poniewaz
				//samochod jest typem, a renault nazwą

	return 0;
}
```

Drugim sposobem jest nadanie nazwy zmiennej strukturalnej podczas tworzenia struktury:

```c++
struct czlowiek{
	char imie[20];
	char nazwisko[20];
	int wiek;
	double wzrost;
}kasia, nowak;  //stworzenie dwóch zmiennych typu czlowiek
```


Odwoływanie się do elemetów składowych
Do elementów odwołujemy się za pomocą kropki, podając najpierw nazwę zmiennej strukturalnej, a następnie po kropce nazwę składowej struktury:

```c++
int main()
{
        
        czlowiek osoba; 
        
	cout<<"Podaj imię: "<<endl;
        cin>>osoba.imie; //odwołanie się do pola imie
	cout<<"Podaj nazwisko: "<<endl;
        cin>>osoba.nazwisko; //odwołanie się do pola nazwisko
        
        cout<<"Imię: "<<osoba.imie<<", nazwisko: "<<osoba.nazwisko<<endl;
        
        return 0;
}
```

Nadawanie wartości początkowych
Wartości początkowe nadajemy podobnie jak w tablicach. Taki sposób można zastosować tylko przy inicjowaniu zmiennej strukturalnej. Wartości elementów podajemy w nawiasie klamrowym pamiętając o kolejności przypisywanych elementów. Jeśli pierwszym elementem jest ciąg znaków, to taki ciąg powinien znaleźć się jako pierwszy. Dotyczy to wszystkich elementów składowych. 

Przykład:

```c++
int main()
{
	//nadanie wartości początkowych
	czlowiek osoba = {"Kasia","Nowak",22,1.65}; 
	
	//wypisanie wartości elementów struktury
	cout<<osoba.imie<<endl<<osoba.nazwisko<<endl<<osoba.wiek
	<<endl<<osoba.wzrost<<endl;
	
	return 0;
}
```

Drugim sposobem jest przypisanie wartości od razu przy tworzeniu struktury:

```c++
struct czlowiek{
	char imie[20];
	char nazwisko[20];
	int wiek;
	double wzrost;
}; osoba = {"Kasia","Nowak",22,1.65}; 
//nadanie wartości początkowych
```

Podsumowując, zmienne strukturalne stosujemy podobnie jak zwykłe zmienne rozszerzając je o dodatkowe właściwości. Możemy je przypisywać do siebie, tworzyć tablice struktur, wskaźniki itp.

Globalnie i lokalnie
Struktura stworzona przed funkcją main() będzie strukturą globalną, czyli każdy podprogram będzie mógł z niej korzystać. Jeśli stworzymy ją wewnątrz jakiegoś bloku, będzie lokalną i widoczna tylko w tym miejscu. Przykład:

globalnie

```c++
#include<iostream>
using namespace std;
//struktura globalna widoczna w każdym zakątku
struct czlowiek{
	char imie[20];
	char nazwisko[20];
	int wiek;
	double wzrost;
};

int main()
{
	czlowiek osoba = {"Kasia","Nowak",22,1.65}; 
	
	return 0;
}
```


lokalnie

```c++
#include<iostream>
using namespace std;

int main()
//struktura lokalna widoczna tylko w main()
{
struct czlowiek{
	char imie[20];
	char nazwisko[20];
	int wiek;
	double wzrost;
};

	czlowiek osoba = {"Kasia","Nowak",22,1.65}; 
	
	return 0;
}
```

Tablice struktur
Używanie struktur do organizacji danych jest znacznie wygodniejsze niż tworzenie pojedynczych zmiennych. Ale jeszcze bardziej wygodne, zwłaszcza przy rozbudowanych programach, jest wykorzystywanie tablic struktur. Zamiast tworzyć trzy osobne obiekty, tworzymy tablicę obiektów typu samochód. Dzięki temu w łatwy sposób możemy wyświetlać poszczególne elementy tablicy czy je dodawać lub usuwać. Przykład:

```c++
#include<iostream>
using namespace std;
//struktura globalna widoczna w każdym zakątku
struct czlowiek{
	char imie[20];
	char nazwisko[20];
	int wiek;
	double wzrost;
};

int main()
{
	int liczba_osob = 3;

	czlowiek osoba[] = {{"Kasia","Nowak",22,1.65}, 
			    {"Anna","Kowalska",24,1.67},
			    {}}; 
			
	
	cout << "Imie\tNazwisko \tWiek \tWzrost" << endl; 
	cout << "----------------------------------" << endl;
	
	for (int i = 0; i < liczba_osob; i++) 
	{
	cout << osoba[i].imie << "\t" << osoba[i].nazwisko << "\t" << osoba[i].wiek <<    	  "\t" << osoba[i].wzrost << endl; 
	}

	return 0;
}
```

&nbsp;

ZADANIA:
1) Stwórz za pomocą struktury bnowy typ samochód, który będzie przechowywał takie dane jak: marka(string), model(string), rok produkcji(int), kolor(string). Utwórz cztery obiekty typu samochód i zdefiniuj ich elementy. Wyświetl je wszystkie w tabelce.
2) Zmodyfikuj program z poprzedniego zadania, dodając do niego dowolną zmienną w strukturze. Wyświetl ponownie tabelkę ze wszystkimi samochodami.
3) Napisz funkcję, która będzie przyjmować tablicę samochodów oraz liczbę elementów w tablicy i zwróci liczbę(sumę) samochodów, które są tej samej marki. 
4) Napisz funkcję, która będzie przyjmować tablicę samochodów oraz liczbę elementów w tablicy i zwróci indeks samochodu, którego rok produkcji jest najniższy.

## 2. Klasy i obiekty

C++ posiada wszystko, co niezbędne do praktycznej realizacji idei programowanie zorientowanego obiektowo. Pisanie programu zgodnie z filozofią OOP(Object-Oriented Programming) polega na definiowaniu i implementowaniu odpowiednich klas oraz tworzeniu z nich obiektów i manipulowaniu nimi. Klasa jest więc dla nas pojęciem kluczowym, które na początek wypadałoby wyjaśnić. 

Klasa jest to złożony typ zmiennych, składający się z pól, przechowujących dane, oraz posiadający metody, wykonujące zaprogramowane czynności. Zmienne należące do tych typów obiektowych nazywamy obiektami. 

Każdy obiekt posiada swój własny pakiet opisujących go pól, które rezydują w pamięci operacyjnej w identyczny sposób jak pola struktur. Metody są natomiast kodem wspólnym dla całej klasy, zatem w czasie działania programu istnieje w pamięci tylko jedna ich kopia, wywoływana w razie potrzeby na rzecz różnych obiektów. Jest to dość oczywiste: tworzenie odrębnych kopii tych samych przecież funkcji dla każdego nowego obiektu byłoby niewątpliwie niepotrzebne.

Określenie klasy jest najczęściej rozdzielone na dwie części:

- definicję, wstawianą w pliku nagłówkowym, w której określamy pola klasy oraz wpisujemy prototypy jej metod

- implementację, umieszczaną w module, będącą po prostu kodem wcześniej zdefiniowanych metod

Układ ten nie dość, że działa nadzwyczaj dobrze, to jeszcze realizuje jeden z postulatów programowania obiektowego, jakim jest ukrywanie niepotrzebnych szczegółów.

Definicja klasy
Jest to konieczna i często pierwsza czynność przy wprowadzaniu do programu nowej klasy. Jej definicja precyzuje bowiem zawarte w niej pola oraz deklaracje metod, którymi klasa będzie dysponowała. Informacje te są niezbędne, aby móc utworzyć obiekt danej klasy; dlatego też umieszczamy je niemal zawsze w pliku nagłówkowym - miejscu należnym własnym typom danych.

Składnia definicji klasy wygląda natomiast następująco:

```c++
class nazwa_klasy
{
[ specyfikator_dostępu : ]
[ pola ]
[ metody ]
};
```

Modyfikatory dostępu 
Fraza oznaczona jako specyfikator_dostępu nie mówi pewnie za wiele. Nazwa specyfikator_dostępu , chociaż brzmi może nieco sztucznie , dobrze oddaje rolę, jaką ta konstrukcja pełni. Otóż specyfikuje ona właśnie prawa dostępu do części składowych klasy (czyli pól lub metod), wyróżniając ich dwa rodzaje: prywatne (ang. private ) oraz publiczne (ang. public).

Różnica między nimi jest znacząca i bardzo ważna, gdyż wpływa na to, które elementy klasy są widoczne tylko w ramach jej samej, a które także na zewnątrz. Te pierwsze nazywamy więc prywatnymi, zaś drugie publicznymi.

Prywatne składowe klasy (wpisane po słowie private : w jej definicji) są dostępne jedynie wewnątrz samej klasy , tj. tylko dla jej własnych metod.

Publiczne składowe klasy (wpisane po słowie public : w jej definicji) widoczne są zawsze i wszędzie - nie tylko dla samej klasy (jej metod), ale na zewnątrz - np. dla jej obiektów.

Chronione składowe klasy (wpisane po słowie protected : w jej definicji) słowo kluczowe protected ma takie same własności co słowo kluczowe private. Różnice pojawiają się tylko wtedy, gdy przyjdzie nam dziedziczyć klasy. Jeśli będziemy dziedziczyli klasę A do klasy B to zmienne oznaczone jako private w klasie A będą niewidoczne dla klasy B. Jeśli zmienne (i funkcje) klasy A będą miały prawo dostępu protected to takie zmienne (i funkcje) będą widoczne dla klasy B. 

Danym specyfikatorem objęte są wszystkie następujące po nim części klasy, aż do jej końca lub. kolejnego specyfikatora. Ich ilość nie jest bowiem niczym ograniczona.
Nic więc nie stoi na przeszkodzie, aby nie było ich wcale. W takiej sytuacji wszystkie składowe będą miały domyślne reguły dostępu. W przypadku klas (definiowanych poprzez class ) jest to dostęp prywatny, natomiast dla typów strukturalnych 1 (słówko struct ) - dostęp publiczny. 

PRZYKŁAD:

```c++
#include <string>

class PrzykladowaKlasa
{
public:
    double liczba; //prawo dostępu: publiczne
    char tablica[20]; //prawo dostępu: publiczne
    
private:
    int abc; //prawo dostępu: prytatne
    char znak; //prawo dostępu: prytatne
    std::string napis; //prawo dostępu: prytatne
};

int main()
{
    PrzykladowaKlasa nazwaZmiennej;
    return(0);
}
```

&nbsp;

ZADANIA:
1) Napisz program, który będzie liczył pole powierzchni prostopadłościanu(klasa Prostopadłościan z trzema polami).
2) Napisz program obliczający objętość kuli (klasa Kula o polu r).
3) Napisz program, który dla wprowadzonych współczynników funkcji kwadratowej wyświetli  wprowadzone dane w postaci: f(x) = a x^2 + b x + c (klasa FunckjaKwadratowa o polach a, b,c).
4) Napisz program, ktory stworzy klasę Student o polach: imię, nazwisko, numer albumu, liczba pytan, poprawne odpowiedzi. Napisz funckję, która wczyta te dane oraz funkcję, która obliczy procent poprawnych odpowiedzi.

Dodaj metody dostępowe do zmiennych (pól) klasy.

## 3. Koncepcja nazw

Nazwy klas piszemy wielką literą.

Nawy metod i zmiennych piszemy z małych liter.

## 4. gettery, setery i ich sens 

Tworząc pola, staramy się je umieszczać w części chronionej naszej klasy (private/protected). Jednakże wtedy nie możemy się odwołać do ich wartości bezpośrednio. Nie możemy odczytać ani zaktualizować ich wartości. Stwórzmy przykładową klasę:

```c++
class Person {
private:
    string firstName = "Jan";
    string secondName = "Kowalski";
};
```

Jeżeli w funkcji main zrobilibyśmy takie wywołanie:

```c++
Person p1;
cout << p1.firstName << endl;
```

To program się nie skompiluje, wyrzucając błąd. Stwórzmy metodę (funkcję), która będzie wypisywać na ekran nasze dane.

```c++
class Person {
private:
    string firstName = "Jan";
    string secondName = "Kowalski";
    
public:
    void print () {
        cout << firstName << " " << secondName << endl;
    }
};
```

Można zauważyć, że teraz w metodzie print mamy dostęp do tej zmiennej. Wracając do problemu postawionego na początku tego rozdziału, odczytywania i modyfikowania wartości pól w części prywatnej. Skoro mamy dostęp do zmiennej w metodzie, to czemu by nie stworzyć metody, która będzie zwracać wartość. Stwórzmy metodę, która będzie zwracać wartość `firstName`.

```c++
string getFirstName() {
    return firstName;
}
```

Jeżeli przez metodę można pobrać wartość zmiennej, to czemu by nie spróbować zmodyfikować jej wartości? Spróbujmy.

```c++
void setFirstName(string firstName) {
    this->firstName = firstName;
}
```

Podsumowując, czym są gettery i settery. <br/>
Gettery i settery są to metody pozwalające na pobranie i zaktualizowanie wartości pól będących w części prywatnej naszej klasy.

Czy settery to zawsze jedynie ustawianie wartości zmiennej? 

[!NOTE]
Tekst

&nbsp;

Do zadań z poprzedniego rozdziału dopisz gettery i settery.

&nbsp;

## 5. Konstruktory

Konstruktor jest specyficzną funkcją, która jest wywoływana zawsze gdy tworzony jest obiekt. Jeśli programista nie utworzy konstruktora dla klasy, kompilator automatycznie utworzy konstruktor, który nic nie będzie robił. Konstruktor nie pojawi się nigdzie w kodzie, jednak będzie on istniał w skompilowanej wersji programu i będzie wywoływany za każdym razem, gdy będzie tworzony obiekt klasy. Jeśli chcemy zmienić domyślne własności konstruktora jaki jest tworzony przez kompilator C++ wystarczy, że utworzymy własny konstruktor dla klasy. Przykład:

```c++
class NazwaKlasy
{
public:
    NazwaKlasy(); //To jest definicja konstruktora
};

NazwaKlasy::NazwaKlasy()
{
    //Tu inicjujemy wartości zmiennych klasy
}
```
Pierwsze co rzuca się w oczy w przypadku konstruktora, to brak zwracanego typu danych. Druga istotna własność konstruktora to jego nazwa. Konstruktor musi nazywać się tak samo jak nazwa klasy. Konstruktorom możesz przekazywać parametry tak samo jak funkcjom. C++ umożliwia również tworzenie kilku konstruktorów dla jednej klasy (muszą się one jednak różnić parametrami wejściowymi tak jak w przypadku funkcji).


Gdy tworzymy klasę, wszystkie zmienne jakie są zadeklarowane wewnątrz niej są zainicjowane przypadkowymi wartościami, które w konstruktorze następnie ustawiamy na takie, jakie uważamy za stosowne. Przykład:

```c++
class JakasKlasa
{
    int a;
    char b;
    std::string c;
public:
    JakasKlasa();
};

JakasKlasa::JakasKlasa()
{
    cout << "Klasa utworzona, wartosci zmiennych: " << endl;
    cout << "a = " << a << endl;
    cout << "b = '" << b << "'" << endl;
    cout << "c = \"" << c << "\"" << endl;
    a = 123;
    b = 'x';
    c = "napis";
    cout << "Wartosci zmiennych po zainicjowaniu w konstruktorze: " << endl;
    cout << "a = " << a << endl;
    cout << "b = '" << b << "'" << endl;
    cout << "c = \"" << c << "\"" << endl;
}

int main()
{
    JakasKlasa tZmienna;
    getch();
    return( 0 );
}
```

Takie rozwiązanie jest oczywiście poprawne, niemniej jednak czasami zachodzi potrzeba zainicjowania zmiennej w trakcie tworzenia klasy, a nie po jej utworzeniu. Aby to zrobić, należy użyć następującego zapisu:

```c++
class JakasKlasa
{
    int a;
    char b;
    std::string c;
public:
    JakasKlasa();
};

JakasKlasa::JakasKlasa()
    : a( 123 )
     , b( 'x' )
     , c( "napis" )
{
    cout << "Klasa utworzona, wartosci zmiennych: " << endl;
    cout << "a = " << a << endl;
    cout << "b = '" << b << "'" << endl;
    cout << "c = \"" << c << "\"" << endl;
}

int main()
{
    JakasKlasa tZmienna;
    getch();
    return( 0 );
}
```

Taki zapis ma kilka bardzo istotnych zalet:
- Jest szybszy - brzmi to trochę absurdalnie, ale różnice są znaczne gdy przyjdzie do wykonywania pomiarów czasowych.
- Jest czytelniejszy - programista nie musi analizować zawartości konstruktora, by wiedzieć jaką domyślną wartością zostanie zainicjowana klasa.
- Umożliwia inicjowanie zmiennych zdefiniowanych jako stałe.
- Umożliwia inicjowanie zmiennych zdefiniowanych jako referencje (i tylko tą metodą jesteś w stanie zainicjować zmienną zadeklarowaną np. tak: int& zmienna;).
- Jest metodą stosowaną przy dziedziczeniu klas (również niezastąpioną).

&nbsp;

PROBLEM 1:

```c++
class JakasKlasa
{
    int & a;
public:
    JakasKlasa( int & fA );
};

JakasKlasa::JakasKlasa( int & fA )
{
    a = fA;
}

int main()
{
    int zmiennaA;
    JakasKlasa tZmienna( zmiennaA );
    return( 0 );
}
```

&nbsp;

ROZWIĄZANIE:

```c++
class JakasKlasa
{
    int & a;
public:
    JakasKlasa( int & fA );
};

JakasKlasa::JakasKlasa( int & fA )
    : a( fA )
{
}

int main()
{
    int zmiennaA;
    JakasKlasa tZmienna( zmiennaA );
    return( 0 );
}
```

&nbsp;

PROBLEM 2:

```c++
class JakasKlasa
{
    const int a;
public:
    JakasKlasa( int fA );
};

JakasKlasa::JakasKlasa( int fA )
{
    a = fA;
}

int main()
{
    JakasKlasa tZmienna( 55 );
    return( 0 );
}
```

ROZWIĄZANIE:
```c++
class JakasKlasa
{
    const int a;
public:
    JakasKlasa( int fA );
};

JakasKlasa::JakasKlasa( int fA )
    : a( fA )
{
}

int main()
{
    JakasKlasa tZmienna( 55 );
    return( 0 );
}
```

ZADANIA:
1) Napisz program, który będzie zawierał klasę Punkt, zawierającą w zakresie publicznym: dwa pola przechowujące współrzędne punktu, konstruktor oraz metodę do obliczania odległości tych punktów.
2) Napisz program, który będzie zawierał klasę Figura, zawierającą w zakresie publicznym: pole (int) do przechowywania liczby wierzchołków, dynamiczną tablicę przechowującą wierzchołki figury oraz konstruktor.

## 6. Destruktor 

Często jest tak, że podczas życia klasy rezerwujemy pamięć, którą chcielibyśmy zwalniać zawsze przed usunięciem klasy. Pierwszym wariantem jest pamiętanie o wywołaniu funkcji, która będzie za to odpowiedzialna. Takie podejście jest jednak ryzykowne, ponieważ bardzo łatwo zapomnieć o wywoływaniu funkcji, która będzie zwalniała ewentualną zarezerwowaną dynamicznie pamięć.
Lepszym rozwiązaniem tego problemu jest wykorzystanie destruktorów. Destruktor jest specjalną funkcją, która jest wywoływana zawsze tuż przed zniszczeniem (usunięciem) klasy z pamięci.
Budowa destruktora:
```c++
class NazwaTwojejKlasy
{
public:
    ~NazwaTwojejKlasy(); //To jest definicja destruktora
};

NazwaTwojejKlasy::~NazwaTwojejKlasy()
{
    //Tu wykonujemy wszystkie operacje jakie mają się wykonać automatycznie tuż przed zwolnieniem pamięci zajmowanej przez klasę.
}
```

Destruktor, tak samo jak konstruktor nie posiada zwracanego typu. Drugą ważną cechą jest to, że destruktor musi być zawsze bezparametrowy. Trzecią, a zarazem ostatnią ważną cechą jest możliwość zdefiniowania tylko i wyłącznie jednego destruktora dla danej klasy.
Poniżej prosty przykład, demonstrujący działanie konstruktora i destruktora.

```c++
class KlasaCL
{
public:
    KlasaCL();
    ~KlasaCL();
};

int main()
{
    KlasaCL * tKlasa;
    cout << "Rezerwuje pamiec za pomoca new" << endl;
    tKlasa = new KlasaCL;
    cout << "Wchodze do bloku {" << endl;
    {
        KlasaCL tKlasa;
    }
    cout << "Wyszedlem z bloku }" << endl;
    cout << "Zwalniam pamiec, ktora zostala zarezerwowana za pomoca new" << endl;
    delete tKlasa;
    getch();
    return( 0 );
}

KlasaCL::KlasaCL()
{
    cout << "=> Konstruktor wywolany!" << endl;
}

KlasaCL::~KlasaCL()
{
    cout << "=> Destruktor wywolany!" << endl;
}
```

Zasady tworzenia destruktora są podobne do konstruktora. Nazwa destruktora zaczyna się od ~ i nazwy klasy.

ZADANIA:

1. W konstruktorze zrób `cout`, w którym dasz informacje, że nie został wywołany.
2. Zaalokuj tablicę wybranego typu 1024 elementami (ma mieć rozmiar 1024).
3. Stwórz metodę pause, w której zatrzymasz program. Możesz tego dokonać za pomocą `system("PAUSE")`, bądź używając `cin`.
4. Możesz sprawdzić ile pamięci zajmuje Twój program.
5. W destruktorze zrób `cout` z dowolnym tekstem i usuń zaalokowaną tablicę.

