
#include "Board.hpp"

namespace tetris {

    Board::Board(int height, int width) {
        boardHeight = height;
        boardWidth = width;

        for (int i = 0; i < boardHeight; i++) {
            std::vector<int>& vector_row = grid.emplace_back();
            for (int j = 0; j < boardWidth; j++) {
                vector_row.push_back(0);
            }
        }
        gridIsChanged = true;
    }

    void Board::initGrid() {
        for (int i = 0; i < boardHeight; i++) {
            for (int j = 0; j < boardWidth; j++) {
                setGridValue(i, j, 0);
            }
        }
    }

    void Board::saveBlock(std::vector<threepp::Vector2> tiles, int type) {
        for (auto tile : tiles) {
            setGridValue(tile.x, tile.y, type);
        }
        gridIsChanged = true;
    }

    int Board::getGridValue(int x, int y) {
        return grid.at(y).at(x);
    }

    void Board::setGridValue(int x, int y, int value) {
        grid.at(y).at(x) = value;
    }

    bool Board::checkBlockOutOfGrid(std::vector<threepp::Vector2> tiles) {
        for (auto item : tiles) {
            if (item.x > boardWidth - 1 || item.x < 0) {
                return true;
            }
            if (item.y > boardHeight - 1) {
                return true;
            }
            if (getGridValue(item.x, item.y) != 0) {
                return true;
            }
        }
        return false;
    }

    //Checks if row are filled with blocks
    bool Board::checkFullRow(int y) {
        for (int i = 0; i < boardWidth; i++) {
            if (getGridValue(i, y) == 0) {
                return false;
            }
        }
        return true;
    }
    //Deletes row
    void Board::deleteFullRow(int y) {
        for (int i = 0; i < boardWidth; i++) {
            setGridValue(i, y, 0);
        }
    }
    //Copies all values from a row to row+movement down the grid. Sets original row to 0
    void Board::moveRowDown(int y, int movement) {
        for (int i = 0; i < boardWidth; i++) {
            setGridValue(i, y + movement, getGridValue(i, y));
            setGridValue(i, y, 0);
        }
    }
    //Checks, moves and deletes rows when they are full.
    void Board::rowCleanUp() {
        int amountOfFullRows = 0;
        for (int i = boardHeight - 1; i > 0; i--) {
            if (checkFullRow(i)) {
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
        for (int i = boardHeight - 1; i > 0; i--) {
            if (checkFullRow(i)) {
                amount++;
            }
        }
        return amount;
    }
}// namespace tetris