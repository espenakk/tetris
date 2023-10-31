
#include "Input.hpp"

namespace tetris {
    void Input::onKeyPressed(threepp::KeyEvent evt) {
        if (evt.key == threepp::Key::A || evt.key == threepp::Key::LEFT) {
            std::cout << "LEFT" << std::endl;
            //obj_.scale.z += 1 * dt_;
        } else if (evt.key == threepp::Key::D || evt.key == threepp::Key::RIGHT) {
            std::cout << "RIGHT" << std::endl;
        } else if (evt.key == threepp::Key::W || evt.key == threepp::Key::UP) {
            std::cout << "UP" << std::endl;
        } else if (evt.key == threepp::Key::S || evt.key == threepp::Key::DOWN) {
            std::cout << "DOWN" << std::endl;
        } else if (evt.key == threepp::Key::SPACE) {
            std::cout << "SPACE" << std::endl;
        }
    }
    void Input::onKeyRepeat(threepp::KeyEvent evt) {
        if (evt.key == threepp::Key::A || evt.key == threepp::Key::LEFT) {
            std::cout << "LEFT" << std::endl;
            //obj_.scale.z += 1 * dt_;
        } else if (evt.key == threepp::Key::D || evt.key == threepp::Key::RIGHT) {
            std::cout << "RIGHT" << std::endl;
        } else if (evt.key == threepp::Key::W || evt.key == threepp::Key::UP) {
            std::cout << "UP" << std::endl;
        } else if (evt.key == threepp::Key::S || evt.key == threepp::Key::DOWN) {
            std::cout << "DOWN" << std::endl;
        } else if (evt.key == threepp::Key::SPACE) {
            std::cout << "SPACE" << std::endl;
        }
    }
}// namespace tetris