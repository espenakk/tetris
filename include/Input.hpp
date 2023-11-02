
#ifndef TETRIS_INPUT_HPP
#define TETRIS_INPUT_HPP

#include <iostream>
#include <threepp/extras/imgui/ImguiContext.hpp>
#include <threepp/threepp.hpp>

namespace tetris {
    enum move {
        LEFT,
        RIGHT,
        ROTATE,
        DOWN,
        DROP,
        NONE
    };
    class Input: public threepp::KeyListener {
    public:
        float& t;
        explicit Input(float& t): t(t) {}

        int newMovement = NONE;
        int previousMovement = NONE;
        void onKeyPressed(threepp::KeyEvent evt) override;

        void onKeyRepeat(threepp::KeyEvent evt) override;
    };
}// namespace tetris

#endif//TETRIS_INPUT_HPP
