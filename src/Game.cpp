
#include "Game.hpp"
#include "Input.hpp"

namespace tetris {
    Game::Game() {
        board = Board();
        block = Block();
        random = Random();
        tetrominos = {T_Tetromino(), S_Tetromino(), Z_Tetromino(), L_Tetromino(), J_Tetromino(), I_Tetromino(), O_Tetromino()};
        currentType = random.getType();
        nextType = random.getType();
        currentBlock = tetrominos[currentType];
        nextBlock = tetrominos[nextType];
        rotate = false;
        movedRows = 0;
        movedColumns = 0;
    }

    void Game::inputHandling(int movement) {
            switch (movement) {
                case LEFT:
                    movedColumns += 1;
                    break;
                case RIGHT:
                    movedColumns -= 1;
                    break;
                case DOWN:
                    movedRows += 1;
                    break;
                case ROTATE:
                    rotate = true;
                    break;
                case DROP:
                    drop = true;
                    break;
            }
        }

        //    void Game::moveBlock(int movedRows, int movedColumns, bool rotate) {
        //            if (!gameOver && movementAllowed()) {
        //                if (rotate) {
        //                    currentBlock.rotate();
        //                }
        //                currentBlock.move(movedRows, movedColumns);
        //                renderBlock = true;
        //                rotate = false;
        //            }
        //    }

        //    bool Game::movementAllowed() {
        //            if (board.isInsideGrid(currentBlock.peak(movedRows, movedColumns, rotate)) && !board.isOccupied(currentBlock.peak(movedRows, movedColumns, rotate))) {
        //                return true;
        //            } else {
        //                return false;
        //            }
        //    }

        //    void Game::update() {
        //            if (!board.isInsideGrid(currentBlock.peak(movedRows, movedColumns, rotate))) {
        //                if (rotate) {
        //                currentBlock.rotate();
        //            }
        //            currentBlock.move(movedRows, movedColumns);
        //        } else {
        //            if (movedRows != 0) {
        //                board.saveBlock(currentBlock.blockPositions(), currentBlock.type);
        //                drop = false;
        //
        //                currentBlock.xOffset = 4;
        //                currentBlock.yOffset = -1;
        //                currentType = nextType;
        //                nextType = random.getType();
        //                currentBlock = tetrominos[currentType];
        //
        //                board.rowCleanUp();
        //                nextBlock = tetrominos[nextType];
        //                nextBlock.xOffset = -4;
        //                nextBlock.yOffset = 1;
        //                renderGame = true;
        //            }
        //        }
        //    }

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