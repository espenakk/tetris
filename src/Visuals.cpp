
#include "Visuals.hpp"
#include <threepp/geometries/BoxGeometry.hpp>
#include <threepp/geometries/PlaneGeometry.hpp>
#include <threepp/geometries/TextGeometry.hpp>
#include <threepp/materials/MeshBasicMaterial.hpp>
#include <threepp/math/Color.hpp>
#include <threepp/renderers/TextRenderer.hpp>

namespace tetris {
    Visuals::Visuals() {
        colours = {threepp::Color::gray, threepp::Color::blueviolet, threepp::Color::limegreen, threepp::Color::red, threepp::Color::darkorange, threepp::Color::deepskyblue, threepp::Color::cyan, threepp::Color::yellow, threepp::Color::black};
    }
    std::shared_ptr<threepp::Mesh> Visuals::createPlane(const threepp::Vector3& pos, const threepp::Color& color) {//Adjusted the function from threepp example
        auto geometry = threepp::PlaneGeometry::create(width_, height_);
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);
        return mesh;
    }
    std::shared_ptr<threepp::Mesh> Visuals::createBox(const threepp::Vector3& pos, const threepp::Color& color) {//Adjusted the function from threepp example
        auto geometry = threepp::BoxGeometry::create(width_, height_);
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);
        return mesh;
    }

    std::shared_ptr<threepp::Group> Visuals::renderBoard(tetris::Board gameBoard) {
        std::shared_ptr<threepp::Group> group;
        group = threepp::Group::create();
        for (int i = 0; i < gameBoard.boardHeight; i++) {
            for (int j = 0; j < gameBoard.boardWidth; j++) {
                auto value = gameBoard.getGridValue(j, i);
                group->add(createBox({(float) j, (float) i, 0}, colours[value]));
            }
        }
        return group;
    }

    std::shared_ptr<threepp::Group> Visuals::renderTetromino(tetris::Block block) {
        std::shared_ptr<threepp::Group> group;
        group = threepp::Group::create();
        for (const threepp::Vector2& pos : block.blockPositions()) {
            group->add(createBox({pos.x, pos.y, 0}, colours[block.type]));
        }
        return group;
    }

    std::shared_ptr<threepp::Group> Visuals::renderNextTetromino(tetris::Block block) {
        auto group = renderTetromino(block);
        group->translateX(-8.0f);
        group->translateY(8.0f);
        return group;
    }
}// namespace tetris