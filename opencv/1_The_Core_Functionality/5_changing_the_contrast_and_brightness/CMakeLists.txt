cmake_minimum_required(VERSION 3.5)

project(ContrastBrightness)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ContrastBrightness change_contrast_brightness.cpp)
target_link_libraries(ContrastBrightness ${OpenCV_LIBS})
