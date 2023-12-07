
#include "Visuals.hpp"
#include <threepp/geometries/BoxGeometry.hpp>
#include <threepp/geometries/PlaneGeometry.hpp>
#include <threepp/materials/MeshBasicMaterial.hpp>
#include <threepp/math/Color.hpp>


using namespace threepp;
namespace tetris {
    Visuals::Visuals() {
        colours = {threepp::Color::gray, threepp::Color::blueviolet, threepp::Color::limegreen, threepp::Color::red, threepp::Color::darkorange, threepp::Color::deepskyblue, threepp::Color::cyan, threepp::Color::yellow, threepp::Color::hotpink};
    };
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

    //    std::shared_ptr<threepp::Group> Board::drawGrid() {
    //        std::shared_ptr<threepp::Group> gridGroup = threepp::Group::create();
    //        Visuals renderGrid(0.9, 0.9);
    //        if (gridIsChanged == 1) {
    //            for (float i = 0; i < amountOfRows; i++) {
    //                for (float j = 0; j < amountOfColumns; j++) {
    //                    if (whatIsGridValue(i, j) == 0) {
    //                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::gray));
    //                    } else if (whatIsGridValue(i, j) == 8) {
    //                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::black));
    //                    } else if (whatIsGridValue(i, j) == 1) {
    //                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::blueviolet));
    //                    } else if (whatIsGridValue(i, j) == 2) {
    //                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::limegreen));
    //                    } else if (whatIsGridValue(i, j) == 3) {
    //                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::red));
    //                    } else if (whatIsGridValue(i, j) == 4) {
    //                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::darkorange));
    //                    } else if (whatIsGridValue(i, j) == 5) {
    //                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::deepskyblue));
    //                    } else if (whatIsGridValue(i, j) == 6) {
    //                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::cyan));
    //                    } else if (whatIsGridValue(i, j) == 7) {
    //                        gridGroup->add(renderGrid.createBox({j, i, 0}, threepp::Color::yellow));
    //                    }
    //                }
    //            }
    //        }
    //        gridIsChanged = 0;
    //        return gridGroup;
    //    }

    std::shared_ptr<threepp::Group> Visuals::renderBoard(const std::vector<std::pair<threepp::Vector2, int>>& gridSlots) {
        std::shared_ptr<threepp::Group> group;
        group = threepp::Group::create();
        group->clear();
        for (const auto& gridItem : gridSlots) {
            group->add(createBox({gridItem.first.x, gridItem.first.y, 0}, colours[gridItem.second]));
        }
        return group;
    }

    std::shared_ptr<threepp::Group> Visuals::renderTetromino(const std::vector<threepp::Vector2>& blockPositions, int type) {
        std::shared_ptr<threepp::Group> group;
        group = threepp::Group::create();
        group->clear();
        for (const threepp::Vector2& item : blockPositions) {
            group->add(createBox({item.y, item.x, 0}, colours[type]));
        }
        return group;
    }

}// namespace tetris