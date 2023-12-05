#include "Game.hpp"
//#include "Random.hpp"
//#include "Tetrominos.cpp"


namespace tetris {
    Game::Game() {
        /*board = Board();
        block = Block();
        random = Random();
        blocks = {T_Tetromino(), S_Tetromino(), Z_Tetromino(), L_Tetromino(), J_Tetromino(), I_Tetromino(), O_Tetromino()};
        currentBlock = blocks[random.getType()];a
        nextBlock = blocks[random.getType()];*/
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