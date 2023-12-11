
#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP

#include "Block.hpp"

namespace tetris {

    class Board {

    public:
        Board(int height, int width);

        int boardHeight;
        int boardWidth;
        void saveBlock(const std::vector<threepp::Vector2>& tiles, TileType tileType);
        int getGridTileType(int x, int y);
        bool blockHasInvalidPosition(const std::vector<threepp::Vector2>& tiles);
        void rowCleanUp();
        int countCompleteLines();
        bool checkGameOver(const std::vector<threepp::Vector2>& tiles);
        void reset();

    private:
        int spawnOffset;
        std::vector<std::vector<TileType>> grid{};
        void setGridTileType(int x, int y, TileType tileType);
        bool hasBlock(int x, int y);
        bool completedLine(int line);
        void clearCompletedLine(int line);
        void moveLineDown(int line, int lines);
    };
}// namespace tetris

#endif//TETRIS_BOARD_HPP

