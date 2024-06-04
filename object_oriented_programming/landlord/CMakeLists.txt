cmake_minimum_required(VERSION 3.14)
project(landlord LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    landlord.cpp
    lordapp.cpp
)

set(PROJECT_HEADERS
    landlord.h
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)
