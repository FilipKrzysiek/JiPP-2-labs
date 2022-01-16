cmake_minimum_required(VERSION 3.16)

project(matrixTest)

add_executable(matrixTest src/main.cpp src/TimeMeasure.cpp)

target_include_directories(matrixTest PUBLIC include)