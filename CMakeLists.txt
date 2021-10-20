cmake_minimum_required(VERSION 3.20)
project(OOP_2021)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "-fexec-charset=CP949")

add_executable(OOP_2021 practice-code/operator_overloading.cpp practice-code/virtual/q10/q10.cpp practice-code/virtual/q10/Circle.cpp practice-code/virtual/q10/Circle.h practice-code/virtual/q10/Shape.cpp practice-code/virtual/q10/Shape.h practice-code/virtual/q10/Rect.cpp practice-code/virtual/q10/Rect.h practice-code/virtual/q10/Line.cpp practice-code/virtual/q10/Line.h)
