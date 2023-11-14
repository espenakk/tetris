
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
        std::vector<Position> peak(int row, int column, bool rotate);
        void rotate();
        std::vector<Position> blockPositions();

        int rowOffset;
        int columnOffset;

    private:
        int rotationState;
        std::vector<Position> blockPositions(int x, int y, int rot);
        std::vector<threepp::Color> colours;
    };

}// namespace tetris

#endif//TETRIS_BLOCK_HPP
