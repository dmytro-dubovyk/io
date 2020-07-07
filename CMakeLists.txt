cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "io_example")

project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wshadow -Wundef -Wno-missing-field-initializers")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cfile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cppfile.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/widget.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
