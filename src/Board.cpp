
#include "Board.hpp"

namespace tetris {

    Board::Board() {
        amountOfRows = 24;
        amountOfColumns = 10;
        initializeGrid();
        gridIsChanged = true;
    }
    void Board::initializeGrid() {
        for (int row = 0; row < amountOfRows; row++) {
            for (int column = 0; column < amountOfColumns; column++) {
                int value = (row < 4) ? 8 : 0;
                gridSlots.emplace_back(threepp::Vector2{column, row}, value);
            }
        }
    }

    void Board::saveBlock(std::vector<threepp::Vector2> blockPositions, int type) {
        for (auto slot : blockPositions) {
            for (auto& gridItem : gridSlots) {
                if (gridItem.first.x == slot.y && gridItem.first.y == slot.x && gridItem.second == 0) {
                    gridItem.second = type;
                }
            }
        }
        gridIsChanged = true;
    }

    bool Board::isInsideGrid(std::vector<threepp::Vector2> blockPositions) {
        for (auto& position : blockPositions) {
            if (position.x < 0 || position.x >= amountOfRows || position.y < 0 || position.y >= amountOfColumns) {
                return false;
            }
        }
        return true;
    }

    bool Board::isOccupied(std::vector<threepp::Vector2> blockPositions) {
        for (auto& position : blockPositions) {
            for (auto& gridItem : gridSlots) {
                if (gridItem.first == position && gridItem.second != 0 && gridItem.second != 8) {
                    return true;
                }
            }
        }
        return false;
    }

    //Checks if row are filled with blocks
    bool Board::checkFullRow(int row) {
        for (auto& gridItem : gridSlots) {
                if (gridItem.first.x == row && gridItem.second == 0) {
                return false;
                }
        }
        return true;
    }

    //Deletes row (except boardwalls)
    void Board::deleteFullRow(int row) {
        for (auto& gridItem : gridSlots) {
                if (gridItem.first.x == row) {
                gridItem.second = 0;
                }
        }
    }
    //Copies all values from a row to row+movement down the gridSlots. Sets original row to 0
    void Board::moveRowDown(int row, int movement) {
        for (auto& gridItem : gridSlots) {
                if (gridItem.first.x == row) {
                auto it = std::find_if(gridSlots.begin(), gridSlots.end(), [&](const std::pair<threepp::Vector2, int>& pair) {
                    return pair.first.x == row + movement && pair.first.y == gridItem.first.y;
                });
                if (it != gridSlots.end()) {
                    it->second = gridItem.second;
                    gridItem.second = 0;
                }
                }
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