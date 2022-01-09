# Laboratorium 11 (10.01.2022)

Celem tego laboratorium jest zapoznanie się z tematyką konwersji, wskaźników inteligentnych i wielowątkowości.

# 1. Konwersje



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

