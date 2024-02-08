cmake_minimum_required(VERSION 3.21)
project(ComplexNumbers)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ComplexNumbers
        src/ComplexNumber.cpp
        src/QuadraticEquation.cpp
        main.cpp
)