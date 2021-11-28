# Laboratorium 8 (29/30.11.2021)

Celem tego laboratorium jest usystematyzowanie wiedzy na temat dziedziczenia i klas abstrakcyjnych.

## Klasy abstrakcyjne/interfejsy

> W C++ klasą abstrakcyjną jest klasa, która posiada zadeklarowaną co najmniej jedną metodę czysto wirtualną. Każda klasa, która dziedziczy po klasie abstrakcyjnej i sama nie chce być abstrakcyjną, musi implementować wszystkie odziedziczone metody czysto wirtualne.

*[Wikipedia](https://pl.wikipedia.org/wiki/Klasa_abstrakcyjna)*

Czy na poprzednich zajęciach implementowaliśmy klasę abstrakcyjną? Tak, przykład, gdzie jedna metoda była wirtualna, był przykładem klasy abstrakcyjnej. Co, jeżeli wszystkie metody klasy są wirtualne? Możemy wtedy mieć do czynienia z interfejsem. Musimy spełnić następujące warunki:

- Klasa nie posiada pól
- Klasa posiada tylko wirtualne metody
- Wszystkie metody są publiczne

Jeżeli powyższe założenia są spełnione, to można powiedzieć, że mamy do czynienia z interfejsem. Język c++ w przeciwieństwie np do javy nie wyróżnia specjalnie interfejsów względem innych klas.

### Zadania

1. Stwórz interfejs dla klasy 

&nbsp;

&nbsp;