
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

//    Game game = Game();
//    Visuals visuals = Visuals();
//    Clock clock = Clock();
//    Input input{clock.elapsedTime};
//    canvas.addKeyListener(&input);
//
//
//    std::shared_ptr<Group> gridGroup = visuals.renderBoard(game.board.gridSlots);
//    scene->add(gridGroup);
//    std::shared_ptr<Group> blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
//    scene->add(blockGroup);
//    //    game.nextBlock.move(6, -5);
//    //    std::shared_ptr<Group> nextBlockGroup = visuals.renderTetromino(game.tetrominos[game.nextType].blockPositions(), game.nextType);
//    //    scene->add(nextBlockGroup);
//
//    bool drop = false;
//
//    float timeLastDown = clock.getElapsedTime();
//
//    canvas.animate([&] {
//        renderingEngine.render(*scene, *camera);
//        renderingEngine.resetState();
//
//        input.previousMovement = input.newMovement;
//        input.newMovement = NONE;
//        float vertical = 0;
//        float horizontal = 0;
//        bool rotate = false;
//        switch (input.previousMovement) {
//            case LEFT:
//                horizontal = 1;
//                break;
//            case RIGHT:
//                horizontal = -1;
//                break;
//            case DOWN:
//                vertical = 1;
//                break;
//            case ROTATE:
//                rotate = true;
//                break;
//            case DROP:
//                drop = true;
//                break;
//        }
//
//        game.currentBlock.move(vertical, horizontal);
//        if (rotate) {
//            game.currentBlock.rotate();
//        }
//
//        //        int row = 0;
//        //        int column = 0;
//        //        bool rotate = false;
//        //        if (drop || (clock.getElapsedTime() - timeLastDown) > 0.3) {
//        //            row = 1;
//        //            game.inputHandling(input.previousMovement);
//        //            if (clock.getElapsedTime() - timeLastDown > 0.3) {
//        //                game.movedRows += 1;
//        //                timeLastDown = clock.getElapsedTime();
//        //            } else {
//        //                switch (input.previousMovement) {
//        //                    case LEFT:
//        //                        column = 1;
//        //                        break;
//        //                    case RIGHT:
//        //                        column = -1;
//        //                        break;
//        //                    case DOWN:
//        //                        row = 1;
//        //                        break;
//        //                    case ROTATE:
//        //                        rotate = true;
//        //                        break;
//        //                    case DROP:
//        //                        drop = true;
//        //                        break;
//        //                }
//        //            }
//        //
//        //            if (!game.board.isSlotOccupied(game.currentBlock.peak(row, column, rotate))) {
//        //                blockGroup->clear();
//        //                if (rotate) {
//        //                    game.currentBlock.rotate();
//        //                }
//        //                game.currentBlock.move(row, column);
//        //                blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
//        //                scene->add(blockGroup);
//        //            } else {
//        //                if (row != 0) {
//        //                    game.board.saveBlock(game.currentBlock.blockPositions(), game.currentBlock.type);
//        //                    drop = false;
//        //                    game.currentBlock.xOffset = -1;
//        //                    game.currentBlock.yOffset = 4;
//        //
//        //                    blockGroup->clear();
//        //                    game.currentType = game.nextType;
//        //                    game.nextType = game.random.getType();
//        //                    game.currentBlock = game.tetrominos[game.currentType];
//        //                    blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
//        //                    scene->add(blockGroup);
//        //
//        //                    game.board.rowCleanUp();
//        //                    gridGroup->clear();
//        //                    gridGroup = visuals.renderBoard(game.board.gridSlots);
//        //                    scene->add(gridGroup);
//        //
//        //                    nextBlockGroup->clear();
//        //                    game.nextBlock = game.tetrominos[game.nextType];
//        //                    game.nextBlock.xOffset = 1;
//        //                    game.nextBlock.yOffset = -4;
//        //                    nextBlockGroup = visuals.renderTetromino(game.tetrominos[game.nextType].blockPositions(), game.nextType);
//        //                    scene->add(nextBlockGroup);
//        //                }
//        //            }
//        //        }
//    });

    Visuals visuals = Visuals();
    Board board = Board();
    Random random = Random();
    std::vector<Block> blocks = {T_Tetromino(), S_Tetromino(), Z_Tetromino(), L_Tetromino(), J_Tetromino(), I_Tetromino(), O_Tetromino()};
    int currentType = random.getType();
    int nextType = random.getType();
    Block currentBlock = blocks[currentType];
    Block nextBlock = blocks[nextType];
    std::shared_ptr<threepp::Group> gridGroup = visuals.renderBoard(board.gridSlots);
    scene->add(gridGroup);
    std::shared_ptr<threepp::Group> blockGroup = visuals.renderTetromino(currentBlock.blockPositions(), currentBlock.type);
    scene->add(blockGroup);
    nextBlock.xOffset = -4;
    nextBlock.yOffset = 1;
    std::shared_ptr<threepp::Group> nextBlockGroup = visuals.renderTetromino(nextBlock.blockPositions(), nextBlock.type);
    scene->add(nextBlockGroup);

    //SCORE
    int tetrisScore = 0;

    TextRenderer textRenderer;
    auto& handle = textRenderer.createHandle();
    auto& test = textRenderer.createHandle();

    Game testgame = Game();

    handle.setText(testgame.makeText("Score").str());
    handle.setPosition(500, 250);
    handle.scale = 2;
    test.setText(testgame.makeText(std::to_string(testgame.updateScore(tetrisScore, board.countRows()))).str());
    test.setPosition(500, 290);
    test.scale = 2;

    //SCORE

    Clock clock;
    Input input{clock.elapsedTime};
    canvas.addKeyListener(&input);

    bool drop = false;
    bool down = false;
    float timeLastDown = clock.getElapsedTime();

    canvas.animate([&] {
        renderingEngine.render(*scene, *camera);
        renderingEngine.resetState();

        input.previousMovement = input.newMovement;
        input.newMovement = NONE;

        int row = 0;
        int column = 0;
        bool rotate = false;
        if (drop || (clock.getElapsedTime() - timeLastDown) > 0.3) {
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

        textRenderer.render();

        if (board.isInsideGrid(currentBlock.peak(row, column, rotate)) && !board.isOccupied(currentBlock.peak(row, column, rotate))) {
            blockGroup->clear();
            if (rotate) {
                currentBlock.rotate();
            }
            currentBlock.move(row, column);
            blockGroup = visuals.renderTetromino(currentBlock.blockPositions(), currentBlock.type);
            scene->add(blockGroup);
        } else {
                board.saveBlock(currentBlock.blockPositions(), currentBlock.type);
                drop = false;
                currentBlock.xOffset = -1;
                currentBlock.yOffset = 4;

                blockGroup->clear();
                currentType = nextType;
                nextType = random.getType();
                currentBlock = blocks[currentType];
                blockGroup = visuals.renderTetromino(currentBlock.blockPositions(), currentBlock.type);
                scene->add(blockGroup);

                //SCORE
                tetrisScore = testgame.updateScore(tetrisScore, board.countRows());
                std::stringstream scoreText = testgame.makeText(std::to_string(tetrisScore));
                test.setText(scoreText.str());
                test.setPosition(500, 290);
                test.scale = 2;
                //SCORE

                board.rowCleanUp();

                // Check if the grid has been updated
                if (board.gridIsChanged) {
                gridGroup->clear();
                gridGroup = visuals.renderBoard(board.gridSlots);
                scene->add(gridGroup);
                board.gridIsChanged = false;// Reset the flag
                }

                nextBlockGroup->clear();
                nextBlock = blocks[nextType];
                nextBlock.xOffset = 1;
                nextBlock.yOffset = -4;
                nextBlockGroup = visuals.renderTetromino(blocks[nextType].blockPositions(), nextType);
                scene->add(nextBlockGroup);
            }
    });


    return 0;
}