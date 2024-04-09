cmake_minimum_required(VERSION 3.27)
project(cg_from_scratch_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(cg_from_scratch_cpp main.cpp
        TGA/TGAImage.cpp
        TGA/TGAImage.h
        TGA/TGAColor.h
        TGA/TGAColor.cpp
        Canvas.cpp
        Canvas.h)
