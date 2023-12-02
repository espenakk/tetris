
#include "Block.hpp"
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
    CHECK(t.type == 0);
    CHECK(s.type == 1);
    CHECK(z.type == 2);
    CHECK(l.type == 3);
    CHECK(j.type == 4);
    CHECK(i.type == 5);
    CHECK(o.type == 6);
}
