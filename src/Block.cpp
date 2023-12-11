
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

    void Block::rotate(int rot) {
        for (int i = 0; i < rot; i++) {
            rotationState += 1;
            if (tiles[rotationState].empty()) {
                rotationState = 0;
            }
        }
    }

    std::vector<threepp::Vector2> Block::blockPositions(float x, float y, int rot) {
        std::vector<threepp::Vector2> currentTiles = tiles[rot];
        std::vector<threepp::Vector2> movedTiles;
        for (auto item : currentTiles) {
            threepp::Vector2 newPosition = threepp::Vector2(item.x + x, item.y + y);
            movedTiles.emplace_back(newPosition);
        }
        return movedTiles;
    }

    std::vector<threepp::Vector2> Block::blockPositions() {
        return blockPositions(xOffset, yOffset, rotationState);
    }

    std::vector<threepp::Vector2> Block::peak(float x, float y, int rot) {
        int rotation = (rotationState + rot) % tiles.size();
        return blockPositions(xOffset + x, yOffset + y, rotation);
    }

}// namespace tetris