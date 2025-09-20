cmake_minimum_required(VERSION 3.10)
project(nnc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(eigen INTERFACE)
target_include_directories(eigen INTERFACE ${CMAKE_SOURCE_DIR}/ext/eigen-3.4.0)

file(GLOB
    src_folder
    "src/*.cpp"
    "src/**/*.cpp"
    "test/*.cpp"
)

add_executable(nnc ${src_folder})
target_link_libraries(nnc eigen)
