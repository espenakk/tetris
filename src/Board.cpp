
#include "Board.hpp"

namespace tetris {

    Board::Board(int height, int width) {
        boardHeight = height;
        boardWidth = width;
        spawnOffset = 4;

        for (int i = 0; i < boardHeight; i++) {
            std::vector<TileType>& vector_line = grid.emplace_back();
            for (int j = 0; j < boardWidth; j++) {
                TileType tileType = i < spawnOffset ? SpawnZone : EmptyTile;
                vector_line.push_back(tileType);
            }
        }
    }

    void Board::reset() {
        for (int i = 0; i < boardHeight; i++) {
            for (int j = 0; j < boardWidth; j++) {
                TileType tileType = i < spawnOffset ? SpawnZone : EmptyTile;
                setGridTileType(j, i, tileType);
            }
        }
    }

    void Board::saveBlock(const std::vector<threepp::Vector2>& tiles, TileType tileType) {
        for (auto tile : tiles) {
            setGridTileType((int) tile.x, (int) tile.y, tileType);
        }
    }

    int Board::getGridTileType(int x, int y) {
        return grid.at(y).at(x);
    }

    void Board::setGridTileType(int x, int y, TileType tileType) {
        grid.at(y).at(x) = tileType;
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
        auto tile = getGridTileType(x, y);
        return tile != EmptyTile && tile != SpawnZone;
    }


    bool Board::completedLine(int line) {
        for (int i = 0; i < boardWidth; i++) {
            if (!hasBlock(i, line)) {
                return false;
            }
        }
        return true;
    }

    void Board::clearCompletedLine(int line) {
        for (int i = 0; i < boardWidth; i++) {
            setGridTileType(i, line, EmptyTile);
        }
    }

    void Board::moveLineDown(int line, int lines) {
        for (int i = 0; i < boardWidth; i++) {
            setGridTileType(i, line + lines, (TileType) getGridTileType(i, line));
            setGridTileType(i, line, EmptyTile);
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