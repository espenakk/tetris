
#include "Game.hpp"

namespace tetris {
    Game::Game(): board(24, 10), clock(), input(elapsedTime) {
        block = Block();
        random = Random();
        tetrominos = {T_Tetromino(), S_Tetromino(), Z_Tetromino(), L_Tetromino(), J_Tetromino(), I_Tetromino(), O_Tetromino()};
        currentType = random.getType();
        nextType = random.getType();
        currentBlock = tetrominos[currentType];
        nextBlock = tetrominos[nextType];

        tetrisScore = 0;
        gameOver = false;
    }

    void Game::inputHandling() {
        moveRequestY = 0;
        moveRequestX = 0;
        rotateRequest = 0;
        currentMovement = input.movement;
        switch (currentMovement) {
            case LEFT:
                moveRequestX = 1;
                break;
            case RIGHT:
                moveRequestX = -1;
                break;
            case DOWN:
                moveRequestY = 1;
                break;
            case ROTATE:
                rotateRequest = 1;
                break;
            case DROP:
                drop = true;
                break;
            case NONE:
                break;
        }
        input.movement = NONE;
    }

    void Game::spawnBlock() {
        currentType = nextType;
        currentBlock = tetrominos[currentType];

        nextType = random.getType();
        nextBlock = tetrominos[nextType];
    }

    bool Game::movementAllowed() {
        if (!gameOver && !board.blockHasInvalidPosition(currentBlock.peak((float) moveRequestX, (float) moveRequestY, rotateRequest))) {
            return true;
        } else {
            return false;
        }
    }

    bool Game::isGameOver() {
        if (board.checkGameOver(currentBlock.peak((float) moveRequestX, (float) moveRequestY, rotateRequest))) {
            if (gameOverCallback)
                gameOverCallback();

            return true;
        }
        return false;
    }

    void Game::update() {
        inputHandling();

        if (!gameOver) {

            if (movementAllowed()) {
                currentBlock.move((float) moveRequestX, (float) 0.0f);
                currentBlock.rotate(rotateRequest);

                if (blockMovedCallback)
                    blockMovedCallback();
            }

            moveRequestX = 0;
            rotateRequest = 0;

            if (drop) {
                moveRequestY = 1;
            } else {
                if (clock.getElapsedTime() - lastTick > 0.3) {
                    moveRequestY = 1;
                    lastTick = clock.getElapsedTime();
                }
            }

            bool goingDown = moveRequestY == 1;
            bool killPiece = !gameOver && !movementAllowed() && goingDown;

            if (goingDown && movementAllowed()) {
                currentBlock.move((float) 0.0f, (float) moveRequestY);

                if (blockMovedCallback)
                    blockMovedCallback();
            }

            if (killPiece) {
                board.saveBlock(currentBlock.tilePositions(), currentBlock.type);
                updateScore(board.countCompleteLines());
                board.rowCleanUp();

                gameOver = isGameOver();

                if (!gameOver) {
                    spawnBlock();
                }

                if (boardChangedCallback)
                    boardChangedCallback();

                drop = false;
            }
        }

        if (gameOver && drop) {
            if (gameContinueCallback)
                gameContinueCallback();

            board.reset();
            spawnBlock();

            if (boardChangedCallback)
                boardChangedCallback();

            tetrisScore = 0;

            if (scoreUpdateCallback)
                scoreUpdateCallback(tetrisScore);

            drop = false;
            gameOver = false;
        }
    }

    void Game::updateScore(int linesCleared) {
        if (linesCleared == 0)
            return;

        int scoreIncrement = 0;
        switch (linesCleared) {
            case 1:
                scoreIncrement = 40;
                break;
            case 2:
                scoreIncrement = 100;
                break;
            case 3:
                scoreIncrement = 300;
                break;
            case 4:
                scoreIncrement = 1200;
                break;
        }
        tetrisScore += scoreIncrement;

        if (scoreUpdateCallback)
            scoreUpdateCallback(tetrisScore);
    }

}// namespace tetris