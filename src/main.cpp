#include <threepp/threepp.hpp>

#include "Blocks.hpp"
#include "Board.hpp"
#include "Render.hpp"

int main() {
    tetris::Blocks b;
    tetris::Render r;
    tetris::Board g;
    
    g.initGrid();
    g.saveBlock(2, 4, 4, 4);

    g.testwhatisgrid(0, 5);

    g.drawGrid();
    //g.printGrid();

    r.initializeScene();
    r.renderScene();
    return 0;
}