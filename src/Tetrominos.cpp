#include "Block.hpp"
#include "Position.hpp"
namespace tetris {
    class T_tetronimo: public Block {
    public:
        T_tetronimo() {
            type = 0;
            cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[1] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
            cells[2] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[3] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        }
    };
}// namespace tetris