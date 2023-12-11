
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
    CHECK(t.type == T);
    CHECK(s.type == S);
    CHECK(z.type == Z);
    CHECK(l.type == L);
    CHECK(j.type == J);
    CHECK(i.type == I);
    CHECK(o.type == O);
}

TEST_CASE("test peak rotations") {
}