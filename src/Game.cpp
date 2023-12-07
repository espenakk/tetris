
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
    }
    void Game::inputHandling(int movement) {
        movedRows = 0;
        movedColumns = 0;
        if (drop || tickDown) {
            movedRows += 1;
            tickDown = false;
        } else {
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
    }
    void Game::update() {
        if (!board.isSlotOccupied(currentBlock.peak(movedRows, movedColumns, rotate))) {
            if (rotate) {
                currentBlock.rotate();
            }
            currentBlock.move(movedRows, movedColumns);
        } else {
            if (movedRows != 0) {
                board.saveBlock(currentBlock.blockPositions(), currentBlock.type);
                drop = false;

                currentBlock.xOffset = 4;
                currentBlock.yOffset = -1;
                currentType = nextType;
                nextType = random.getType();
                currentBlock = tetrominos[currentType];

                board.rowCleanUp();
                nextBlock = tetrominos[nextType];
                nextBlock.xOffset = -4;
                nextBlock.yOffset = 1;
                renderGame = true;
            }
        }
    }

}// namespace tetris