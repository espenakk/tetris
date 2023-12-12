
#ifndef TETRIS_INPUT_HPP
#define TETRIS_INPUT_HPP

#include <threepp/input/KeyListener.hpp>

namespace tetris {

    enum Movement {
        LEFT,
        RIGHT,
        ROTATE,
        DOWN,
        DROP,
        NONE
    };

    class Input: public threepp::KeyListener {// Adjusted to our needs from threepp example
    public:
        float& time;
        explicit Input(float& time);
        Movement movement = NONE;

    private:
        void inputProcessing(threepp::KeyEvent evt);
        void onKeyPressed(threepp::KeyEvent evt) override;
        void onKeyRepeat(threepp::KeyEvent evt) override;
    };
}// namespace tetris

#endif//TETRIS_INPUT_HPP
