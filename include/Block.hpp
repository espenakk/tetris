
#ifndef TETRIS_BLOCK_HPP
#define TETRIS_BLOCK_HPP

#include <map>
#include <threepp/math/Vector2.hpp>
#include <vector>

namespace tetris {

    enum TileType {
        EmptyTile,
        SpawnZone,
        T,
        S,
        Z,
        L,
        J,
        I,
        O
    };

    class Block {
    public:
        Block();

        std::map<int, std::vector<threepp::Vector2>> tiles;
        void move(float x, float y);
        void rotate(int rot);
        std::vector<threepp::Vector2> peak(float x, float y, int rot);
        std::vector<threepp::Vector2> tilePositions();

        float xOffset;
        float yOffset;
        int rotationState;
        TileType type;

    private:
        std::vector<threepp::Vector2> tilePositions(float x, float y, int rot);
    };

}// namespace tetris

#endif//TETRIS_BLOCK_HPP
