
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
    WindowSize canvasSize{650, 800};
    WindowSize renderingSize{800, 800};
    canvas.setSize(canvasSize);
    GLRenderer renderingEngine(renderingSize);
    renderingEngine.setClearColor(Color::black);
    auto scene = Scene::create();
    auto camera = OrthographicCamera::create();
    camera->position.z = 1;
    camera->position.x = -3;
    camera->position.y = 10;
    camera->rotateZ(3.1415);
    camera->zoom = 0.08;
    camera->updateProjectionMatrix();


    Game game = Game();
    Visuals visuals = Visuals();
    std::shared_ptr<threepp::Group> gridGroup = visuals.renderBoard(game.board);
    scene->add(gridGroup);
    game.board.gridIsChanged = false;
    std::shared_ptr<threepp::Group> blockGroup = visuals.renderTetromino(game.currentBlock);
    scene->add(blockGroup);
    std::shared_ptr<threepp::Group> nextBlockGroup = visuals.renderNextTetromino(game.nextBlock);
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
    nextb.setPosition(650 - 125, 170);

    Vector3 pos(10.0f, 3.0f, 0);
    pos.unproject(*camera);

    std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;

    nextb.scale = 1.5;
    score.setText(game.makeText("Score").str());
    score.setPosition(500, 350);
    score.scale = 1.5;
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
                tetrisScore = game.updateScore(tetrisScore, game.board.countRows());
                std::stringstream scoreText = game.makeText(std::to_string(tetrisScore));
                value.setText(scoreText.str());
                value.setPosition(500, 390);
                value.scale = 2;
                //SCORE

                if (game.board.getGridValue(0, 5) != 0) {
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