
#include "Game.hpp"
#include "Visuals.hpp"
#include <threepp/canvas/Canvas.hpp>

using namespace threepp;
using namespace tetris;

int main() {
    Canvas canvas("Tetris");
    Game game = Game();
    Visuals visuals = Visuals();
    canvas.setSize(visuals.getCanvasSize());
    canvas.addKeyListener(&game.input);
    visuals.setupScene(game);

    canvas.animate([&] {
        game.update();
        visuals.render(game);
    });
    return 0;
}