
#ifndef TETRIS_VISUALS_HPP
#define TETRIS_VISUALS_HPP

#include "Block.hpp"
#include "Board.hpp"
#include <array>
#include <threepp/math/Vector2.hpp>
#include <threepp/objects/Group.hpp>
#include <threepp/objects/mesh.hpp>
#include <vector>

namespace tetris {

    class Visuals {
    public:
        Visuals();
        std::shared_ptr<threepp::Mesh> createPlane(const threepp::Vector3& pos, const threepp::Color& color);//Adjusted the function from threepp example
        std::shared_ptr<threepp::Mesh> createBox(const threepp::Vector3& pos, const threepp::Color& color);  //Adjusted the function from threepp example
        std::shared_ptr<threepp::Group> renderBoard(tetris::Board gameBoard);
        std::shared_ptr<threepp::Group> renderTetromino(tetris::Block block);
        std::shared_ptr<threepp::Group> renderNextTetromino(tetris::Block block);

    private:
        float width_ = 0.9;
        float height_ = 0.9;
    };

}// namespace tetris

#endif//TETRIS_VISUALS_HPP
