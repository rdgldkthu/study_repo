cmake_minimum_required(VERSION 3.5)

project(RandomGeneratorAndText)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(RandomGeneratorAndText random_generator_and_text.cpp)
target_link_libraries(RandomGeneratorAndText ${OpenCV_LIBS})
