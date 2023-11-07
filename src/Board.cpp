
#include "Board.hpp"
#include "Render.hpp"
#include "threepp/threepp.hpp"
#include <iostream>

namespace tetris {

    Board::Board() {
        amountOfRows = 21;
        amountOfColumns = 12;
        blockSize = 4;
        initGrid();
    }
    void Board::initGrid() {
        for (int row = 0; row < amountOfRows; row++) {
            for (int column = 0; column < amountOfColumns; column++) {
                if ((column == 0) || (column == amountOfColumns - 1) || (row == amountOfRows - 1)) {
                    grid[row][column] = 2;
                } else {
                    grid[row][column] = 0;
                }
            }
        }
        gridIsChanged = 1;
    }
    void Board::printGrid() {
        for (int i = 0; i < amountOfRows; i++) {
            for (int j = 0; j < amountOfColumns; j++) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    void Board::saveBlock(std::vector<Position> tiles) {
        for (auto tile : tiles) {
            grid[tile.row][tile.column] = 1;
        }
        gridIsChanged = 1;
    }
    int Board::whatIsGridValue(int x, int y) {
        int gridvalue = 0;
        if (grid[x][y] == 0)
            gridvalue = 0;
        else if (grid[x][y] == 1)
            gridvalue = 1;
        else if (grid[x][y] == 2)
            gridvalue = 2;
        return gridvalue;
    }
    void Board::testwhatisgrid(int x, int y) {
        int test = whatIsGridValue(x, y);
        std::cout << test << " ";
    }

    std::shared_ptr<threepp::Group> Board::drawGrid() {
        std::shared_ptr<threepp::Group> gridGroup = threepp::Group::create();
        Render renderGrid(0.9, 0.9);
        if (gridIsChanged == 1) {
            for (float i = 0; i < amountOfRows; i++) {
                for (float j = 0; j < amountOfColumns; j++) {
                    if (whatIsGridValue(i, j) == 0) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::gray));
                    } else if (whatIsGridValue(i, j) == 1) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::green));
                    } else if (whatIsGridValue(i, j == 2)) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::black));
                    }
                }
            }
        }
        gridIsChanged = 0;
        return gridGroup;
    }
    bool Board::checkOutOfGrid(int x, int y) {
        if (x > amountOfRows - 2)
            return true;
        if (y < 1)
            return true;
        if (y > amountOfColumns - 2)
            return true;

        return false;
    }
    /* bool Board::checkCollision(int x, int y) {
        if(){}
    }
*/
    bool Board::checkBlockOutOfGrid(std::vector<Position> tiles) {
        for (Position item : tiles) {
            //if(checkOutOfGrid(item.row, item.column)){
            //    return true;
            //}
            if (grid[item.row][item.column] != 0) {
                return true;
            }
        }
        return false;
    }

}// namespace tetris