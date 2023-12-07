
#include "Block.hpp"

namespace tetris {
    Block::Block() {
        rotationState = 0;
        rowOffset = 0;
        columnOffset = 0;
    }

    void Block::move(int row, int column) {
        rowOffset += row;
        columnOffset += column;
    }
    void Block::rotate() {
        rotationState += 1;
        if (cells[rotationState].empty()) {
            rotationState = 0;
        }
    }
    std::vector<Position> Block::blockPositions(int x, int y, int rot) {
        std::vector<Position> tiles = cells[rot];
        std::vector<Position> movedTiles;
        for (Position item : tiles) {
            Position newPosition = Position(item.row + x, item.column + y);
            movedTiles.push_back(newPosition);
        }
        return movedTiles;
    };
    std::vector<Position> Block::blockPositions() {
        return blockPositions(rowOffset, columnOffset, rotationState);
    }
    std::vector<Position> Block::peak(int row, int column, bool rotate) {
        int rotation = (rotationState + rotate) % 4;
        return blockPositions(rowOffset + row, columnOffset + column, rotation);
    }
}// namespace tetris