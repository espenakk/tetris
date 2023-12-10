
#include "Tetrominos.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Block operations", "[Block]") {

    tetris::T_Tetromino block;

    SECTION("Constructor") {
        REQUIRE(block.blockPositions().empty());// Assuming the block is empty initially
    }

    SECTION("Move operation") {
        block.move(5, 5);
        auto positions = block.blockPositions();
        for (auto pos : positions) {
            REQUIRE(pos.x >= 5);
            REQUIRE(pos.y >= 5);
        }
    }

    SECTION("Rotate operation") {
        block.rotate(1);
        auto positions = block.blockPositions();
        REQUIRE(block.rotationState == 1);
    }
}