# Laboratorium 10 19.12.2021/4.12.2022

## Szablony 

Szablon jest prostym, a jednocześnie bardzo potężnym narzędziem w C++. Są podstawą programowania generycznego, które polega na pisaniu kodu w sposób niezależny od konkretnego typu. Prostym pomysłem jest przekazanie typu danych jako parametru, dzięki czemu nie musimy pisać tego samego kodu dla różnych typów danych. Na przykład firma programistyczna może potrzebować sort() dla różnych typów danych. Zamiast pisać i utrzymywać wiele kodów, możemy napisać jeden sort() i przekazać typ danych jako parametr.

Szablon to plan lub formuła tworzenia ogólnej klasy lub funkcji. Implementują koncepcję programowania generycznego, które używa typów danych jako parametrów. Szablony zapewniają mechanizm, za pomocą którego funkcje lub klasy mogą być implementowane dla ogólnych typów danych (nawet takich, które jeszcze nie istnieją).

Parametry szablonów mogą być:
- typami
- stałymi typów całkowitych lub wyliczeniowych znanymi w chwili kompilacji
- szablonami

Szablony funkcji
Ogólna postać definicji szablonu funkcji:

```c++
template <class type> return type function name(parameter list) {
   ...
} 
```

Przykładami szablonów funkcji są sort(), max(), min(), printArray().



```c++
template <typename T>
T myMax(T x, T y)
{
   return (x > y)? x: y;
}
 
int main()
{
  cout << myMax<int>(1, 6) << endl;  // max z int
  cout << myMax<double>(8.0, 3.0) << endl; // max z double
  cout << myMax<char>('d', 'f') << endl;   // max z char
 
  return 0;
}
```

Poniżej program do implementacji bubble sort przy użyciu szablonów w C++:
```c++
// Funkcja szablonu do implementacji sortowania bąbelkowego.
// Możemy użyć tego dla dowolnego typu danych, który obsługuje
// Operator porównania < i swap działają dla niego.
template <class T>
void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
              swap(a[j], a[j - 1]);
}
  
int main() {
    int a[5] = {10, 50, 30, 40, 20};
    int n = sizeof(a) / sizeof(a[0]);
  
    // wywołujemy szablon funkcji
    bubbleSort<int>(a, n);
  
    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
  
  return 0;
}
```


Przeciążanie szablonów
W programie może obok siebie istnieć mając tę samą nazwę:
- kilka szablonów funkcji – byle produkowały funkcje o odmiennych argumentach,
- funkcje, o argumentach takich, że mogłyby zostać wyprodukowane przez któryś z szablonów (funkcje specjalizowane),
- funkcje o argumentach takich, że nie mógłby ich wyprodukować żaden z istniejących szablonów (zwykłe przeładowanie).

Szablony klas
Szablony klas jest podobny do szablonu funkcji. Szablony klas są przydatne, gdy klasa definiuje coś, co jest niezależne od typu danych. Może być przydatny dla klas takich jak LinkedList, BinaryTree, Stack, Queue, Array itp.





