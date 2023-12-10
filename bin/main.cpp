
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

    canvas.animate([&] {
        renderingEngine.render(*scene, *camera);
        renderingEngine.resetState();
        textRenderer.render();

        input.previousMovement = input.newMovement;
        input.newMovement = NONE;
        game.movedTilesX = 0;
        game.movedTilesY = 0;
        game.rotate = 0;

        if (game.drop || (clock.getElapsedTime() - timeLastDown) > 0.3) {
            game.movedTilesX += 1;
            timeLastDown = clock.getElapsedTime();
        } else {
            game.inputHandling(input.previousMovement);
        }
        if (game.movementAllowed()) {
            blockGroup->clear();
            game.moveBlock();
            blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
            scene->add(blockGroup);
        } else {
            if (game.movedTilesX != 0) {
                blockGroup->clear();
                gridGroup->clear();
                nextBlockGroup->clear();
                game.update();
                blockGroup = visuals.renderTetromino(game.currentBlock.blockPositions(), game.currentBlock.type);
                scene->add(blockGroup);
                gridGroup = visuals.renderBoard();
                scene->add(gridGroup);
                nextBlockGroup = visuals.renderTetromino(game.nextBlock.blockPositions(), game.nextBlock.type);
                scene->add(nextBlockGroup);

                //SCORE
                tetrisScore = game.updateScore(tetrisScore, game.board.countRows());
                std::stringstream scoreText = game.makeText(std::to_string(tetrisScore));
                value.setText(scoreText.str());
                value.setPosition(500, 390);
                value.scale = 2;
                //SCORE

                if (game.board.whatIsGridValue(0, 5) != 0) {
                    end.setText(game.makeText("Game Over").str());
                    end.setPosition(70, 300);
                    end.scale = 5;
                    endRestart.setText(game.makeText("Press SPACE to play again").str());
                    endRestart.setPosition(87, 450);
                    endRestart.scale = 1.5;
                }
            }
        }
    });
    return 0;
}