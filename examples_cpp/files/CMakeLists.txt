cmake_minimum_required(VERSION 3.14)
project(cpp_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(file_analys)
add_subdirectory(file_write)
add_subdirectory(time_diff)
