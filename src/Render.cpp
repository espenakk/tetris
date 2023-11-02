#include "Render.hpp"
#include "Blocks.hpp"
#include "Board.hpp"
#include "Input.hpp"
namespace tetris {
    std::shared_ptr<threepp::Mesh> Render::createPlane(const threepp::Vector3& pos, const threepp::Color& color, float width, float height) {
        auto geometry = threepp::PlaneGeometry::create(width, height);
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);

        return mesh;
    }
    std::shared_ptr<threepp::Mesh> Render::createBox(const threepp::Vector3& pos, const threepp::Color& color) {
        auto geometry = threepp::BoxGeometry::create();
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);

        return mesh;
    }
    void Render::initializeScene() {

        tetris::Board brd;
        tetris::Blocks blc;

        threepp::Canvas canvas("Tetris", {{"aa", 4}});
        threepp::GLRenderer renderer(canvas.size());
        renderer.setClearColor(threepp::Color::goldenrod);
        std::shared_ptr<threepp::OrthographicCamera> camera = threepp::OrthographicCamera::create();
        camera->position.z = 20;
        camera->position.x = 5.5;
        camera->position.y = 11;
        camera->rotateZ(3.14);
        std::shared_ptr<threepp::Scene> scene = threepp::Scene::create();

        /*std::shared_ptr<threepp::Group> boardObjectsGroup = threepp::Group::create();
        boardObjectsGroup->add(createPlane({0.5, 0, 0}, threepp::Color::darkgrey, 17, 22));
        boardObjectsGroup->add(createPlane({-2, 0, 0}, threepp::Color::black, 10, 20));
        boardObjectsGroup->add(createPlane({6, 0, 0}, threepp::Color::darkslateblue, 4, 20));
        scene->add(boardObjectsGroup);

        std::shared_ptr<threepp::Group> group = threepp::Group::create();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (blc.getTetronimo(0, 0, i, j)) {
                    group->add(createBox({(float) (i), (float) (j), 0}, threepp::Color::crimson));
                }
            }
        }

        scene->add(group);

        Board t;
        std::shared_ptr<threepp::Group> grid = t.drawGrid();
        scene->add(grid);

        threepp::Clock clock;
        tetris::Input kl{clock.elapsedTime};

        canvas.addKeyListener(&kl);

        canvas.onWindowResize([&](threepp::WindowSize size) {
            //camera->aspect = size.aspect();
            camera->zoom = 0.05;
            camera->updateProjectionMatrix();
            renderer.setSize(size);
        });

        canvas.animate([&] {
            renderer.render(*scene, *camera);
            renderer.resetState();

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
        });
    }
    void Render::renderScene() {}
}// namespace tetris