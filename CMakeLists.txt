cmake_minimum_required(VERSION 3.10)
project(nnc)
set(CMAKE_CXX_STANDARD 14)

include_directories(includes)

file(GLOB 
    src_folder
    "src/*.cpp"
    "src/**/*.cpp"
)

add_executable(nnc ${src_folder})