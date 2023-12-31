cmake_minimum_required(VERSION 3.26)
project(src C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(src
        DFS.c
        DFS.h
        druk.c
        druk.h
        labirynt.c
        labirynt.h
        main.c
        prim.c
        prim.h
        solver.c
        solver.h
        wilson.c
        wilson.h)
