cmake_minimum_required(VERSION 3.10)
project(nnc)
set(CMAKE_CXX_STANDARD 14)

file(GLOB src_folder
    "includes/*.h"
    "src/*.cpp"
)

add_executable(nnc ${src_folder})