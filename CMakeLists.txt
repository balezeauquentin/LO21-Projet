cmake_minimum_required(VERSION 3.23)
project(LO21_projet C)

set(CMAKE_C_STANDARD 99)

add_executable(LO21_projet main.c liste_bit.c liste_bit.h Individu.c Individu.h Population.c Population.h)
