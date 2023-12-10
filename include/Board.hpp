
#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP

#include "Block.hpp"
#include <threepp/math/Vector2.hpp>

namespace tetris {

    class Board {

    public:
        Board(int height, int width);
        std::vector<std::vector<int>> grid{};

        void initGrid();

        void saveBlock(std::vector<threepp::Vector2> tiles, int type);
        int getGridValue(int x, int y);
        void setGridValue(int x, int y, int value);
        bool checkBlockOutOfGrid(std::vector<threepp::Vector2> tiles);

        void rowCleanUp();
        int countRows();
        int boardHeight;
        int boardWidth;
        bool gridIsChanged;

        bool checkFullRow(int row);
        void deleteFullRow(int row);
        void moveRowDown(int row, int movement);

    private:
    };
}// namespace tetris

#endif//TETRIS_BOARD_HPP

