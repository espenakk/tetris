
#include "Tetrominos.hpp"
namespace tetris {
    T_Tetromino::T_Tetromino() {
        type = 1;
        cells[0] = {threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(1, 2)};
        cells[1] = {threepp::Vector2(1, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(1, 2)};
        cells[2] = {threepp::Vector2(1, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1)};
        cells[3] = {threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(1, 2)};
        move(3, 0);
    }
    S_Tetromino::S_Tetromino() {
        type = 2;
        cells[0] = {threepp::Vector2(1, 0), threepp::Vector2(2, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1)};
        cells[1] = {threepp::Vector2(0, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(1, 2)};
        move(4, 0);
    }
    Z_Tetromino::Z_Tetromino() {
        type = 3;
        cells[0] = {threepp::Vector2(0, 0), threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(2, 1)};
        cells[1] = {threepp::Vector2(2, 0), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(1, 2)};
        move(3, 0);
    }
    L_Tetromino::L_Tetromino() {
        type = 4;
        cells[0] = {threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(1, 2), threepp::Vector2(2, 2)};
        cells[1] = {threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(0, 2)};
        cells[2] = {threepp::Vector2(0, 0), threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(1, 2)};
        cells[3] = {threepp::Vector2(2, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1)};
        move(3, 0);
    }
    J_Tetromino::J_Tetromino() {
        type = 5;
        cells[0] = {threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(1, 2), threepp::Vector2(0, 2)};
        cells[1] = {threepp::Vector2(0, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1)};
        cells[2] = {threepp::Vector2(1, 0), threepp::Vector2(2, 0), threepp::Vector2(1, 1), threepp::Vector2(1, 2)};
        cells[3] = {threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(2, 2)};
        move(4, 0);
    }
    I_Tetromino::I_Tetromino() {
        type = 6;
        cells[0] = {threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(1, 2), threepp::Vector2(1, 3)};
        cells[1] = {threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(3, 1)};
        move(3, 0);
    }
    O_Tetromino::O_Tetromino() {
        type = 7;
        cells[0] = {threepp::Vector2(0, 0), threepp::Vector2(1, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1)};
        move(4, 0);
    }
}// namespace tetris
