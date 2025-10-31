cmake_minimum_required(VERSION 3.5)

project(Mask)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Mask mask.cpp)
target_link_libraries(Mask ${OpenCV_LIBS})
