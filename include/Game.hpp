
#ifndef TETRIS_GAME_HPP
#define TETRIS_GAME_HPP
#include "Board.hpp"
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
        threepp::Clock clock;
        std::vector<Block> tetrominos;
        Block currentBlock;
        Block nextBlock;
        void inputHandling(int movement);
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
        void tickDown(int movement);


    private:
        float lastTick = clock.getElapsedTime();
    };

}// namespace tetris

#endif//TETRIS_GAME_HPP
