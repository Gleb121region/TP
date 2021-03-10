cmake_minimum_required(VERSION 3.17)
project(Fake)

set(CMAKE_CXX_STANDARD 14)

add_executable(Fake main.cpp
        shape.hpp
        rectangle.hpp rectangle.cpp
        circle.hpp circle.cpp
        diamond.cpp diamond.hpp
        CompositeShape.cpp CompositeShape.hpp
        Errors.hpp)