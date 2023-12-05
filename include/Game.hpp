
#ifndef TETRIS_GAME_HPP
#define TETRIS_GAME_HPP
#include "Block.hpp"
#include "Board.hpp"
#include "Random.hpp"
#include <sstream>

namespace tetris {

    class Game {
    public:
        Game();
        /*Board board;
        Block block;
        Random random;
        void draw();*/

        int updateScore(int score, int check);

        std::stringstream makeText(std::string text);
        std::shared_ptr<threepp::TextHandle> textConfig(std::stringstream text, threepp::TextHandle handle);


    private:
        /*std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;*/
    };

}// namespace tetris

#endif//TETRIS_GAME_HPP
