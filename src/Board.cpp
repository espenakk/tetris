
#include "Board.hpp"
#include "threepp/threepp.hpp"
#include <iostream>

namespace tetris {

    Board::Board() {
        amountOfRows = 20;
        amountOfColumns = 10;
        initGrid();
    }
    void Board::initGrid() {
        for (int row = 0; row < amountOfRows; row++) {
            for (int column = 0; column < amountOfColumns; column++) {
                grid[row][column] = 0;
            }
        }
    }
    void Board::printGrid() {
        for (int row = 0; row < amountOfRows; row++) {
            for (int column = 0; column < amountOfColumns; column++) {
                std::cout << grid[row][column] << " ";
            }
            std::cout << std::endl;
        }
    }
    void Board::insertNewBlock(int type, int rotation) {

        Blocks test;

        for (int row = 0; row < 4; row++) {
            for (int column = 0; column < 4; column++) {
                block[row][column] = test.getTetronimo(type, rotation, row, column);
            }
        }
        for (int row = 0; row < 4; row++) {
            for (int column = 0; column < 4; column++) {
                grid[row - 1][column + 3] = grid[row - 1][column + 3] + block[row][column];
            }
        }
    }
}// namespace tetris