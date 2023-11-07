#include "Block.hpp"
#include "Position.hpp"
namespace tetris {
    class T_Tetronimo: public Block {
    public:
        T_Tetronimo() {
            type = 0;
            cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[1] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
            cells[2] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[3] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
            move(-1, 4);
        }
    };
    class S_Tetronimo: public Block {
    public:
        S_Tetronimo() {
            type = 1;
            cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
            cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
            cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
            cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
            move(-1, 4);
        }
    };
    class Z_Tetronimo: public Block {
    public:
        Z_Tetronimo() {
            type = 2;
            cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
            cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
            move(-1, 4);
        }
    };
    class L_Tetronimo: public Block {
    public:
        L_Tetronimo() {
            type = 3;
            cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
            cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
            move(-1, 4);
        }
    };
    class J_Tetronimo: public Block {
    public:
        J_Tetronimo() {
            type = 4;
            cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
            cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
            move(-1, 4);
        }
    };
    class I_Tetronimo: public Block {
    public:
        I_Tetronimo() {
            type = 5;
            cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
            cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
            cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
            cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
            move(-1, 4);
        }
    };
    class O_Tetronimo: public Block {
    public:
        O_Tetronimo() {
            type = 6;
            cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
            move(-1, 5);
        }
    };
}// namespace tetris