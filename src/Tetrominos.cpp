
#include "Tetrominos.hpp"
namespace tetris {
    T_Tetromino::T_Tetromino() {
        type = T;
        tiles[0] = {threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(1, 2)};
        tiles[1] = {threepp::Vector2(1, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(1, 2)};
        tiles[2] = {threepp::Vector2(1, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1)};
        tiles[3] = {threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(1, 2)};
        move(3, 0);
    }
    S_Tetromino::S_Tetromino() {
        type = S;
        tiles[0] = {threepp::Vector2(1, 0), threepp::Vector2(2, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1)};
        tiles[1] = {threepp::Vector2(0, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(1, 2)};
        move(4, 0);
    }
    Z_Tetromino::Z_Tetromino() {
        type = Z;
        tiles[0] = {threepp::Vector2(0, 0), threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(2, 1)};
        tiles[1] = {threepp::Vector2(2, 0), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(1, 2)};
        move(3, 0);
    }
    L_Tetromino::L_Tetromino() {
        type = L;
        tiles[0] = {threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(1, 2), threepp::Vector2(2, 2)};
        tiles[1] = {threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(0, 2)};
        tiles[2] = {threepp::Vector2(0, 0), threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(1, 2)};
        tiles[3] = {threepp::Vector2(2, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1)};
        move(3, 0);
    }
    J_Tetromino::J_Tetromino() {
        type = J;
        tiles[0] = {threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(1, 2), threepp::Vector2(0, 2)};
        tiles[1] = {threepp::Vector2(0, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1)};
        tiles[2] = {threepp::Vector2(1, 0), threepp::Vector2(2, 0), threepp::Vector2(1, 1), threepp::Vector2(1, 2)};
        tiles[3] = {threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(2, 2)};
        move(4, 0);
    }
    I_Tetromino::I_Tetromino() {
        type = I;
        tiles[0] = {threepp::Vector2(1, 0), threepp::Vector2(1, 1), threepp::Vector2(1, 2), threepp::Vector2(1, 3)};
        tiles[1] = {threepp::Vector2(0, 1), threepp::Vector2(1, 1), threepp::Vector2(2, 1), threepp::Vector2(3, 1)};
        move(3, 0);
    }
    O_Tetromino::O_Tetromino() {
        type = O;
        tiles[0] = {threepp::Vector2(0, 0), threepp::Vector2(1, 0), threepp::Vector2(0, 1), threepp::Vector2(1, 1)};
        move(4, 0);
    }
}// namespace tetris
