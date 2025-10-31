cmake_minimum_required(VERSION 3.5)

project(Operations)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Operations operations.cpp)
target_link_libraries(Operations ${OpenCV_LIBS})
