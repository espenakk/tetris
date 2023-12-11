
#include "Input.hpp"

namespace tetris {
    Input::Input(float& time): time(time) {}

    void Input::inputProcessing(threepp::KeyEvent evt) {
        if (evt.key == threepp::Key::A || evt.key == threepp::Key::LEFT) {
            movement = LEFT;
        } else if (evt.key == threepp::Key::D || evt.key == threepp::Key::RIGHT) {
            movement = RIGHT;
        } else if (evt.key == threepp::Key::W || evt.key == threepp::Key::UP) {
            movement = ROTATE;
        } else if (evt.key == threepp::Key::S || evt.key == threepp::Key::DOWN) {
            movement = DOWN;
        } else if (evt.key == threepp::Key::SPACE) {
            movement = DROP;
        }
    }
    void Input::onKeyPressed(threepp::KeyEvent evt) {
        inputProcessing(evt);
    }
    void Input::onKeyRepeat(threepp::KeyEvent evt) {
        inputProcessing(evt);
    }
}// namespace tetris