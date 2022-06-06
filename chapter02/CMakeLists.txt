# reference:
# https://trenki2.github.io/blog/2017/06/02/using-sdl2-with-cmake/

cmake_minimum_required(VERSION 3.13)
project(chapter02 CXX)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(02.out Main.cpp Game.cpp)
target_link_libraries(02.out ${SDL2_LIBRARIES})