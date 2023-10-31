
#ifndef TETRIS_RENDER_HPP
#define TETRIS_RENDER_HPP

#include "Input.hpp"
#include <threepp/threepp.hpp>

namespace tetris {

    class Render {
    public:
        std::shared_ptr<threepp::Mesh> createPlane(const threepp::Vector3& pos, const threepp::Color& color, float width, float height);
        std::shared_ptr<threepp::Mesh> createBox(const threepp::Vector3& pos, const threepp::Color& color);
        void initializeScene();
        void renderScene();
    };

}// namespace tetris

#endif//TETRIS_RENDER_HPP
