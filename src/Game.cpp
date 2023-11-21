#include "Game.hpp"
#include "Random.hpp"
#include "Tetrominos.cpp"

/*namespace tetris {
    Game::Game() {
        board = Board();
        block = Block();
        random = Random();
        blocks = {T_Tetromino(), S_Tetromino(), Z_Tetromino(), L_Tetromino(), J_Tetromino(), I_Tetromino(), O_Tetromino()};
        currentBlock = blocks[random.getType()];
        nextBlock = blocks[random.getType()];
    }
    void Game::draw() {
        std::shared_ptr<threepp::Group> grid = board.drawGrid();
        std::shared_ptr<threepp::Group> blockGroup = currentBlock.draw();
    }
}// namespace tetris */