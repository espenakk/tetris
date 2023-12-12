
add_library(tetris_lib Board.cpp Input.cpp Game.cpp Visuals.cpp Tetrominos.cpp Block.cpp Random.cpp)

target_link_libraries(tetris_lib PUBLIC threepp::threepp)

target_include_directories(tetris_lib PUBLIC "${CMAKE_SOURCE_DIR}/include")