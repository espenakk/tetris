
#ifndef TETRIS_BLOCK_HPP
#define TETRIS_BLOCK_HPP
#include "position.hpp"
#include <map>
#include <threepp/threepp.hpp>
#include <vector>
namespace tetris {

    class Block {
    public:
        Block();
        int type;
        std::map<int, std::vector<Position>> cells;
        std::shared_ptr<threepp::Group> draw();
        void move(int row, int column);
        void rotate();
        std::vector<Position> blockPositions();

    private:
        int rotationState;
        int rowOffset;
        int columnOffset;
    };

}// namespace tetris

#endif//TETRIS_BLOCK_HPP
