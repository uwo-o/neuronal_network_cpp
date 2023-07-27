cmake_minimum_required(VERSION 3.10)
project(nnc)
set(CMAKE_CXX_STANDARD 14)

add_executable(nnc main.cpp menu.cpp menu.hpp network.cpp network.hpp activation_functions.hpp constants.hpp neuron.cpp neuron.hpp)