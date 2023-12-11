
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
        void inputHandling();
        void update();
        int currentType;
        int nextType;
        int movedTilesX;
        int movedTilesY;
        int rotate;

        bool drop = false;

        int tetrisScore;


        bool renderGame;
        bool renderTetromino;

        void moveBlock();
        bool movementAllowed();
        int updateScore(int score, int check);
        bool isGameOver();
        bool gameOver;
        void tickDown();

        void updateMovement() {
            movedTilesY = 0;
            movedTilesX = 0;
            rotate = 0;
            currentMovement = input.movement;
            input.movement = NONE;
        };

    private:
        Movement currentMovement;
        float elapsedTime = clock.getElapsedTime();
        float lastTick = elapsedTime;
    };

}// namespace tetris

#endif//TETRIS_GAME_HPP
