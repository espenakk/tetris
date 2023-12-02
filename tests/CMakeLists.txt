
add_executable(BlockType BlockType.cpp)
add_test(NAME BlockType COMMAND test)
target_link_libraries(BlockType PUBLIC tetris_lib Catch2::Catch2WithMain)

