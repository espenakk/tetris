
#include "Game.hpp"
#include "Input.hpp"
#include "Visuals.hpp"
#include <threepp/cameras/OrthographicCamera.hpp>
#include <threepp/canvas/Canvas.hpp>
#include <threepp/core/Clock.hpp>
#include <threepp/renderers/GLRenderer.hpp>
#include <threepp/renderers/TextRenderer.hpp>
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
    camera->position.z = 5;
    camera->position.x = 1.5;
    camera->position.y = 10;
    camera->rotateZ(3.1415);
    camera->zoom = 0.09;
    camera->updateProjectionMatrix();


    Game game = Game();
    Visuals visuals = Visuals();
    std::shared_ptr<threepp::Group> gridGroup = visuals.renderBoard();
    scene->add(gridGroup);
    game.board.gridIsChanged = false;
    std::shared_ptr<threepp::Group> blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
    scene->add(blockGroup);
    game.nextBlock.yOffset = -4;
    game.nextBlock.xOffset = 3;
    std::shared_ptr<threepp::Group> nextBlockGroup = visuals.renderTetromino(game.nextBlock.blockPositions(), game.nextBlock.type);
    scene->add(nextBlockGroup);

    Clock clock;
    Input input{clock.elapsedTime};
    canvas.addKeyListener(&input);
    float timeLastDown = clock.getElapsedTime();


    //SCORE
    int tetrisScore = 0;
    TextRenderer textRenderer;
    auto& nextb = textRenderer.createHandle();
    auto& score = textRenderer.createHandle();
    auto& value = textRenderer.createHandle();
    auto& end = textRenderer.createHandle();
    auto& endScore = textRenderer.createHandle();
    auto& endRestart = textRenderer.createHandle();
    auto& endtest = textRenderer.createHandle();

    nextb.setText(game.makeText("Next block").str());
    nextb.setPosition(500, 70);
    nextb.scale = 2;
    score.setText(game.makeText("Score").str());
    score.setPosition(500, 350);
    score.scale = 2;
    value.setText(game.makeText(std::to_string(game.updateScore(tetrisScore, game.board.countRows()))).str());
    value.setPosition(500, 390);
    value.scale = 2;
    //SCORE

    bool drop = false;
    bool down = false;
    bool gameOver = false;

    canvas.animate([&] {
        renderingEngine.render(*scene, *camera);
        renderingEngine.resetState();
        textRenderer.render();

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
        if (!game.board.checkBlockOutOfGrid(game.currentBlock.peak(row, column, rotate)) & gameOver == false) {
            blockGroup->clear();
            if (rotate) {
                game.currentBlock.rotate();
            }
            game.currentBlock.move(row, column);
            blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
            scene->add(blockGroup);

        } else {
            if (row != 0 & gameOver == false) {
                game.board.saveBlock(game.currentBlock.blockPositions(), game.currentBlock.type);
                drop = false;
                game.currentBlock.xOffset = 5;
                game.currentBlock.yOffset = 4;

                blockGroup->clear();
                game.currentType = game.nextType;
                game.nextType = game.random.getType();
                game.currentBlock = game.tetrominos[game.currentType];
                blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
                scene->add(blockGroup);

                //SCORE
                tetrisScore = game.updateScore(tetrisScore, game.board.countRows());
                std::stringstream scoreText = game.makeText(std::to_string(tetrisScore));
                value.setText(scoreText.str());
                value.setPosition(500, 390);
                value.scale = 2;
                //SCORE

                game.board.rowCleanUp();
                gridGroup->clear();
                gridGroup = visuals.renderBoard();
                scene->add(gridGroup);
                game.board.gridIsChanged = false;

                nextBlockGroup->clear();
                game.nextBlock = game.tetrominos[game.nextType];
                game.nextBlock.xOffset = 3;
                game.nextBlock.yOffset = -4;
                nextBlockGroup = visuals.renderTetromino(game.nextBlock.blockPositions(), game.nextBlock.type);
                scene->add(nextBlockGroup);

                if (game.board.whatIsGridValue(0, 5) != 0) {
                    end.setText(game.makeText("Game Over").str());
                    end.setPosition(70, 300);
                    end.scale = 5;
                    endRestart.setText(game.makeText("Press SPACE to play again").str());
                    endRestart.setPosition(87, 450);
                    endRestart.scale = 1.5;

                    gameOver = true;
                }
            }
        }
        if (gameOver && input.previousMovement == DROP) {
            tetrisScore = 0;
            //Game::restartGame();

            end.setPosition(1000, 450);
            endRestart.setPosition(1000, 450);

            game.board.initGrid();
            gridGroup->clear();
            gridGroup = visuals.renderBoard();
            scene->add(gridGroup);
            game.board.gridIsChanged = false;

            drop = false;
            game.currentBlock.xOffset = -1;
            game.currentBlock.yOffset = 4;
            blockGroup->clear();
            game.currentType = game.nextType;
            game.nextType = game.random.getType();
            game.currentBlock = game.tetrominos[game.currentType];
            blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
            scene->add(blockGroup);

            nextBlockGroup->clear();
            game.nextBlock = game.tetrominos[game.nextType];
            game.nextBlock.xOffset = 3;
            game.nextBlock.yOffset = -4;
            nextBlockGroup = visuals.renderTetromino(game.nextBlock.blockPositions(), game.nextBlock.type);
            scene->add(nextBlockGroup);

            input.previousMovement = 0;
            gameOver = false;
        }
    });
    return 0;
}