
#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP

#include "Block.hpp"

namespace tetris {

    class Board {

    public:
        Board(int height, int width);

        int boardHeight;
        int boardWidth;
        void saveBlock(const std::vector<threepp::Vector2>& tiles, int type);
        int getGridValue(int x, int y);
        bool blockHasInvalidPosition(const std::vector<threepp::Vector2>& tiles);
        void rowCleanUp();
        int countCompleteLines();
        bool checkGameOver(const std::vector<threepp::Vector2>& tiles);

    private:
        int spawnOffset;
        std::vector<std::vector<int>> grid{};
        void setGridValue(int x, int y, int value);
        bool hasBlock(int x, int y);
        bool completedLine(int row);
        void clearCompletedLine(int row);
        void moveLineDown(int row, int lines);
    };
}// namespace tetris

#endif//TETRIS_BOARD_HPP

