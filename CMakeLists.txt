cmake_minimum_required(VERSION 3.13)
project(Image2StringImage)

set(CMAKE_CXX_STANDARD 14)

add_executable(Image2StringImage main.cpp)

find_package(OpenCV REQUIRED)
target_link_libraries(Image2StringImage ${OpenCV_LIBS})