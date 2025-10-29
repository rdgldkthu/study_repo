cmake_minimum_required(VERSION 3.5)

project(DisplayImage)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(DisplayImage DisplayImage.cpp)
target_link_libraries(DisplayImage ${OpenCV_LIBS})
