
#include "Tetrominos.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("test Person") {
    tetris::T_Tetromino t;
    tetris::S_Tetromino s;
    tetris::Z_Tetromino z;
    tetris::L_Tetromino l;
    tetris::J_Tetromino j;
    tetris::I_Tetromino i;
    tetris::O_Tetromino o;
    CHECK(t.type == 0);
    CHECK(s.type == 1);
    CHECK(z.type == 2);
    CHECK(l.type == 3);
    CHECK(j.type == 4);
    CHECK(i.type == 5);
    CHECK(o.type == 6);
}
