
#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP

#include "Block.hpp"
#include <threepp/math/Vector2.hpp>

namespace tetris {

    class Board {

    public:
        Board(int height, int width);
        std::vector<std::vector<int>> grid{};
        int boardHeight;
        int boardWidth;

        void saveBlock(std::vector<threepp::Vector2> tiles, int type);
        int getGridValue(int x, int y);
        bool checkBlockOutOfGrid(std::vector<threepp::Vector2> tiles);
        void rowCleanUp();
        int countRows();
        bool checkGameOver(std::vector<threepp::Vector2> tiles);

    private:
        bool checkFullRow(int row);
        void deleteFullRow(int row);
        void moveRowDown(int row, int movement);
        int spawnOffset;
        void setGridValue(int x, int y, int value);
        bool hasBlock(int x, int y);
    };
}// namespace tetris

#endif//TETRIS_BOARD_HPP

