cmake_minimum_required(VERSION 3.6)
project(pantomime)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Figure.h src/Point.cpp src/Point.h src/Figure.cpp src/Field.cpp src/Field.h src/Matrix.cpp src/Matrix.h)
add_executable(pantomime ${SOURCE_FILES})