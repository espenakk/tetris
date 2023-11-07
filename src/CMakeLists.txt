add_executable(tetris main.cpp)
add_library(tetris_lib Board.cpp Blocks.cpp Input.cpp Game.cpp Render.cpp Tetronimos.cpp Block.cpp Position.cpp Random.cpp)

target_link_libraries(tetris PRIVATE threepp::threepp tetris_lib)
target_link_libraries(tetris_lib PRIVATE threepp::threepp)

target_include_directories(tetris PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(tetris_lib PUBLIC "${CMAKE_SOURCE_DIR}/include")