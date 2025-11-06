cmake_minimum_required(VERSION 3.25)

project(SmoothingImages)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(SmoothingImages smoothing_images.cpp)
target_link_libraries(SmoothingImages ${OpenCV_LIBS})

