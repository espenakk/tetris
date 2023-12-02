
#add_executable(allTetrisTests BlockType.cpp test.cpp)
#add_test(NAME allTetrisTests COMMAND allTetrisTests)
#target_link_libraries(allTetrisTests PUBLIC tetris_lib Catch2::Catch2WithMain)

function(add_test_executable name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} PUBLIC tetris_lib Catch2::Catch2WithMain)
    add_test(NAME ${name} COMMAND ${name})
endfunction()

add_test_executable(BlockType BlockType.cpp)
add_test_executable(sillyTest sillyTest.cpp)

