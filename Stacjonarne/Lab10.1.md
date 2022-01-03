# Laboratorium 10.1 (3.01.2022)

Celem tego laboratorium jest usystematyzowanie wiedzy na temat plików, szablonów i obiektowości. Dodatkowo poruszony zostanie temat wyjątków.

# Obsługa błędów


Temat obsługi błędów został już poruszony w podstawowym stopniu podczas laboratorium 3. Poznaliśmy wtedy blok `try` `catch` i dowiedzieliśmy się, że możemy łapać i rzucać podstawowe wyjątki zdefiniowane w bibliotece, ewentualnie `char *`. Zobaczmy to na kilka przykładów, aby sobie przypomnieć.

Rzucanie i łapanie wyjątku typu `char *`:

```c++
int main() { 
    try       { 
        throw"tekst z obszaru try"; // wyrzuć tekst
        return 0;
    } 
    catch(const char * msg) // złap wyrzucony tekst i przypisz do wskaźnika msg       
    {                                                
        cout << msg << endl;
        return 1;
    }  
} 
```

C++ posiada zdefiniowane wyjątki ich listę można znaleźć [tutaj](https://en.cppreference.com/w/cpp/error/exception).

Łapanie wyjątków zdefiniowanych w bibliotece:

```c++
int main()
{
    try {
         int f = std::stoi("ABBA");
    } catch (const invalid_argument& e) {
        cout << "Allocation failed: " << e.what() << '\n';
    } catch (...) {
        cout << "Caught exception in default block" << endl;
    }
}
```

Rzucanie wyjątków zdefiniowanych w bibliotece:

```c++
int main()
{
    try {
        throw invalid_argument("try block argument not found");
    } catch (const invalid_argument& e) {
        cout << "Invalid argument failed: " << e.what() << '\n';
    } catch (...) {
        cout << "Caught exception in default block" << endl;
    }
}
```

&nbsp;

&nbsp;

## Nasze wyjątki

Nie zawsze w bibliotece podstawowej znajdziemy wyjątki, które idealnie pasują do naszej funkcji, klasy, aplikacji, biblioteki, czy tego, co tworzymy. Idealnym rozwiązaniem jest stworzenie własnej klasy dla wyjątku. Stwórzmy klasę wyjątku `MyException`. Pierwszą rzeczą, jaką musimy zrobić, to odziedziczyć interfejs wyjątku, następnie trzeba zaimplementować wszystkie funkcje i konstruktory.

Definicja wyjątku w plikach źródłowych:

```c++
namespace std
{
  /**
   * @defgroup exceptions Exceptions
   * @ingroup diagnostics
   *
   * Classes and functions for reporting errors via exception classes.
   * @{
   */

  /**
   *  @brief Base class for all library exceptions.
   *
   *  This is the base class for all exceptions thrown by the standard
   *  library, and by certain language expressions.  You are free to derive
   *  your own %exception classes, or use a different hierarchy, or to
   *  throw non-class data (e.g., fundamental types).
   */
  class exception
  {
  public:
    exception() _GLIBCXX_NOTHROW { }
    virtual ~exception() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
#if __cplusplus >= 201103L
    exception(const exception&) = default;
    exception& operator=(const exception&) = default;
    exception(exception&&) = default;
    exception& operator=(exception&&) = default;
#endif

    /** Returns a C-style character string describing the general cause
     *  of the current error.  */
    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
  };

} // namespace std
```

Implementacja naszego wyjątku:

```c++
#include <exception>

class MyException: public exception {
private:
    char *exceptionText;
    
public:
    MyException(char * exceptionText): exceptionText(exceptionText) {}
    
    
};
```

Powyższy przykład przedstawia podstawową klasę wyjątku. Spróbujmy zaszaleć bardziej, stwórzcie klasę wyjątku, która:
 
- będzie w sobie przechowywać podstawowe komunikaty i kody błędów
- będzie posiadać w sobie rozróżnienie błędów na krytyczne, poważne i ostrzeżenia

&nbsp;

&nbsp;

&nbsp;

# Zadanie

1. Zaprojektuj bibliotekę do obsługi plików `.csv`. Opracuj, jakie ma ona oferować funkcjonalności.
2. Zaprojektuj klasę wyjątku dla tej biblioteki.
3. Zacznij implementować.

Zwróć uwagę na:

- pierwszy wiersz może być wierszem z tytułami kolumn
- nie zawsze `,` jest tym, co dzieli wartości 
- co z tekstem, który ma przecinek w środku?
- biblioteka powinna umożliwiać odczytywanie pliku ewentualnie jeżeli starczy czasu, to zapisywanie
- pliki `.csv` mogą być bardzo duże










