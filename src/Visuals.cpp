
#include "Visuals.hpp"
#include <threepp/geometries/BoxGeometry.hpp>
#include <threepp/geometries/PlaneGeometry.hpp>
#include <threepp/materials/MeshBasicMaterial.hpp>
#include <threepp/math/Color.hpp>

namespace tetris {
    Visuals::Visuals() {
        colours = {threepp::Color::gray, threepp::Color::blueviolet, threepp::Color::limegreen, threepp::Color::red, threepp::Color::darkorange, threepp::Color::deepskyblue, threepp::Color::cyan, threepp::Color::yellow, threepp::Color::hotpink};
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

    std::shared_ptr<threepp::Group> Visuals::renderBoard(/*std::array<std::array<int, 11>, 21> grid*/) {
        std::shared_ptr<threepp::Group> group;
        group = threepp::Group::create();
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++) {
                group->add(createBox({(float) j + 1, (float) i + 1, 0}, colours[0]));
            }
        }
        return group;
    }

    std::shared_ptr<threepp::Group> Visuals::renderTetromino(const std::vector<threepp::Vector2>& blockPositions, int type) {
        std::shared_ptr<threepp::Group> group;
        group = threepp::Group::create();
        for (const threepp::Vector2& block : blockPositions) {
            group->add(createBox({block.y, block.x, 0}, colours[type]));
        }
        return group;
    }

}// namespace tetris