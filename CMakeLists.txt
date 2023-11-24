cmake_minimum_required(VERSION 3.26)
project(Pendu C)

set(CMAKE_C_STANDARD 11)

add_executable(Pendu main.c
        Pendu.c
        Pendu.h
)
