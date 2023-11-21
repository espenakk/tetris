
#include "Tetrominos.hpp"
namespace tetris {
    T_Tetromino::T_Tetromino() {
        type = 0;
        cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[1] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        cells[2] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
        move(-1, 4);
    }
    S_Tetromino::S_Tetromino() {
        type = 1;
        cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
        cells[1] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
        move(-1, 4);
    }
    Z_Tetromino::Z_Tetromino() {
        type = 2;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
        move(-1, 4);
    }
    L_Tetromino::L_Tetromino() {
        type = 3;
        cells[0] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[1] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
        cells[2] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
        cells[3] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
        move(-1, 4);
    }
    J_Tetromino::J_Tetromino() {
        type = 4;
        cells[0] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 0)};
        cells[1] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[2] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        cells[3] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        move(-1, 4);
    }
    I_Tetromino::I_Tetromino() {
        type = 5;
        cells[0] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        cells[1] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
        move(-1, 4);
    }
    O_Tetromino::O_Tetromino() {
        type = 6;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
        move(-1, 5);
    }
}// namespace tetris
