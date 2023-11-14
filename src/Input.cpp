
#include "Input.hpp"

namespace tetris {
    Input::Input(float& t): t(t) {}

    void Input::inputHandling(threepp::KeyEvent evt) {
        if (evt.key == threepp::Key::A || evt.key == threepp::Key::LEFT) {
            newMovement = LEFT;
        } else if (evt.key == threepp::Key::D || evt.key == threepp::Key::RIGHT) {
            newMovement = RIGHT;
        } else if (evt.key == threepp::Key::W || evt.key == threepp::Key::UP) {
            newMovement = ROTATE;
        } else if (evt.key == threepp::Key::S || evt.key == threepp::Key::DOWN) {
            newMovement = DOWN;
        } else if (evt.key == threepp::Key::SPACE) {
            newMovement = DROP;
        }
    }
    void Input::onKeyPressed(threepp::KeyEvent evt) {
        inputHandling(evt);
    }
    void Input::onKeyRepeat(threepp::KeyEvent evt) {
        inputHandling(evt);
    }
}// namespace tetris