
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


        int block[4][4];
        void saveBlock(std::vector<Position> tiles);

        int whatIsGridValue(int x, int y);
        bool checkOutOfGrid(int x, int y);

        bool checkBlockOutOfGrid(std::vector<Position> tiles);

        void checkFullLines();


        void testwhatisgrid(int x, int y);

        std::shared_ptr<threepp::Group> drawGrid();
    private:
        int amountOfRows;
        int amountOfColumns;
        int blockSize;
        bool gridIsChanged;
    };
}// namespace tetris

#endif//TETRIS_BOARD_HPP
