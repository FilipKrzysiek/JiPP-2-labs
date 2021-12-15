# Projekt końcowy

Tematykę projektu końcowego wymyślacie sami. Projekt będzie musiał w sobie zawierać większość tematów, które były poruszane na zajęciach. Obowiązkowo musi on zawierać:

- wskaźniki
- klasy
- dziedziczenie
- polimorfizm
- szablon
- przeciążanie metod
- przeciążanie operatorów
- konstruktory, destruktory
- kontenery
- „bazę danych” - plik też jest bazą danych
- parametry wywoływania programu
- obsługę błędów

Do zwolnienia z egzaminu należy dodatkowo zrobić GUI, może także być inne środowisko graficzne.

Interfejs użytkownika można zrobić używając:

- widnows visual studio (windowsowe okienka)
- wxwidgets - dość proste, ale może nie udać się zainstalować
- gtk - nie wiem, czy działa pod windowsem
- qt - działa wszezie, nie jest trudne i posiada narzędzie do tworzenia okienek ([tutaj można pobrać](https://www.qt.io/download-open-source?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5), trzeba się zarejestrować, ale powinno działać)
- inne, które znalazłem, ale nie testowałem
  - nana

## Co będzie sprawdzane?

1. Działanie
2. Czy wszystkie rzeczy zostały zaimplementowane
3. Dokumentacja w plikach nagłówkowych
4. Nazwy zmiennych, czy mówią to co przechowują
5. Czystość kodu


## Terminy

1. Temat projektu
   1. Propozycje wymyślane przez studentów - 6.12
   2. Wybieranie tematu projektu - 13.12
2. Konsultowanie się w temacie projektu, pomoc itp do 16.01
3. Oddawanie im wcześniej, tym lepiej, ale nie później niż do końca semestru (30.01)
4. Projekty oddane w sesji będą oceniane maksymalnie na 4.0

&nbsp;

&nbsp;

&nbsp;

## Bazy danych

Używana w projekcie baza danych nie musi być pełnoprawną bazą danych. Tematyka baz danych będzie poruszana dopiero na późniejszych etapach Waszej edukacji.

W projekcie możesz użyć plików zamiast pełnoprawnej bazy danych przykładowo: 

- pliki binarne - sam wymyślisz, jak zapisać dane
- pliki json
- pliki csv
- pliki xml

Pamiętaj wszystkie dane nie muszą być przechowywane w jednym pliku, mogą być przechowywane w wielu. Dodatkowo możesz używać bibliotek do ich obsługi. 

&nbsp;

Jeżeli natomiast masz ambicje i chcesz skorzystać z pełnoprawnej bazy danych, to możesz użyć:

- mysql (lub inna sql) - musisz poszukać biblioteki do obsługi
- mongodb - udostępnia bibliotekę do obsługi
- sqlite - musisz poszukać biblioteki do obsługi

&nbsp;

&nbsp;

&nbsp;

## Przykładowe tematy

(podpunkty to jest podobny temat, tyle, że różni się szczegółami)

1. Aplikacja do zarządzania (dodawanie wpisów, wyświetlanie, edytowani, usuwanie, jakieś proste analizy):
   1. Pracownikami
   2. Liniami komunikacji
   3. Spedycją
   4. Wydatkami
2. Proste gry
3. Implementacja własnego kontenera, którego zawartość można zapisywać na dysk i dodatkowe proste zarządzanie (dodaj, usuń, wyświetl, edytuj)
4. Aplikacja do edytowania plików
   1. csv
   2. json
   3. xml
   4. inne
5. Aplikacja kalendarz
6. Aplikacja wspomagająca zarządzanie pociągami na stacji (dodawanie pociągu, wyszukiwanie danych w rozkładzie jazdy (skąd dokąd, na który wyjazd, czas zatrzymania, czas odjazdu), zapisywanie statusu (zapowiedziany, nadjeżdża, nadjeżdża bez postoju, postój handlowy, postój, odjeżdża), opis, edytowanie statusu, danych, usuwanie pociągu).

&nbsp;

&nbsp;

&nbsp;

## Skąd czerpać wiedzę

Lista książek z opisami dostępna jest [tutaj](https://coders.school/resources/). Zanim poszukasz w bibliotece, czy też księgarni, sprawdź, czy nie ma nowszego wydania.

Najważniejszą rzeczą, na którą warto zwracać uwagę, to jest **wersja c++**, która jest omawiana. Absolutne minimum, to **c++11**, wprowadził on bardzo dużą rewolucję.

Książki, które miałem w ręce:

- Wprowadzenie do wzorców projektowych C++ i Qt ([biblioteka](https://koha.biblos.pk.edu.pl/cgi-bin/koha/opac-detail.pl?biblionumber=10132&query_desc=kw%2Cwrdl%3A%20Qt)) - Opisuje c++ i wprowadza w programowanie GUI przy użyciu qt.
- C++ : podróż po języku dla zaawansowanych ([biblioteka](https://koha.biblos.pk.edu.pl/cgi-bin/koha/opac-detail.pl?biblionumber=140033)) - poruszane są wszystkie tematy, leczy jest pisana dość zaawansowanym językiem. Wspomina o nowościach wprowadzanych w c++ 20.
- C++20 biblioteka techniczna : problemy i rozwiązania ([biblioteka](https://koha.biblos.pk.edu.pl/cgi-bin/koha/opac-detail.pl?biblionumber=146870)) - omawia podobnie, jak poprzednia wszystkie tematy, lecz mam wrażenie, że wdaje się zbyt bardzo w szczegóły. Jest napisana w formie problem, rozwiązanie.