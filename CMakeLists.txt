cmake_minimum_required(VERSION 3.15)
project(tetris)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)
target_link_libraries(tetris PRIVATE threepp::threepp)
