#include "Block.hpp"
#include "Board.hpp"
#include "Tetrominos.cpp"
#include <threepp/threepp.hpp>
using namespace threepp;
using namespace tetris;

int main() {
    Canvas canvas("Tetris");
    WindowSize tetrisSize{1200, 1200};
    canvas.setSize(tetrisSize);
    GLRenderer glr(glrSize);
    glr.setClearColor(Color::blueviolet);
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

    canvas.animate([&] {
        glr.render(*scene, *camera);
        glr.resetState();
        float dt = clock.getDelta();

        input.previousMovement = input.newMovement;
        input.newMovement = NONE;

        switch (input.previousMovement) {
            case LEFT:
                blockGroup->clear();
                block.move(0, 1);
                blockGroup = block.draw();
                scene->add(blockGroup);
                break;
            case RIGHT:
                blockGroup->clear();
                block.move(0, -1);
                blockGroup = block.draw();
                scene->add(blockGroup);
                break;
            case DOWN:
                blockGroup->clear();
                block.move(1, 0);
                blockGroup = block.draw();
                scene->add(blockGroup);
                break;
            case ROTATE:
                blockGroup->clear();
                block.rotate();
                blockGroup = block.draw();
                scene->add(blockGroup);
                break;
            case DROP:
                blockGroup->clear();
                block.move(5, 0);
                blockGroup = block.draw();
                scene->add(blockGroup);
                break;
        }
    });
    return 0;
}