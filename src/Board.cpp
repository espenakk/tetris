
#include "Board.hpp"
#include "Render.hpp"
#include "threepp/threepp.hpp"
#include <iostream>

namespace tetris {

    Board::Board() {
        amountOfRows = 21;
        amountOfColumns = 12;
        initGrid();
        gridIsChanged = 1;
    }
    void Board::initGrid() {
        for (int row = 0; row < amountOfRows; row++) {
            for (int column = 0; column < amountOfColumns; column++) {
                if ((column == 0) || (column == amountOfColumns - 1) || (row == amountOfRows - 1)) {
                    grid[row][column] = 8;
                } else {
                    grid[row][column] = 0;
                }
            }
        }
    }
    void Board::printGrid() {
        for (int i = 0; i < amountOfRows; i++) {
            for (int j = 0; j < amountOfColumns; j++) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    void Board::saveBlock(std::vector<Position> tiles, int type) {
        for (auto tile : tiles) {
            grid[tile.row][tile.column] = type + 1;
        }
        gridIsChanged = 1;
    }
    int Board::whatIsGridValue(int x, int y) {
        if (grid[x][y] == 0)
            return 0;
        else if (grid[x][y] == 1)
            return 1;
        else if (grid[x][y] == 2)
            return 2;
        else if (grid[x][y] == 3)
            return 3;
        else if (grid[x][y] == 4)
            return 4;
        else if (grid[x][y] == 5)
            return 5;
        else if (grid[x][y] == 6)
            return 6;
        else if (grid[x][y] == 7)
            return 7;
        else if (grid[x][y] == 8)
            return 8;
        return 0;
    }
    std::shared_ptr<threepp::Group> Board::drawGrid() {
        std::shared_ptr<threepp::Group> gridGroup = threepp::Group::create();
        Render renderGrid(0.9, 0.9);
        if (gridIsChanged == 1) {
            for (float i = 0; i < amountOfRows; i++) {
                for (float j = 0; j < amountOfColumns; j++) {
                    if (whatIsGridValue(i, j) == 0) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::gray));
                    } else if (whatIsGridValue(i, j) == 8) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::black));
                    } else if (whatIsGridValue(i, j) == 1) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::blueviolet));
                    } else if (whatIsGridValue(i, j) == 2) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::limegreen));
                    } else if (whatIsGridValue(i, j) == 3) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::red));
                    } else if (whatIsGridValue(i, j) == 4) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::darkorange));
                    } else if (whatIsGridValue(i, j) == 5) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::deepskyblue));
                    } else if (whatIsGridValue(i, j) == 6) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::cyan));
                    } else if (whatIsGridValue(i, j) == 7) {
                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::yellow));
                    }
                }
            }
        }
        gridIsChanged = 0;
        return gridGroup;
    }
    bool Board::checkBlockOutOfGrid(std::vector<Position> tiles) {
        for (Position item : tiles) {
            if (grid[item.row][item.column] != 0) {
                return true;
            }
        }
        return false;
    }

    //Checks if row are filled with blocks (except boardwalls)
    bool Board::checkFullRow(int row) {
        for (int i = 1; i < amountOfColumns - 1; i++) {
            if (grid[row][i] == 0) {
                return false;
            }
        }
        return true;
    }
    //Deletes row (except boardwalls)
    void Board::deleteFullRow(int row) {
        for (int i = 1; i < amountOfColumns - 1; i++) {
            grid[row][i] = 0;
        }
    }
    //Copies all values from a row to row+movement down the grid. Sets original row to 0
    void Board::moveRowDown(int row, int movement) {
        for (int i = 1; i < amountOfColumns - 1; i++) {
            grid[row + movement][i] = grid[row][i];
            grid[row][i] = 0;
        }
    }
    //Checks, moves and deletes rows when they are full.
    void Board::rowCleanUp() {
        int amountOfFullRows = 0;
        for (int i = amountOfRows - 2; i > 0; i--) {
            if (checkFullRow(i) == true) {
                amountOfFullRows++;
                deleteFullRow(i);
            } else if (amountOfFullRows > 0) {
                moveRowDown(i, amountOfFullRows);
            }
        }
    }
    //Checks how many rows are full and returns amount
    int Board::countRows() {
        int amount = 0;
        for (int i = amountOfRows - 2; i > 0; i--) {
            if (checkFullRow(i) == true) {
                amount++;
            }
        }
        return amount;
    }
}// namespace tetris