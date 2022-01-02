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
    catch(constchar * msg) // złap wyrzucony tekst i przypisz do wskaźnika msg       
    {                                                
        cout << msg << endl;
        return 1;
    }  
} 
```

Łapanie wyjątków zdefiniowanych w bibliotece:

```c++

```

Rzucanie wyjątków zdefiniowanych w bibliotece:

```c++

```

&nbsp;

&nbsp;

## Nasze wyjątki

Nie zawsze w bibliotece podstawowej znajdziemy wyjątki, które idealnie pasują do naszej funkcji, klasy, aplikacji, biblioteki, czy tego, co tworzymy. Idealnym rozwiązaniem jest stworzenie własnej klasy dla wyjątku. Stwórzmy klasę wyjątku `MyException`. Pierwszą rzeczą, jaką musimy zrobić, to odziedziczyć interfejs wyjątku, następnie trzeba zaimplementować wszystkie funkcje i konstruktory.

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










