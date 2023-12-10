
#include "Tetrominos.hpp"
#include <catch2/catch_test_macros.hpp>

using namespace tetris;

TEST_CASE("test tetromino types") {
    T_Tetromino t;
    S_Tetromino s;
    Z_Tetromino z;
    L_Tetromino l;
    J_Tetromino j;
    I_Tetromino i;
    O_Tetromino o;
    CHECK(t.type == 1);
    CHECK(s.type == 2);
    CHECK(z.type == 3);
    CHECK(l.type == 4);
    CHECK(j.type == 5);
    CHECK(i.type == 6);
    CHECK(o.type == 7);
}