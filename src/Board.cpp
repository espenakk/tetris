
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

    void Board::saveBlock(std::vector<threepp::Vector2> tiles, int type) {
        for (auto tile : tiles) {
            for (auto& gridItem : gridSlots) {
                if (gridItem.first == tile && gridItem.second == 0) {
                    gridItem.second = type;
                }
                }
            }
        gridIsChanged = true;
    }

    bool Board::isSlotOccupied(std::vector<threepp::Vector2> tiles) {
        for (threepp::Vector2 item : tiles) {
                if (item.x < 0 || item.x >= amountOfRows || item.y < 0 || item.y >= amountOfColumns) {
                return true;// If the new position is outside of the predefined grid
                }
                for (auto& gridItem : gridSlots) {
                if (gridItem.first == item && gridItem.second != 0 && gridItem.second != 8) {
                    return true;// That position in the grid is occupied
                }
                }
        }
        return false;// Position is not occupied and within the grid
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