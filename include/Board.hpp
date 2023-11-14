
#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP
#include "Blocks.hpp"
#include "threepp/threepp.hpp"
#include <iostream>

#include <threepp/threepp.hpp>
#include <iostream>

#include "Block.hpp"

namespace tetris {

    class Board {

    public:
        Board();
        int grid[21][12]{};
        void initGrid();
        void printGrid();

        void saveBlock(std::vector<Position> tiles);
        int whatIsGridValue(int x, int y);
        bool checkBlockOutOfGrid(std::vector<Position> tiles);
        std::shared_ptr<threepp::Group> drawGrid();

        int rowCleanUp();

    private:
        int amountOfRows;
        int amountOfColumns;
        bool gridIsChanged;

        bool checkFullRow(int row);
        void deleteFullRow(int row);
        void moveRowDown(int row, int movement);
    };
}// namespace tetris

#endif//TETRIS_BOARD_HPP
