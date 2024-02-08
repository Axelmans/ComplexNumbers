cmake_minimum_required(VERSION 3.21)
project(ComplexNumbers)

add_executable(
        ComplexNumbers
        src/ComplexNumber.cpp
        src/QuadraticEquation.cpp
        main.cpp
)

set(CMAKE_CXX_STANDARD 17)