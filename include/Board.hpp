
#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP

#include "Block.hpp"
#include <threepp/math/Vector2.hpp>
#include <threepp/math/Vector3.hpp>
#include <vector>

namespace tetris {

    class Board {

    public:
        Board();
        int type;
        std::vector<std::pair<threepp::Vector2, int>> gridSlots;
        void initializeGrid();

        void saveBlock(std::vector<threepp::Vector2> blockPositions, int type);
        bool isInsideGrid(std::vector<threepp::Vector2> blockPositions);
        bool isOccupied(std::vector<threepp::Vector2> blockPositions);
        void rowCleanUp();
        int countRows();

        int amountOfRows;
        int amountOfColumns;
        bool gridIsChanged;

    private:
        bool checkFullRow(int row);
        void deleteFullRow(int row);
        void moveRowDown(int row, int movement);
    };
}// namespace tetris

#endif//TETRIS_BOARD_HPP
