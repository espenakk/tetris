
#ifndef TETRIS_GAME_HPP
#define TETRIS_GAME_HPP
#include "Board.hpp"
#include "Random.hpp"
#include "Tetrominos.hpp"

#include "threepp/renderers/TextRenderer.hpp"
#include <sstream>

namespace tetris {

    class Game {
    public:
        Game();
        Board board;
        Block block;
        Random random;
        std::vector<Block> tetrominos;
        Block currentBlock;
        Block nextBlock;
        void inputHandling(int movement);
        void update();
        int currentType;
        int nextType;
        int movedRows = 0;
        int movedColumns = 0;

        bool drop = false;
        bool tickDown = false;
        bool gameOver = false;
        bool rotate = false;
        bool renderGame = true;
        bool renderBlock = false;
        bool renderBoard = false;


        int updateScore(int score, int check);

        std::stringstream makeText(std::string text);
        std::shared_ptr<threepp::TextHandle> textConfig(std::stringstream text, threepp::TextHandle handle);

    private:
        bool movementAllowed();
        void moveBlock();
    };

}// namespace tetris

#endif//TETRIS_GAME_HPP
