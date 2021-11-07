cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

# Ustawianie, gdzie ma znaleźć się skompilowany plik wyjściowy (to jest po to, aby nie trzeba było kopiować)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../CallLibrary/libs/ExampleLib)

# Dodajemy ścieżkę, w ktorej mają być wyszukiwane pliki nagłówkowe
include_directories(include)

# Dodajemy pliki, które mają byc kompilowane
# STATIC - biblioteka będzie statyczna
add_library(exampleLib STATIC src/lib.cpp)