
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

    private:
        int cellSize;
        int rotationState;
        //        std::vector<Colour> colours;
    };

}// namespace tetris

#endif//TETRIS_BLOCK_HPP
