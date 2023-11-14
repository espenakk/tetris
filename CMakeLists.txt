
cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(tetris)
find_package(threepp CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(bin)
add_subdirectory(tests)
