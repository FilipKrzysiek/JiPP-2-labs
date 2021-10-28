# Projekt

## Etap 1

#### Stwórz Podstawową implementację wektora

Celem tego etapu projektu jest stworzenie własnej implementacji kontenera `vector`, na podstawie podanej poniżej deklaracji.

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
     * Stworzenie pustego wektora
     */
    Vector();

    /**
     * Create vector with passed size
     * Stwórz wektor o podanym rozmiarze
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
     * Pobieranie elementów elementów spod przekazanego indeksu
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
     * Pobieranie adresu ostatniego elementu
     * @return address of last element
     */
    type *back();

    /**
     * Get size of using
     * Pobieranie rozmiaru
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

    /**
     * Delete all elements
     * Usuwanie wszystkich elementów z wektora
     */
    void clear();
};
```

