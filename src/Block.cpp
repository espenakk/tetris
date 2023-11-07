
#include "Block.hpp"
#include "Render.hpp"
namespace tetris {
    Block::Block() {
        cellSize = 0.9;
        rotationState = 0;
        //        colours = getCellColours();
    }

    std::shared_ptr<threepp::Group> Block::draw() {
        Render tetronimo(0.9, 0.9);
        std::shared_ptr<threepp::Group> blockGroup = threepp::Group::create();
        blockGroup->clear();
        std::vector<Position> tiles = cells[rotationState];
        for (Position item : tiles) {
            blockGroup->add(tetronimo.createBox({(float) (item.column) + 4, (float) (item.row) - 1, 0}, threepp::Color::crimson));
        }
        return blockGroup;
    }
}// namespace tetris