
#include "Game.hpp"
#include "Input.hpp"
#include "Visuals.hpp"
#include <iostream>
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
    WindowSize canvasSize{550, 780};
    WindowSize renderingSize{800, 800};
    canvas.setSize(canvasSize);
    GLRenderer renderingEngine(renderingSize);
    renderingEngine.setClearColor(Color::black);
    auto scene = Scene::create();
    auto camera = OrthographicCamera::create();
    camera->position.z = 1;
    camera->position.x = -2;
    camera->position.y = 11.5;
    camera->rotateZ(3.1415);
    camera->zoom = 0.08;
    camera->updateProjectionMatrix();


    Game game = Game();
    Visuals visuals = Visuals();
    std::shared_ptr<threepp::Group> gridGroup = visuals.renderBoard(game.board);
    scene->add(gridGroup);
    std::shared_ptr<threepp::Group> blockGroup = visuals.renderTetromino(game.currentBlock);
    scene->add(blockGroup);
    std::shared_ptr<threepp::Group> nextBlockGroup = visuals.renderNextTetromino(game.nextBlock);
    scene->add(nextBlockGroup);

    Clock clock;
    Input input{clock.elapsedTime};
    canvas.addKeyListener(&input);
    float timeLastDown = clock.getElapsedTime();


    //SCORE
    TextRenderer textRenderer;
    auto& nextb = textRenderer.createHandle();
    auto& score = textRenderer.createHandle();
    auto& value = textRenderer.createHandle();
    auto& end = textRenderer.createHandle();
    auto& endScore = textRenderer.createHandle();
    auto& endRestart = textRenderer.createHandle();
    auto& test = textRenderer.createHandle();

    nextb.setText("Next block");
    nextb.setPosition(370, 220);
    nextb.scale = 2;
    score.setText("Score");
    score.setPosition(400, 450);
    score.scale = 2;
    std::string scoreText = std::to_string(game.tetrisScore);
    value.setText(scoreText);
    value.setPosition(400, 500);
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
            game.movedTilesY += 1;
            timeLastDown = clock.getElapsedTime();
        } else {
            game.inputHandling(input.previousMovement);
        }

        if (game.movementAllowed()) {
            blockGroup->clear();
            game.moveBlock();
            blockGroup = visuals.renderTetromino(game.currentBlock);
            scene->add(blockGroup);
        } else {
            if (game.movedTilesY != 0) {

                blockGroup->clear();
                gridGroup->clear();
                nextBlockGroup->clear();
                game.update();
                blockGroup = visuals.renderTetromino(game.currentBlock);
                scene->add(blockGroup);
                gridGroup = visuals.renderBoard(game.board);
                scene->add(gridGroup);
                nextBlockGroup = visuals.renderNextTetromino(game.nextBlock);
                scene->add(nextBlockGroup);

                //SCORE
                std::string scoreText = std::to_string(game.tetrisScore);
                value.setText(scoreText);
                //SCORE

                if (game.isGameOver()) {
                    end.setText("Game Over");
                    end.setPosition(39, 350);
                    end.scale = 4;
                    endRestart.setText("Press SPACE to play again");
                    endRestart.setPosition(39, 420);
                    endRestart.scale = 1.5;
                }
            }
        }
    });
    return 0;
}