#include "Block.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Block operations", "[Block]") {

    tetris::Block block;

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
        // Assuming the block has a getter for rotationState
        REQUIRE(block.rotationState == 1);
    }

    SECTION("blockPositions operation") {
        auto positions = block.blockPositions(2, 2, 1);
        for (auto pos : positions) {
            REQUIRE(pos.x >= 2);
            REQUIRE(pos.y >= 2);
        }
    }

    SECTION("Peak operation") {
        auto peakPositions = block.peak(2, 2, 1);
        for (auto pos : peakPositions) {
            REQUIRE(pos.x >= 2);
            REQUIRE(pos.y >= 2);
        }
    }
}