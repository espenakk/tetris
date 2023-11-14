#include "Block.hpp"
#include "Board.hpp"
#include "Input.hpp"
#include "Tetrominos.cpp"
#include <threepp/threepp.hpp>
using namespace threepp;
using namespace tetris;

/* Funksjoner tilhørende collision, som skal i GAME
bool checkBlockOutOfGrid(){
    std::vector<Position> tiles = block.blockPositions();
    for(Position item : tiles){
        if(brd.checkOutOfGrid(item.row, item.column)){
            return true;
        }
    }
    return false;
}
*/

int main() {
    Canvas canvas("Tetris");
    WindowSize tetrisSize{760, 1200};
    WindowSize glrSize{1200, 1200};
    canvas.setSize(tetrisSize);
    GLRenderer glr(glrSize);
    glr.setClearColor(Color::limegreen);
    auto scene = Scene::create();
    auto camera = OrthographicCamera::create();
    camera->position.z = 5;
    camera->position.x = 1.5;
    camera->position.y = 10;
    camera->rotateZ(3.1415);
    camera->zoom = 0.09;
    camera->updateProjectionMatrix();

    Board brd = Board();
    std::shared_ptr<threepp::Group> grid = brd.drawGrid();
    scene->add(grid);

    T_Tetronimo block = T_Tetronimo();
    std::shared_ptr<threepp::Group> blockGroup = block.draw();
    scene->add(blockGroup);

    Clock clock;
    Input input{clock.elapsedTime};
    canvas.addKeyListener(&input);

    bool drop = false;
    bool down = false;
    float timeLastDown = clock.getElapsedTime();

    canvas.animate([&] {
        glr.render(*scene, *camera);
        glr.resetState();
        float dt = clock.getDelta();

        input.previousMovement = input.newMovement;
        input.newMovement = NONE;

        int row = 0;
        int column = 0;
        bool rotate = false;
        if (drop || (clock.getElapsedTime() - timeLastDown) > 0.5) {
            row = 1;
            timeLastDown = clock.getElapsedTime();
        } else {
            switch (input.previousMovement) {
                case LEFT:
                    column = 1;
                    break;
                case RIGHT:
                    column = -1;
                    break;
                case DOWN:
                    row = 1;
                    break;
                case ROTATE:
                    rotate = true;
                    break;
                case DROP:
                    drop = true;
                    break;
            }
        }

        if (!brd.checkBlockOutOfGrid(block.peak(row, column, rotate))) {
            blockGroup->clear();
            if (rotate) {
                block.rotate();
            }
            block.move(row, column);
            blockGroup = block.draw();
            scene->add(blockGroup);
        } else {
            if (row != 0) {
                brd.saveBlock(block.blockPositions());
                drop = false;

                block.rowOffset = -1;
                block.columnOffset = 4;
                blockGroup->clear();
                blockGroup = block.draw();
                scene->add(blockGroup);

                brd.rowCleanUp();
                grid->clear();
                grid = brd.drawGrid();
                scene->add(grid);
            }
        }
    });
    return 0;
}