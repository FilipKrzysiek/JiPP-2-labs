cmake_minimum_required(VERSION 3.16)

project(FirstClass)

set(CMAKE_CXX_STANDARD 17)

add_executable(FirstClass src/main.cpp src/MyFirstClass.cpp include/MyFirstClass.h)