cmake_minimum_required(VERSION 3.5)

project(AddImages)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(AddImages add_images.cpp)
target_link_libraries(AddImages ${OpenCV_LIBS})
