
#include "Board.hpp"

namespace tetris {

    Board::Board(int height, int width) {
        boardHeight = height;
        boardWidth = width;
        spawnOffset = 4;

        for (int i = 0; i < boardHeight; i++) {
            std::vector<int>& vector_row = grid.emplace_back();
            for (int j = 0; j < boardWidth; j++) {
                TileType tileType = i < spawnOffset ? SpawnZone : EmptyTile;
                vector_row.push_back(tileType);
            }
        }
    }

    void Board::saveBlock(const std::vector<threepp::Vector2>& tiles, int type) {
        for (auto tile : tiles) {
            setGridValue((int) tile.x, (int) tile.y, type);
        }
    }

    int Board::getGridValue(int x, int y) {
        return grid.at(y).at(x);
    }

    void Board::setGridValue(int x, int y, int value) {
        grid.at(y).at(x) = value;
    }

    bool Board::blockHasInvalidPosition(const std::vector<threepp::Vector2>& tiles) {
        for (auto item : tiles) {
            if (item.x > (float) boardWidth - 1 || item.x < EmptyTile) {
                return true;
            }
            if (item.y > (float) boardHeight - 1) {
                return true;
            }
            if (hasBlock((int) item.x, (int) item.y)) {
                return true;
            }
        }
        return false;
    }

    bool Board::hasBlock(int x, int y) {
        auto tile = getGridValue(x, y);
        return tile != EmptyTile && tile != SpawnZone;
    }


    bool Board::completedLine(int y) {
        for (int i = 0; i < boardWidth; i++) {
            if (!hasBlock(i, y)) {
                return false;
            }
        }
        return true;
    }

    void Board::clearCompletedLine(int y) {
        for (int i = 0; i < boardWidth; i++) {
            setGridValue(i, y, EmptyTile);
        }
    }

    void Board::moveLineDown(int y, int lines) {
        for (int i = 0; i < boardWidth; i++) {
            setGridValue(i, y + lines, getGridValue(i, y));
            setGridValue(i, y, EmptyTile);
        }
    }

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

    int Board::countCompleteLines() {
        int amount = 0;
        for (int i = boardHeight - 1; i > spawnOffset - 1; i--) {
            if (completedLine(i)) {
                amount++;
            }
        }
        return amount;
    }

    bool Board::checkGameOver(const std::vector<threepp::Vector2>& tiles) {
        for (auto item : tiles) {
            if (item.x < (float) boardWidth - 1 && item.x > 0 && item.y < (float) spawnOffset + 1 && (hasBlock((int) item.x, (int) item.y))) {
                return true;
            }
        }
        return false;
    }
}// namespace tetris