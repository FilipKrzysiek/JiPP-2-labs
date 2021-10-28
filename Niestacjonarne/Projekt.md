# Projekt

## Etap 1

#### Stwórz Podstawową implementację wektora

Celem tego etapu projektu jest stworzenie własnej implementacji kontenera `vector`, na podstawie podanej poniżej deklaracji.

Deklaracja zawiera metody, które są wymagane do zaimplementowania i takie, które można wykonać dodatkowo. Zostały one dodatkowo oznaczone.

```c++
template<typename type>
class Vector {
private:
    type data*;
    size_t allocatedDataSize;
    size_t usingDataSize;

public:
    /**
     * Create empty vector
     * Tworzenie pustego wektora
     */
    Vector();

    /**
     * Create vector with passed size
     * Tworzenie wektor o podanym rozmiarze
     * @param usingDataSize size of creating vector
     */
    Vector(size_t usingDataSize);

    /**
     * Deallocating, do cleanings
     * Zwalnianie pamięci, robienie porządków
     */
    ~Vector();

    /**
     * Get element from specified index
     * Pobieranie elementów spod przekazanego indeksu
     * @param index index of element
     * @return reference to element
     */
    type *at(size_t index);

    /**
     * Get address of first element
     * Pobieranie adresu pierwszego elementu
     * @return address of first element
     */
    type *front();

    /**
     * Get address of last element
     * Pobieranie adresu ostatniego używanego elementu
     * @return address of last element
     */
    type *back();

    /**
     * Get size of using data
     * Pobieranie rozmiaru tablicy (używanej części)
     * @return size of using vector
     */
    size_t size();

    /**
     * Add new element on the end of vector
     * Dodaj nowy element na koniec wektora
     * @param newRecord new value
     */
    void pushBack(type newRecord);

    /**
     * Delete last element
     * Usuwanie ostatniego elementu
     */
    void popBack();

    /**
     * Check vector is empty
     * Sprawdzanie, czy wektor jest pusty
     * @return true if vector is empty, false if not empty
     */
    bool isEmpty();

    /** Dodatkowe
     * Delete all elements
     * Usuwanie wszystkich elementów z wektora
     */
    void clear();
    
    /** Dodatkowe
     * Reallocate data to fit allocated data to using data
     * Realokowanie pamięci, aby dopasować rozmiar zaalokowanej tablicy do używanej
     */
    void shrinkToFit();
    
    /**
     * Delete element on passed index
     * Usuwanie elementu pod wskazanym indeksem
     * @param size_t index of element to erase
     */
    void erase(size_t index);
};
```

#### Pola

Klasa zawiera następujące pola:
- data - wskaźnik służący do przechowywania danych
- allocatedDataSize - rozmiar (ilość elementów) zaalokowanej pamięci
- usingDataSize - rozmiar (ilość) używanych elementów

#### Konstruktory

Podczas tworzenia obiektu powinna być alokowana pamięć do przechowywania elementów. Można zaalokować więcej pamięci, niż jest używane. Przykładowo przy wywołaniu pustego konstruktora można zaalokować pamięć dla 10 elementów i ustawić używaną wielkość (usingDataSize) na 0.

## Dodatkowe informacje

Można tworzyć dodatkowe metody bądź pola, jeżeli będzie to potrzebne.



