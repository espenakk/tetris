
#include "Game.hpp"
#include "Input.hpp"
#include "Visuals.hpp"
#include <threepp/cameras/OrthographicCamera.hpp>
#include <threepp/canvas/Canvas.hpp>
#include <threepp/core/Clock.hpp>
#include <threepp/renderers/GLRenderer.hpp>
#include <threepp/scenes/Scene.hpp>

using namespace threepp;
using namespace tetris;

int main() {
    Canvas canvas("Tetris");
    WindowSize canvasSize{650, 800};
    WindowSize renderingSize{800, 800};
    canvas.setSize(canvasSize);
    GLRenderer renderingEngine(renderingSize);
    renderingEngine.setClearColor(Color::black);
    auto scene = Scene::create();
    auto camera = OrthographicCamera::create();
    camera->position.z = 1;//5
    camera->position.x = 1.5;
    camera->position.y = 15;//10
    camera->rotateZ(3.1415);
    camera->zoom = 0.06;//0.09
    camera->updateProjectionMatrix();

    Game game = Game();
    Visuals visuals = Visuals();
    Clock clock = Clock();
    Input input{clock.elapsedTime};
    canvas.addKeyListener(&input);


    std::shared_ptr<Group> gridGroup = visuals.renderBoard(game.board.gridSlots);
    scene->add(gridGroup);
    std::shared_ptr<Group> blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
    scene->add(blockGroup);
    //    game.nextBlock.move(6, -5);
    //    std::shared_ptr<Group> nextBlockGroup = visuals.renderTetromino(game.tetrominos[game.nextType].blockPositions(), game.nextType);
    //    scene->add(nextBlockGroup);

    bool drop = false;

    float timeLastDown = clock.getElapsedTime();

    canvas.animate([&] {
        renderingEngine.render(*scene, *camera);
        renderingEngine.resetState();

        input.previousMovement = input.newMovement;
        input.newMovement = NONE;
        float vertical = 0;
        float horizontal = 0;
        bool rotate = false;
        switch (input.previousMovement) {
            case LEFT:
                horizontal = 1;
                break;
            case RIGHT:
                horizontal = -1;
                break;
            case DOWN:
                vertical = 1;
                break;
            case ROTATE:
                rotate = true;
                break;
            case DROP:
                drop = true;
                break;
        }

        game.currentBlock.move(vertical, horizontal);
        if (rotate) {
            game.currentBlock.rotate();
        }

        //        int row = 0;
        //        int column = 0;
        //        bool rotate = false;
        //        if (drop || (clock.getElapsedTime() - timeLastDown) > 0.3) {
        //            row = 1;
        //            game.inputHandling(input.previousMovement);
        //            if (clock.getElapsedTime() - timeLastDown > 0.3) {
        //                game.movedRows += 1;
        //                timeLastDown = clock.getElapsedTime();
        //            } else {
        //                switch (input.previousMovement) {
        //                    case LEFT:
        //                        column = 1;
        //                        break;
        //                    case RIGHT:
        //                        column = -1;
        //                        break;
        //                    case DOWN:
        //                        row = 1;
        //                        break;
        //                    case ROTATE:
        //                        rotate = true;
        //                        break;
        //                    case DROP:
        //                        drop = true;
        //                        break;
        //                }
        //            }
        //
        //            if (!game.board.isSlotOccupied(game.currentBlock.peak(row, column, rotate))) {
        //                blockGroup->clear();
        //                if (rotate) {
        //                    game.currentBlock.rotate();
        //                }
        //                game.currentBlock.move(row, column);
        //                blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
        //                scene->add(blockGroup);
        //            } else {
        //                if (row != 0) {
        //                    game.board.saveBlock(game.currentBlock.blockPositions(), game.currentBlock.type);
        //                    drop = false;
        //                    game.currentBlock.xOffset = -1;
        //                    game.currentBlock.yOffset = 4;
        //
        //                    blockGroup->clear();
        //                    game.currentType = game.nextType;
        //                    game.nextType = game.random.getType();
        //                    game.currentBlock = game.tetrominos[game.currentType];
        //                    blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
        //                    scene->add(blockGroup);
        //
        //                    game.board.rowCleanUp();
        //                    gridGroup->clear();
        //                    gridGroup = visuals.renderBoard(game.board.gridSlots);
        //                    scene->add(gridGroup);
        //
        //                    nextBlockGroup->clear();
        //                    game.nextBlock = game.tetrominos[game.nextType];
        //                    game.nextBlock.xOffset = 1;
        //                    game.nextBlock.yOffset = -4;
        //                    nextBlockGroup = visuals.renderTetromino(game.tetrominos[game.nextType].blockPositions(), game.nextType);
        //                    scene->add(nextBlockGroup);
        //                }
        //            }
        //        }
    });
    return 0;
}