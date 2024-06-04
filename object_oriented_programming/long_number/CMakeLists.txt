cmake_minimum_required(VERSION 3.14)
project(long_number LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    long_number.cpp
    app.cpp
)

set(PROJECT_HEADERS
    long_number.h
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)
