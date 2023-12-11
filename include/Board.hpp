
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
        bool blockHasInvalidPosition(std::vector<threepp::Vector2> tiles);
        void rowCleanUp();
        int countCompleteLines();
        bool checkGameOver(std::vector<threepp::Vector2> tiles);

    private:
        bool completedLine(int row);
        void clearCompletedLine(int row);
        void moveLineDown(int row, int lines);
        int spawnOffset;
        void setGridValue(int x, int y, int value);
        bool hasBlock(int x, int y);
    };
}// namespace tetris

#endif//TETRIS_BOARD_HPP

