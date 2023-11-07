
#ifndef TETRIS_GAME_HPP
#define TETRIS_GAME_HPP
#include "Block.hpp"
#include "Board.hpp"
#include "Random.hpp"
namespace tetris {

    class Game {
    public:
        Game();
        Board board;
        Block block;
        Random random;
        void draw();

    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
    };

}// namespace tetris

#endif//TETRIS_GAME_HPP
