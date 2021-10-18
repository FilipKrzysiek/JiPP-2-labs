cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD  17)

# Dodajemy folder z bibliotekami
add_subdirectory(libs)

# Dodajemy ścieżkę, w której mają być wyszukiwane pliki nagłówkowe
include_directories(libs/ExampleLib/include)

# Dodajemy pliki do kompilacji
add_executable(callLibrary src/main.cpp)

# Załączamy do naszej aplikacji biblioteki. Musi to być po add_executable
target_link_libraries(callLibrary exampleLibCall)