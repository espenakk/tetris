
#include "Game.hpp"
#include "Input.hpp"
#include "Visuals.hpp"
#include <iostream>
#include <threepp/canvas/Canvas.hpp>
#include <threepp/renderers/TextRenderer.hpp>

using namespace threepp;
using namespace tetris;

int main() {
    Canvas canvas("Tetris");
    Game game = Game();
    Visuals visuals = Visuals();
    canvas.setSize(visuals.getCanvasSize());
    visuals.setupScene(game);


    Input input{game.clock.elapsedTime};
    canvas.addKeyListener(&input);


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
        visuals.render(game);
        textRenderer.render();

        input.previousMovement = input.newMovement;
        input.newMovement = NONE;

        game.tickDown(input.previousMovement);
        game.moveBlock();
        visuals.renderTetromino(game);
        game.update();
        visuals.renderGame(game);

        //SCORE
        std::string scoreText = std::to_string(game.tetrisScore);
        value.setText(scoreText);
        //SCORE

        //                if (game.isGameOver()) {
        //                    end.setText("Game Over");
        //                    end.setPosition(39, 350);
        //                    end.scale = 4;
        //                    endRestart.setText("Press SPACE to play again");
        //                    endRestart.setPosition(39, 420);
        //                    endRestart.scale = 1.5;
        //                }
    });
    return 0;
}