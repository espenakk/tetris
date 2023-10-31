
#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP
#include "Blocks.hpp"

namespace tetris {

    class Board {

    public:
        Board();
        bool grid[20][10]{};
        void initGrid();
        void printGrid();

        bool block[4][4]{};
        void insertNewBlock(int type, int rotation);


        //std::shared_ptr<threepp::Mesh> drawGrid();

    private:
        int amountOfRows;
        int amountOfColumns;
    };
}// namespace tetris

#endif//TETRIS_BOARD_HPP
