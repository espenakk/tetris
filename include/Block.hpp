
#ifndef TETRIS_BLOCK_HPP
#define TETRIS_BLOCK_HPP
#include <map>
#include <threepp/math/Vector2.hpp>
#include <vector>

namespace tetris {

    class Block {
    public:
        Block();

        std::map<int, std::vector<threepp::Vector2>> cells;
        void move(float x, float y);
        void rotate(int rot);
        std::vector<threepp::Vector2> peak(float x, float y, int rot);
        std::vector<threepp::Vector2> blockPositions();

        float xOffset;
        float yOffset;
        int type;

    private:
        int rotationState;
        std::vector<threepp::Vector2> blockPositions(float x, float y, int rot);
    };

}// namespace tetris

#endif//TETRIS_BLOCK_HPP
