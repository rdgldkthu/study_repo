cmake_minimum_required(VERSION 3.5)

project(BasicDrawing)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(BasicDrawing basic_drawing.cpp)
target_link_libraries(BasicDrawing ${OpenCV_LIBS})
