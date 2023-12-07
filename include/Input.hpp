
#ifndef TETRIS_INPUT_HPP
#define TETRIS_INPUT_HPP
#include <threepp/input/KeyListener.hpp>

namespace tetris {
    enum moveInDirection {
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
        explicit Input(float& t);

        int newMovement = NONE;
        int previousMovement = NONE;
        void inputProcessing(threepp::KeyEvent evt);
        void onKeyPressed(threepp::KeyEvent evt) override;
        void onKeyRepeat(threepp::KeyEvent evt) override;
    };
}// namespace tetris

#endif//TETRIS_INPUT_HPP
