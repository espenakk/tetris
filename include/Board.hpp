
#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP

#include "Block.hpp"
#include <array>
#include <threepp/math/Vector2.hpp>

namespace tetris {

    class Board {

    public:
        Board();
        int grid[21][12];
        void initGrid();

        void saveBlock(std::vector<threepp::Vector2> tiles, int type);
        int whatIsGridValue(int x, int y);
        int returnGridValue(int x, int y);
        bool checkBlockOutOfGrid(std::vector<threepp::Vector2> tiles);

        void rowCleanUp();
        int countRows();
        int boardHeight;
        int boardWidth;
        bool gridIsChanged;
    private:
        bool checkFullRow(int row);
        void deleteFullRow(int row);
        void moveRowDown(int row, int movement);
    };
}// namespace tetris

#endif//TETRIS_BOARD_HPP

