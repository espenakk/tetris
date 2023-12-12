
#ifndef TETRIS_GAME_HPP
#define TETRIS_GAME_HPP

#include "Board.hpp"
#include "Input.hpp"
#include "Random.hpp"
#include "Tetrominos.hpp"

#include <sstream>
#include <threepp/core/Clock.hpp>
#include <threepp/renderers/TextRenderer.hpp>
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

        void update();
        int tetrisScore;
        void updateScore(int linesCleared);
        bool isGameOver();

        void onScoreUpdate(std::function<void(int)> callback) {
            scoreUpdateCallback = std::move(callback);
        }

        void onBlockmoved(std::function<void()> callback) {
            blockMovedCallback = std::move(callback);
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
        int currentType;
        int nextType;
        int moveRequestX;
        int moveRequestY;
        int rotateRequest;
        bool gameOver;
        bool drop = false;
        void inputHandling();
        void spawnBlock();
        bool movementAllowed();
        std::function<void(int)> scoreUpdateCallback;
        std::function<void()> boardChangedCallback;
        std::function<void()> blockMovedCallback;
        std::function<void()> gameOverCallback;
        std::function<void()> gameContinueCallback;
    };

}// namespace tetris

#endif//TETRIS_GAME_HPP
