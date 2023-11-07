
#include "Block.hpp"
#include "Blocks.hpp"
#include "Input.hpp"
#include "Render.hpp"
namespace tetris {
    Block::Block() {
        rotationState = 0;
        rowOffset = 0;
        columnOffset = 0;
    }
    std::shared_ptr<threepp::Group> Block::draw() {
        Render render(0.9, 0.9);
        std::shared_ptr<threepp::Group> blockGroup = threepp::Group::create();
        blockGroup->clear();
        std::vector<Position> tiles = blockPositions();
        for (Position item : tiles) {
            blockGroup->add(render.createBox({(float) (item.column), (float) (item.row), 0}, threepp::Color::crimson));
        }
        return blockGroup;
    }
    void Block::move(int row, int column) {
        rowOffset += row;
        columnOffset += column;
    }
    void Block::rotate() {
        rotationState += 1;
        if (rotationState == 4) {
            rotationState = 0;
        }
    }
    std::vector<Position> Block::blockPositions() {
        std::vector<Position> tiles = cells[rotationState];
        std::vector<Position> movedTiles;
        for (Position item : tiles) {
            Position newPosition = Position(item.row + rowOffset, item.column + columnOffset);
            movedTiles.push_back(newPosition);
        }
        return movedTiles;
    };
}// namespace tetris