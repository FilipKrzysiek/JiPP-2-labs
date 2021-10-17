# FAQ, rozwiązywanie podstawowych problemów

## Problemy z narzędziami deweloperskimi

### Próbuję uruchomić z konsoli mój program, ale nie działa

Sprawdź z jakiego narzędzia deweloperskiego korzystasz. Jeżeli jesteś na windowsie i korzystasz z:
- VisualStudio - odpal cmd i powinno działać
- cygwin - odpal konsolę cygwina i z jej poziomu uruchom program
- mingw - odpal konsolę mingw i z jej poziomu uruchom program, jeżeli nie możesz jej znaleźć popatrz [tutaj](https://stackoverflow.com/questions/14430944/i-cant-find-my-mingw-shell-after-installing-with-gui-installer/18094371)
- WSL - odpal konsolę ubuntu


### Mam cygwina i nie wykrywa kompilatora

1. Uruchom instalator cygwina
2. Przeklikaj dalej do tabeli, gdzie można wybierać pakiety do instalacji
3. Z rozwijanego menu u góry wybierz `Full` zamiast `Pending`
4. Znajdź i zaznacz do instalacji:
   - gcc
   - g++
   - gdb


## Problemy z CMake

### Nie wykrywa mi targetu (nie ma na liście rozwijanej jednego outputu)

**Czy CMake został załadowany poprawnie (w zakładce `CMake` na dole nie ma błędów)?**

**Próbowałeś załadować ponownie plik CMake?**

![img.png](img/reloadCmake.png)

Ewentualnie załadować ponownie z resetem cache?

![img.png](img/forceReloadCmake.png)

**Masz wybrany poprawny bazowy plik CMake?**

![](img/choseBaseFile.png)


**W bazowym pliku CMake dodajesz podkatalog z kolejnym plikiem CMake?**

Bzowy plik CMake - plik, który jest ładowany jako pierwszy, powinien to być plik, który znajduje się najwyżej w naszym projekcie

```cmake
add_subdirectory(nazwa_katalogu)
# Jeżeli w nazwie katalogu występuje spacja
add_subdirectory("nazwa katalogu")
```

