add_executable(tetris main.cpp)
target_link_libraries(tetris PRIVATE threepp::threepp imgui::imgui)
target_include_directories(tetris PUBLIC "${CMAKE_SOURCE_DIR}/include")