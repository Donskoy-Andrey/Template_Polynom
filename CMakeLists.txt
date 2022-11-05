cmake_minimum_required(VERSION 3.2)
project(main)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(
main src/main.cpp
src/polynom.hpp
src/quat.hpp
)