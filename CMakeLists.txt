enable_testing()
cmake_minimum_required(VERSION 3.10)
project(nnc)
set(CMAKE_CXX_STANDARD 14)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

enable_testing()

include_directories(include)
include_directories(ext)

file(GLOB 
    src_folder
    "src/*.cpp"
    "src/**/*.cpp"
    "test/*.cpp"
)

add_executable(nnc ${src_folder})
target_link_libraries(nnc Eigen3::Eigen)