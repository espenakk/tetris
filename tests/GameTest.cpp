
#include "Board.hpp"
#include "Tetrominos.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace tetris;
TEST_CASE("Block rotation near board boundaries", "[Block][Board]") {

    Z_Tetromino z;
    S_Tetromino s;

    tetris::Board board(20, 10);

    SECTION("S rotation near left boundary") {
        s.rotate(1);                                                    // Rotate block
        s.move(4, 0);                                                   // Move s close to left boundary
        REQUIRE(board.checkBlockOutOfGrid(s.blockPositions()) == false);// Check if s is out of grid
        s.rotate(1);                                                    // Rotate s
        REQUIRE(board.checkBlockOutOfGrid(s.blockPositions()) == true); // Check if s is out of grid
    }

    SECTION("Z rotation near right boundary") {
        z.rotate(1);                                                    // Rotate z
        z.move(-4, 0);                                                  // Move z close to left boundary
        REQUIRE(board.checkBlockOutOfGrid(z.blockPositions()) == false);// Check if z is out of grid
        z.rotate(1);                                                    // Rotate z
        REQUIRE(board.checkBlockOutOfGrid(z.blockPositions()) == true); // Check if z is out of grid
    }
}