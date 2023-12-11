
#ifndef TETRIS_VISUALS_HPP
#define TETRIS_VISUALS_HPP

#include "Game.hpp"
#include <threepp/cameras/OrthographicCamera.hpp>
#include <threepp/objects/Group.hpp>
#include <threepp/objects/mesh.hpp>
#include <threepp/renderers/GLRenderer.hpp>
#include <threepp/renderers/TextRenderer.hpp>
#include <threepp/scenes/Scene.hpp>
#include <vector>

namespace tetris {

    class Visuals {
    public:
        Visuals(): renderingEngine(renderingSize), scene(threepp::Scene::create()), camera(threepp::OrthographicCamera::create()) {
            renderingEngine.setClearColor(threepp::Color::black);
            camera->position.z = 1;
            camera->position.x = -2;
            camera->position.y = 11.5;
            camera->rotateZ(3.1415);
            camera->zoom = 0.08;
            camera->updateProjectionMatrix();
        }

        void setupScene(Game& game);
        void renderGame(Game& game);
        void renderTetromino(Game& game);

        //        void renderScore(int score) {
        //            std::string scoreText = std::to_string(score);
        //            value.setText(scoreText);
        //        }

        void render(Game& game);

        threepp::WindowSize getCanvasSize() {
            return canvasSize;
        }

        //threepp::TextHandle renderText(std::string text, int x, int y, int pos);

    private:
        const float width_ = 0.9;
        const float height_ = 0.9;

        const threepp::WindowSize renderingSize{800, 800};
        const threepp::WindowSize canvasSize{550, 780};
        threepp::GLRenderer renderingEngine;
        std::shared_ptr<threepp::Scene> scene;
        std::shared_ptr<threepp::OrthographicCamera> camera;
        std::shared_ptr<threepp::Group> boardGroup;
        std::shared_ptr<threepp::Group> blockGroup;
        std::shared_ptr<threepp::Group> nextBlockGroup;

        std::shared_ptr<threepp::Mesh> createBox(const threepp::Vector3& pos, const threepp::Color& color) const;//Adjusted the function from threepp example
        std::shared_ptr<threepp::Group> createBoardGroup(tetris::Board& gameBoard);
        std::shared_ptr<threepp::Group> createBlockGroup(tetris::Block& block);
        std::shared_ptr<threepp::Group> createNextBlockGroup(tetris::Block& block);
        //        threepp::TextRenderer textRenderer;
        //        threepp::TextRenderer::Handle value;
    };

}// namespace tetris

#endif//TETRIS_VISUALS_HPP
