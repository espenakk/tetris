
#include "Game.hpp"
#include "Input.hpp"

namespace tetris {
    Game::Game(): board(24, 10) {
        block = Block();
        random = Random();
        tetrominos = {T_Tetromino(), S_Tetromino(), Z_Tetromino(), L_Tetromino(), J_Tetromino(), I_Tetromino(), O_Tetromino()};
        currentType = random.getType();
        nextType = random.getType();
        currentBlock = tetrominos[currentType];
        nextBlock = tetrominos[nextType];
        gameOver = false;
        rotate = 0;
        movedTilesX = 0;
        movedTilesY = 0;
    }

    void Game::inputHandling(int movement) {
            switch (movement) {
                case LEFT:
                    movedTilesX += 1;
                    break;
                case RIGHT:
                    movedTilesX -= 1;
                    break;
                case DOWN:
                    movedTilesY += 1;
                    break;
                case ROTATE:
                    rotate += 1;
                    break;
                case DROP:
                    drop = true;
                    break;
            }
        }

    void Game::moveBlock() {
        if (!gameOver && movementAllowed()) {
            currentBlock.move(movedTilesX, movedTilesY);
            currentBlock.rotate(rotate);
        }
    }

    bool Game::movementAllowed() {
        if (!board.checkBlockOutOfGrid(currentBlock.peak(movedTilesX, movedTilesY, rotate))) {
            return true;
        } else {
            return false;
        }
    }

    void Game::update() {
        board.saveBlock(currentBlock.blockPositions(), currentBlock.type);
        drop = false;
        //        currentBlock.xOffset = 5;
        //        currentBlock.yOffset = 4;
        currentType = nextType;
        nextType = random.getType();
        currentBlock = tetrominos[currentType];
        board.rowCleanUp();
        nextBlock = tetrominos[nextType];
    }

    //Adds points to "score" according to amount of rows filled in "check"
    int Game::updateScore(int score, int check) {
        if (check == 1) {
            score = score + 40;
        } else if (check == 2) {
            score = score + 100;
        } else if (check == 3) {
            score = score + 300;
        } else if (check == 4) {
            score = score + 1200;
        }
        return score;
    }
    //Converts a string into stringstream
    std::stringstream Game::makeText(std::string text) {
        std::stringstream stream;
        stream << text;
        return stream;
    }

}// namespace tetris