
#ifndef TETRIS_GAME_HPP
#define TETRIS_GAME_HPP
#include "Board.hpp"
#include "Input.hpp"
#include "Random.hpp"
#include "Tetrominos.hpp"

#include <threepp/core/Clock.hpp>

#include "threepp/renderers/TextRenderer.hpp"
#include <sstream>
#include <utility>

namespace tetris {

    class Game {
    public:
        Game();
        Board board;
        Block block;
        Random random;
        Input input;
        threepp::Clock clock;
        std::vector<Block> tetrominos;
        Block currentBlock;
        Block nextBlock;

        void runTetris();

        int tetrisScore;
        bool renderGame;
        bool renderTetromino;

        void updateScore(int check);
        bool isGameOver();

        void onScoreUpdate(std::function<void(int)> callback) {
            scoreUpdateCallback = std::move(callback);
        }

        void onBordChanged(std::function<void()> callback) {
            boardChangedCallback = std::move(callback);
        }

        void onGameOver(std::function<void()> callback) {
            gameOverCallback = std::move(callback);
        }

        void onContinue(std::function<void()> callback) {
            gameContinueCallback = std::move(callback);
        }

    private:
        Movement currentMovement;
        float elapsedTime = clock.getElapsedTime();
        float lastTick = elapsedTime;

        std::function<void(int)> scoreUpdateCallback;
        std::function<void()> boardChangedCallback;
        std::function<void()> gameOverCallback;
        std::function<void()> gameContinueCallback;

        void spawnBlock();
        bool movementAllowed();
        void updateMovement();

        int currentType;
        int nextType;
        int moveRequestX;
        int moveRequestY;
        int rotateRequest;

        bool gameOver;
        bool drop = false;
        void tickDown();
        void inputHandling();
        void update();
    };

}// namespace tetris

#endif//TETRIS_GAME_HPP
