
## BeforeCopyingConstructor

Folder zawiera projekt przed stworzeniem konstruktora kopiującego. Efektem działania tego programu powinno być 
wyrzucanie błędu po przyciśnięciu dowolnego przycisku w konsoli, gdy zostaniemy o to poproszeni. Dodatkowo można 
zaobserwować, że zmieniając wartości w zmiennej `n1` również zmieniają się wartości w zmiennej `n1_1`.

## WithCopyingConstructor

Dodanie konstruktora kopiującego naprawia powyższy błąd.

## FriendFunctions

Przykład zawiera zastosowanie funkcji zaprzyjaźnionych.


Użyj debuggera i sprawdź różnice pomiędzy funkcjami:
- `void showTriangleData(Triangle triangle);`
- `void showTriangleData(Triangle *triangle);`