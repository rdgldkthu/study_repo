cmake_minimum_required(VERSION 3.25)

project(ErodingDilating)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ErodingDilating eroding_dilating.cpp)
target_link_libraries(ErodingDilating ${OpenCV_LIBS})

