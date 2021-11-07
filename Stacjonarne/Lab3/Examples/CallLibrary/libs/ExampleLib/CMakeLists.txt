cmake_minimum_required(VERSION 3.16)

# tworzone pod linuxem, jeżeli uruchamiasz pod innym systemem zmień rozszerzenie pliku
add_library(exampleLibCall INTERFACE)
target_link_libraries(exampleLibCall INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/libexampleLib.a)