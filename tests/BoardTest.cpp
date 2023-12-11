
#include "Board.hpp"
#include "Tetrominos.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace tetris;

    TEST_CASE("Block rotation near board boundaries", "[Block][Board]") {

        Z_Tetromino z;
        S_Tetromino s;
        Board board(24, 10);

        SECTION("S rotation near left boundary") {
            s.rotate(1);
            s.move(4, 0);
            REQUIRE(board.blockHasInvalidPosition(s.blockPositions()) == false);
            s.rotate(1);
            REQUIRE(board.blockHasInvalidPosition(s.blockPositions()) == true);
        }

        SECTION("Z rotation near right boundary") {
            z.rotate(1);
            z.move(-4, 0);
            REQUIRE(board.blockHasInvalidPosition(z.blockPositions()) == false);
            z.rotate(1);
            REQUIRE(board.blockHasInvalidPosition(z.blockPositions()) == true);
        }
    }

TEST_CASE("saveBlock operation", "[Board]") {

    Board board(24, 10);

    SECTION("Constructor") {
        REQUIRE(board.getGridValue(0, 0) == SpawnZone);
        REQUIRE(board.getGridValue(0, 23) == EmptyTile);
    }

    SECTION("saveBlock and getGridValue operation") {
        std::vector<threepp::Vector2> tiles = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
        board.saveBlock(tiles, 1);
        for (auto tile : tiles) {
            REQUIRE(board.getGridValue(tile.x, tile.y) == 1);
        }
    }
}