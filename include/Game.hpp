
#ifndef TETRIS_GAME_HPP
#define TETRIS_GAME_HPP
#include "Board.hpp"
#include "Input.hpp"
#include "Random.hpp"
#include "Tetrominos.hpp"

#include <threepp/core/Clock.hpp>

#include "threepp/renderers/TextRenderer.hpp"
#include <sstream>

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

        int updateScore(int score, int check);
        bool isGameOver();

    private:
        Movement currentMovement;
        float elapsedTime = clock.getElapsedTime();
        float lastTick = elapsedTime;

        void moveBlock();
        bool movementAllowed();
        void updateMovement();

        int currentType;
        int nextType;
        int movedTilesX;
        int movedTilesY;
        int rotate;

        bool gameOver;
        bool drop = false;
        void tickDown();
        void inputHandling();
        void update();
    };

}// namespace tetris

#endif//TETRIS_GAME_HPP
