
#include "Board.hpp"

namespace tetris {

    Board::Board() {
        boardHeight = 21;
        boardWidth = 12;
        initGrid();
        gridIsChanged = true;
    }

    void Board::initGrid() {
        for (int row = 0; row < boardHeight; row++) {
            for (int column = 0; column < boardWidth; column++) {
                if ((column == 0) || (column == boardWidth - 1) || (row == boardHeight - 1)) {
                    grid[row][column] = 8;
                } else {
                    grid[row][column] = 0;
                }
            }
        }
    }

    void Board::saveBlock(std::vector<threepp::Vector2> tiles, int type) {
        for (auto item : tiles) {
            int x = static_cast<int>(item.x);
            int y = static_cast<int>(item.y);
            grid[x][y] = type + 1;
        }
        gridIsChanged = true;
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
    }

    int Board::returnGridValue(int x, int y) {
        int value;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = grid[j][i];
            }
        }
        return value;
    }

    bool Board::checkBlockOutOfGrid(std::vector<threepp::Vector2> tiles) {
        for (threepp::Vector2 item : tiles) {
            int x = static_cast<int>(item.x);
            int y = static_cast<int>(item.y);
            if (grid[x][y] != 0) {
                return true;
            }
        }
        return false;
    }

    //Checks if row are filled with blocks (except boardwalls)
    bool Board::checkFullRow(int row) {
        for (int i = 1; i < boardWidth - 1; i++) {
            if (grid[row][i] == 0) {
                return false;
            }
        }
        return true;
    }
    //Deletes row (except boardwalls)
    void Board::deleteFullRow(int row) {
        for (int i = 1; i < boardWidth - 1; i++) {
            grid[row][i] = 0;
        }
    }
    //Copies all values from a row to row+movement down the grid. Sets original row to 0
    void Board::moveRowDown(int row, int movement) {
        for (int i = 1; i < boardWidth - 1; i++) {
            grid[row + movement][i] = grid[row][i];
            grid[row][i] = 0;
        }
    }
    //Checks, moves and deletes rows when they are full.
    void Board::rowCleanUp() {
        int amountOfFullRows = 0;
        for (int i = boardHeight - 2; i > 0; i--) {
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
        for (int i = boardHeight - 2; i > 0; i--) {
            if (checkFullRow(i) == true) {
                amount++;
            }
        }
        return amount;
    }
}// namespace tetris