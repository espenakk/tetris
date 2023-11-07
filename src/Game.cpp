#include "Game.hpp"
#include "Random.hpp"
#include "Tetronimos.cpp"

namespace tetris {
    Game::Game() {
        board = Board();
        block = Block();
        random = Random();
        blocks = {T_Tetronimo(), S_Tetronimo(), Z_Tetronimo(), L_Tetronimo(), J_Tetronimo(), I_Tetronimo(), O_Tetronimo()};
        currentBlock = blocks[random.getType()];
        nextBlock = blocks[random.getType()];
    }
    void Game::draw() {
        std::shared_ptr<threepp::Group> grid = board.drawGrid();
        std::shared_ptr<threepp::Group> blockGroup = currentBlock.draw();
    }
}// namespace tetris