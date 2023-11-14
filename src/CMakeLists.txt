
add_library(tetris_lib Board.cpp Blocks.cpp Input.cpp Game.cpp Render.cpp Tetrominos.cpp Block.cpp Position.cpp Random.cpp)

target_link_libraries(tetris_lib PUBLIC threepp::threepp)

target_include_directories(tetris_lib PUBLIC "${CMAKE_SOURCE_DIR}/include")