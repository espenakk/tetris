
#include "Board.hpp"

namespace tetris {

    Board::Board(int height, int width) {
        boardHeight = height;
        boardWidth = width;
        spawnOffset = 4;

        for (int i = 0; i < boardHeight; i++) {
            std::vector<int>& vector_row = grid.emplace_back();
            for (int j = 0; j < boardWidth; j++) {
                int tilevalue = i < spawnOffset ? SpawnZone : EmptyTile;
                vector_row.push_back(tilevalue);
            }
        }
    }

    void Board::saveBlock(std::vector<threepp::Vector2> tiles, int type) {
        for (auto tile : tiles) {
            setGridValue(tile.x, tile.y, type);
        }
    }

    int Board::getGridValue(int x, int y) {
        return grid.at(y).at(x);
    }

    void Board::setGridValue(int x, int y, int value) {
        grid.at(y).at(x) = value;
    }

    bool Board::blockHasInvalidPosition(std::vector<threepp::Vector2> tiles) {
        for (auto item : tiles) {
            if (item.x > boardWidth - 1 || item.x < EmptyTile) {
                return true;
            }
            if (item.y > boardHeight - 1) {
                return true;
            }
            if (hasBlock(item.x, item.y)) {
                return true;
            }
        }
        return false;
    }

    bool Board::hasBlock(int x, int y) {
        auto tile = getGridValue(x, y);
        return tile != EmptyTile && tile != SpawnZone;
    }

    //Checks if row are filled with blocks
    bool Board::completedLine(int y) {
        for (int i = 0; i < boardWidth; i++) {
            if (!hasBlock(i, y)) {
                return false;
            }
        }
        return true;
    }
    //Deletes row
    void Board::clearCompletedLine(int y) {
        for (int i = 0; i < boardWidth; i++) {
            setGridValue(i, y, EmptyTile);
        }
    }
    //Copies all values from a row to row+lines down the grid. Sets original row to 0
    void Board::moveLineDown(int y, int lines) {
        for (int i = 0; i < boardWidth; i++) {
            setGridValue(i, y + lines, getGridValue(i, y));
            setGridValue(i, y, EmptyTile);
        }
    }
    //Checks, moves and deletes rows when they are full.
    void Board::rowCleanUp() {
        int completedLines = 0;
        for (int i = boardHeight - 1; i > spawnOffset - 1; i--) {
            if (completedLine(i)) {
                completedLines++;
                clearCompletedLine(i);
            } else if (completedLines > 0) {
                moveLineDown(i, completedLines);
            }
        }
    }
    //Checks how many rows are full and returns amount
    int Board::countCompleteLines() {
        int amount = 0;
        for (int i = boardHeight - 1; i > spawnOffset - 1; i--) {
            if (completedLine(i)) {
                amount++;
            }
        }
        return amount;
    }

    bool Board::checkGameOver(std::vector<threepp::Vector2> tiles) {
        for (auto item : tiles) {
            if (item.x < boardWidth - 1 && item.x > 0 && item.y < spawnOffset + 1 && (hasBlock(item.x, item.y))) {
                return true;
            }
        }
        return false;
    }
}// namespace tetris