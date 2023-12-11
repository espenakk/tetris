
#include "Board.hpp"
#include "Tetrominos.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace tetris;
TEST_CASE("Block rotation near board boundaries", "[Block][Board]") {

    Z_Tetromino z;
    S_Tetromino s;

    tetris::Board board(20, 10);

    SECTION("S rotation near left boundary") {
        s.rotate(1);
        s.move(4, 0);
        REQUIRE(board.checkBlockOutOfGrid(s.blockPositions()) == false);
        s.rotate(1);
        REQUIRE(board.checkBlockOutOfGrid(s.blockPositions()) == true);
    }

    SECTION("Z rotation near right boundary") {
        z.rotate(1);
        z.move(-4, 0);
        REQUIRE(board.checkBlockOutOfGrid(z.blockPositions()) == false);
        z.rotate(1);
        REQUIRE(board.checkBlockOutOfGrid(z.blockPositions()) == true);
    }
}