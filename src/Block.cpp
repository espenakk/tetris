
#include "Block.hpp"
#include "Input.hpp"
#include "Render.hpp"
namespace tetris {
    Block::Block() {
        rotationState = 0;
        rowOffset = 0;
        columnOffset = 0;
        colours = {threepp::Color::blueviolet, threepp::Color::limegreen, threepp::Color::red, threepp::Color::darkorange, threepp::Color::deepskyblue, threepp::Color::cyan, threepp::Color::yellow};
    }
    std::shared_ptr<threepp::Group> Block::draw() {
        Render render(0.9, 0.9);
        std::shared_ptr<threepp::Group> blockGroup = threepp::Group::create();
        blockGroup->clear();
        std::vector<Position> tiles = blockPositions();
        for (Position item : tiles) {
            blockGroup->add(render.createBox({(float) (item.column), (float) (item.row), 0}, colours[type]));
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
    };
}// namespace tetris