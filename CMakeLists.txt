
cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(tetris)
find_package(threepp CONFIG REQUIRED)
add_subdirectory(src)
add_subdirectory(bin)

option(TETRIS_BUILD_TESTS "Build tests" ON)
if (TETRIS_BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v3.4.0
    )
    FetchContent_MakeAvailable(Catch2)
    enable_testing()
    add_subdirectory(tests)
endif ()
