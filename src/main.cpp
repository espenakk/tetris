#include <iostream>
#include <threepp/extras/imgui/ImguiContext.hpp>
#include <threepp/threepp.hpp>

#include "Blocks.hpp"
#include "Board.hpp"
#include "Input.hpp"


namespace create {
    std::shared_ptr<threepp::Mesh> Plane(const threepp::Vector3& pos, const threepp::Color& color, float width, float height) {
        auto geometry = threepp::PlaneGeometry::create(width, height);
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);

        return mesh;
    }

    std::shared_ptr<threepp::Mesh> Box(const threepp::Vector3& pos, const threepp::Color& color) {
        auto geometry = threepp::BoxGeometry::create();
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);

        return mesh;
    }
}// namespace create


int main() {
    tetris::Blocks b;
    threepp::Canvas canvas("Tetris", {{"aa", 4}});
    threepp::GLRenderer renderer(canvas.size());
    renderer.setClearColor(threepp::Color::aliceblue);
    std::shared_ptr<threepp::PerspectiveCamera> camera = threepp::PerspectiveCamera::create();
    camera->position.z = 20;
    std::shared_ptr<threepp::Scene> scene = threepp::Scene::create();

    std::shared_ptr<threepp::Group> boardObjectsGroup = threepp::Group::create();
    boardObjectsGroup->add(create::Plane({0.5, 0, 0}, threepp::Color::darkgrey, 17, 22));
    boardObjectsGroup->add(create::Plane({-2, 0, 0}, threepp::Color::black, 10, 20));
    boardObjectsGroup->add(create::Plane({6, 0, 0}, threepp::Color::darkslateblue, 4, 20));
    scene->add(boardObjectsGroup);

    std::shared_ptr<threepp::Group> blocksObjectsGroup = threepp::Group::create();
    scene->add(blocksObjectsGroup);


    threepp::Clock clock;
    tetris::Input kl{clock.elapsedTime};
    canvas.addKeyListener(&kl);

    canvas.onWindowResize([&](threepp::WindowSize size) {
        camera->aspect = size.aspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
    });

    canvas.animate([&] {
        renderer.render(*scene, *camera);
        renderer.resetState();
    });
    return 0;
}