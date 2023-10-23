
#include "Blocks.hpp"

namespace tetris {
    // Blocks
    bool t_block[9]{
            0, 1, 0,
            1, 1, 1,
            0, 0, 0};

    bool s_block[2][9]{
            {0, 0, 0,
             0, 1, 1,
             1, 1, 0},
            {1, 0, 0,
             1, 1, 0,
             0, 1, 0}};
    bool z_block[9]{
            0, 0, 0,
            1, 1, 0,
            0, 1, 1};
    bool l_block[9]{
            0, 1, 0,
            0, 1, 0,
            0, 1, 1};

    int Blocks::GetBlock() {
        return 0;// Placeholder
    }
}// namespace tetris