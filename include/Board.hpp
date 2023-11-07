
#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP
#include "Blocks.hpp"
#include "threepp/threepp.hpp"
#include <iostream>

#include <threepp/threepp.hpp>
#include <iostream>

#include "Blocks.hpp"

namespace tetris {

    class Board {

    public:
        Board();
        int grid[21][12]{};
        void initGrid();
        void printGrid();


        int block[4][4];
        void saveBlock(int type, int rotation, int x, int y);
        int whatIsGridValue(int x, int y);
        void testwhatisgrid(int x, int y);

        std::shared_ptr<threepp::Group> drawGrid();
        std::shared_ptr<threepp::Mesh> create3dGrid(const threepp::Vector3& pos, const threepp::Color& color, float boxWidth, float boxHeight);

    private:
        int amountOfRows;
        int amountOfColumns;
        int blockSize;
    };
}// namespace tetris

#endif//TETRIS_BOARD_HPP
