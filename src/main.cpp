#include <iostream>
#include <threepp/extras/imgui/ImguiContext.hpp>
#include <threepp/threepp.hpp>

#include "Blocks.hpp"
#include "Board.hpp"


namespace create {
    std::shared_ptr<threepp::Mesh> BackDrop(const threepp::Vector3& pos, const threepp::Color& color) {
        auto geometry = threepp::PlaneGeometry::create(17, 22);
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);

        return mesh;
    }

    std::shared_ptr<threepp::Mesh> Board(const threepp::Vector3& pos, const threepp::Color& color) {
        auto geometry = threepp::PlaneGeometry::create(10, 20);
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);

        return mesh;
    }
    std::shared_ptr<threepp::Mesh> ScoreBoard(const threepp::Vector3& pos, const threepp::Color& color) {
        auto geometry = threepp::PlaneGeometry::create(4, 20);
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
    threepp::Canvas canvas("Tetris", {{"aa", 4}});
    threepp::GLRenderer renderer(canvas.size());
    renderer.setClearColor(threepp::Color::aliceblue);
    std::shared_ptr<threepp::PerspectiveCamera> camera = threepp::PerspectiveCamera::create();
    camera->position.z = 20;
    std::shared_ptr<threepp::Scene> scene = threepp::Scene::create();

    std::shared_ptr<threepp::Group> boardObjectsGroup = threepp::Group::create();
    boardObjectsGroup->add(create::BackDrop({0.5, 0, 0}, threepp::Color::darkgrey));
    boardObjectsGroup->add(create::Board({-2, 0, 0}, threepp::Color::darksalmon));
    boardObjectsGroup->add(create::ScoreBoard({6, 0, 0}, threepp::Color::darkslateblue));
    scene->add(boardObjectsGroup);

    std::shared_ptr<threepp::Group> blocksObjectsGroup = threepp::Group::create();

    /**************************
     *  Fredags testing :)
     *************************/

    bool t_block[9]{
            0, 1, 0,
            1, 1, 1,
            0, 0, 0};

    bool s_block[2][9]{
            {0, 0, 0,
             0, 1, 1,
             1, 1, 0},
            {1, 0, 0,
             1, 1, 0,
             0, 1, 0}};
    bool z_block[9]{
            0, 0, 0,
            1, 1, 0,
            0, 1, 1};
    bool l_block[9]{
            0, 1, 0,
            0, 1, 0,
            0, 1, 1};

    auto printBlock = [](bool block[9]) {
        for (int i = 0; i < 9; i++) {
            std::cout << block[i] << " ";
            if (i % 3 == 2) {
                std::cout << std::endl;
            }
        }
    };

    auto print3D_block = [blocksObjectsGroup](bool block[9]) {
        for (int i = 0; i < 9; i++) {
            if (block[i]) {
                blocksObjectsGroup->add(create::Box({(float) (i % 3), (float) (i / 3), 0}, threepp::Color::crimson));
            }
        }
    };

    auto rotateBlock_90_deg = [](bool block[9]) {
        bool temp[9];
        for (int i = 0; i < 9; i++) {
            temp[i] = block[i];
        }
        for (int i = 0; i < 9; i++) {
            block[i] = temp[6 - ((i % 3) * 3) + (i / 3)];
        }
        return block;
    };

    //        std::cout << std::endl;
    //        printblock(rotateblock_90_deg(t_block));
    //        std::cout << std::endl;
    //        printblock(rotateblock_90_deg(t_block));
    //        std::cout << std::endl;
    //        printblock(rotateblock_90_deg(t_block));
    scene->add(blocksObjectsGroup);

    canvas.onWindowResize([&](threepp::WindowSize size) {
        camera->aspect = size.aspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
    });
    auto temp_block = s_block[0];
    int select = 0;
    int frame = 0;
    canvas.animate([&] {
        blocksObjectsGroup->clear();
        if (frame % 10 == 0) {
            //                rotateblock_90_deg(s_block);
            select = 1 - select;
        }
        print3D_block(s_block[select]);
        frame++;
        renderer.render(*scene, *camera);
        renderer.resetState();
    });
    return 0;
}
