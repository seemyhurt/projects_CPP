cmake_minimum_required(VERSION 3.14)
project(cpp_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(append_string)
add_subdirectory(only_numbers)
add_subdirectory(sorted_string)
add_subdirectory(symbol_count)
