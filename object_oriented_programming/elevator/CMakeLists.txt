cmake_minimum_required(VERSION 3.14)
project(elevator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    elevator.cpp
    main.cpp
)

set(PROJECT_HEADERS
    elevator.h
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE msoftcon)
