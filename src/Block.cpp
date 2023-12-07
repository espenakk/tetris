
#include "Block.hpp"

namespace tetris {

    Block::Block() {
        rotationState = 0;
        xOffset = 0;
        yOffset = 0;
    }

    void Block::move(float x, float y) {
        xOffset += x;
        yOffset += y;
    }

    void Block::rotate() {
        rotationState += 1;
        if (cells[rotationState].empty()) {
            rotationState = 0;
        }
    }

    std::vector<threepp::Vector2> Block::blockPositions(float x, float y, int rot) {
        std::vector<threepp::Vector2> tiles = cells[rot];
        std::vector<threepp::Vector2> movedTiles;
        for (threepp::Vector2 item : tiles) {
            threepp::Vector2 newPosition = threepp::Vector2(item.x + x, item.y + y);
            movedTiles.push_back(newPosition);
        }
        return movedTiles;
    }

    std::vector<threepp::Vector2> Block::blockPositions() {
        return blockPositions(xOffset, yOffset, rotationState);
    }

    std::vector<threepp::Vector2> Block::peak(float x, float y, bool rotate) {
        int rotation = (rotationState + rotate) % 4;
        return blockPositions(xOffset + x, yOffset + y, rotation);
    }

}// namespace tetris