cmake_minimum_required(VERSION 3.25)

project(Morphology)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Morphology morphology.cpp)
target_link_libraries(Morphology ${OpenCV_LIBS})

