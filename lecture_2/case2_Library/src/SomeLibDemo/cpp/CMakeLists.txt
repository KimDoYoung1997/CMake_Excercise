cmake_minimum_required(VERSION 3.13)
project(mearlymath)

# ar rcs libmearlymath.a adder.o 와 같은 기능을 함. 즉 adder.cpp를 통해 만들어진 obj 인 adder.o를 가지고 static library를 만듦
add_library(mearlymath adder.cpp)
