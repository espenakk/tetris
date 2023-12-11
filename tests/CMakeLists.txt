
function(add_test_executable name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} PUBLIC tetris_lib Catch2::Catch2WithMain)
    add_test(NAME ${name} COMMAND ${name})
endfunction()

add_test_executable(BoardTest BoardTest.cpp)
add_test_executable(GameTest GameTest.cpp)
add_test_executable(RandomTest RandomTest.cpp)
add_test_executable(TetrominosTest TetrominosTest.cpp)
add_test_executable(VisualsTest VisualsTest.cpp)
