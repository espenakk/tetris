#include "Render.hpp"
#include "Board.hpp"
#include "Input.hpp"
namespace tetris {
    Render::Render(float width, float height): width_(width), height_(height){};
    std::shared_ptr<threepp::Mesh> Render::createPlane(const threepp::Vector3& pos, const threepp::Color& color) {//Adjusted the function from threepp example
        auto geometry = threepp::PlaneGeometry::create(width_, height_);
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);
        return mesh;
    }
    std::shared_ptr<threepp::Mesh> Render::createBox(const threepp::Vector3& pos, const threepp::Color& color) {//Adjusted the function from threepp example
        auto geometry = threepp::BoxGeometry::create(width_, height_);
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);
        return mesh;
    }
    /*void Render::initializeScene() {

        tetris::Board brd;
        tetris::Blocks blc;

        int rotation = 0;
        int type = 0;

        std::shared_ptr<threepp::Group> group = threepp::Group::create();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (blc.getTetronimo(type, rotation, i, j)) {
                    group->add(createBox({(float) (j) + 4, (float) (i), 0}, threepp::Color::crimson));
                }
            }
        }
        scene->add(group);


            //            if (kl.newMovement == LEFT) {
            //                blc.moveBlock(LEFT);
            //            } else if (kl.newMovement == RIGHT) {
            //                blc.moveBlock(RIGHT);
            //            } else if (kl.newMovement == DOWN) {
            //                blc.moveBlock(DOWN);
            //            } else if (kl.newMovement == ROTATE) {
            //                blc.rotateBlock();
            //            } else if (kl.newMovement == DROP) {
            //                blc.dropBlock();
            //            }


            kl.previousMovement = kl.newMovement;
            kl.newMovement = NONE;


            threepp::Clock clock;
            tetris::Input input{clock.elapsedTime};
            switch (input.previousMovement) {

            }


            if (kl.previousMovement == DROP) {
                group->clear();
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (blc.getTetronimo(type, rotation, i, j)) {
                            group->add(createBox({(float) (j) + 4, (float) (i), 0}, threepp::Color::crimson));
                        }
                    }
                }
                type += 1;
                rotation = 0;
            };
            if (rotation == 4) {
                rotation = 0;
            };
            if (type == 8) {
                type = 0;
            };
    } */
}// namespace tetris