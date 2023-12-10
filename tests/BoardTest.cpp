#include "Board.hpp"
#include "Tetrominos.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace tetris;
TEST_CASE("Block rotation near board boundaries", "[Block][Board]") {

    Z_Tetromino z;
    S_Tetromino s;

    tetris::Board board(20, 10);

    SECTION("Z rotation near left boundary") {
        z.rotate(1);                                                    // Rotate block
        z.move(4, 0);                                                   // Move z close to left boundary
        REQUIRE(board.checkBlockOutOfGrid(z.blockPositions()) == false);// Check if z is out of grid
        z.rotate(1);                                                    // Rotate z
        REQUIRE(board.checkBlockOutOfGrid(z.blockPositions()) == true); // Check if z is out of grid
    }

    SECTION("S rotation near right boundary") {
        s.rotate(1);                                                    // Rotate s
        s.move(-4, 0);                                                  // Move s close to left boundary
        REQUIRE(board.checkBlockOutOfGrid(s.blockPositions()) == false);// Check if s is out of grid
        s.rotate(1);                                                    // Rotate s
        REQUIRE(board.checkBlockOutOfGrid(s.blockPositions()) == true); // Check if s is out of grid
    }
}

TEST_CASE("Board operations", "[Board]") {

    tetris::Board board(24, 10);

    SECTION("Constructor") {
        REQUIRE(board.getGridValue(0, 0) == 0);
        REQUIRE(board.getGridValue(0, 23) == 8);//TODO: Fix this
    }

    SECTION("saveBlock operation") {
        std::vector<threepp::Vector2> tiles = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
        board.saveBlock(tiles, 1);
        for (auto tile : tiles) {
            REQUIRE(board.getGridValue(tile.x, tile.y) == 1);
        }
    }

    SECTION("getGridValue and setGridValue operations") {
        board.setGridValue(0, 0, 1);
        REQUIRE(board.getGridValue(0, 0) == 1);
    }

    SECTION("checkBlockOutOfGrid operation") {
        std::vector<threepp::Vector2> tiles = {{0, 1}};
        REQUIRE(board.checkBlockOutOfGrid(tiles) == false);
        tiles = {{1, 25}};
        REQUIRE(board.checkBlockOutOfGrid(tiles) == true);
        tiles = {{-1, 1}};
        REQUIRE(board.checkBlockOutOfGrid(tiles) == true);
    }

    SECTION("checkFullRow, deleteFullRow, and moveRowDown operations") {
        for (int i = 0; i < 10; i++) {
            board.setGridValue(i, 19, 1);
        }
        REQUIRE(board.checkFullRow(19) == true);
        board.deleteFullRow(19);
        REQUIRE(board.checkFullRow(19) == false);
        for (int i = 0; i < 10; i++) {
            board.setGridValue(i, 18, 1);
        }
        board.moveRowDown(18, 1);
        REQUIRE(board.checkFullRow(19) == true);
    }

    SECTION("rowCleanUp operation") {
        for (int i = 0; i < 10; i++) {
            board.setGridValue(i, 19, 1);
            board.setGridValue(i, 18, 1);
        }
        board.rowCleanUp();
        REQUIRE(board.checkFullRow(19) == false);
        REQUIRE(board.checkFullRow(18) == false);
    }

    SECTION("countRows operation") {
        for (int i = 0; i < 10; i++) {
            board.setGridValue(i, 19, 1);
            board.setGridValue(i, 18, 1);
        }
        REQUIRE(board.countRows() == 2);
    }
}