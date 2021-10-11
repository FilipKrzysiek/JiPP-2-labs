# Zadanie domowe

## Przygotowanie

W głównym folderze Twojego repozytorium stwórz folder `simpleCalc`, wewnątrz którego utwórz strukturę 
projektu dla języka c++ ([ściąga tutaj](Lab1.md#Komendy-cmake)).

## Zadanie

Stwórz program, który będzie dokonywał obliczeń, na podstawie przekazanych do niego parametrów (nie używamy cin).
Pierwszy z nich
będzie decydował, jakie to będzie działanie:
1. `add` - dodawanie dwóch liczb
2. `subtract` - odejmowanie dwóch liczb
3. `volume` - obliczanie objętości graniastosłupa prostego o podstawie trapezu
4. `help` - wyświetlanie dokumentacji

Jeżeli przekazano zły bądź złą ilość parametrów powinien zostać wyświetlony komunikat o błędzie i dokumentacja,
która powinna wyglądać w następujący sposób (tu jest tylko kawałek):

```console
Simple calculatur
simpleCalc [nazwa działania]

Działania:
add [a] [b]
    Dodawanie dwóch liczb ([a] i [b]) całkowitych.    
```

**Założenie**

Zawsze podajemy liczby tam, gdzie mają być liczby, nie wpisujemy tam tekstu.

### Podział na pliki

Kod głównego programu powinien znajdować się w pliku `main.cpp` (który znajduje się w folderze `src`). Każda z 
wymienionych funkcjonalności powinna znajdować się w osobnej funkcji. Deklaracje funkcji powinny znajdować się w 
pliku `include/calc.h`, a ich ciała w `src/calc.cpp`.

## Problemy z przekazywaniem parametrów

Jeżeli ktoś miał problemy z przekazywaniem parametrów do programu, który stworzył, to zapewne używał minGw, bądź 
cygwina. Aby można było przetestować działanie, można edytować konfigurację (u góry po prawej pomiędzy młotkiem i 
trójkątem jest lista rozwijana, z której należy wybrać `edit configuration`, a następnie w polu `Program arguments` 
wpisać argumenty, które chcemy przekazać).

**Inne metody:**

cygwin - należy odpalić terminal cygwina i z jego poziomu uruchomić naszą aplikację, wtedy już powinno to działać

minGw - znaleźć, jak uruchomić terminal minGw, uruchomić go i z jego poziomu uruchomić naszą aplikację
