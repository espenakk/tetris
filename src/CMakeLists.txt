add_executable(tetris main.cpp)
add_library(tetris_lib Board.cpp Blocks.cpp Input.cpp)

target_link_libraries(tetris PRIVATE threepp::threepp imgui::imgui tetris_lib)
target_link_libraries(tetris_lib PRIVATE threepp::threepp imgui::imgui)

target_include_directories(tetris PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(tetris_lib PUBLIC "${CMAKE_SOURCE_DIR}/include")