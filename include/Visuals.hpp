
#ifndef TETRIS_VISUALS_HPP
#define TETRIS_VISUALS_HPP

#include "Block.hpp"
#include "Board.hpp"
#include "Game.hpp"

#include <threepp/math/Vector2.hpp>
#include <threepp/objects/Group.hpp>
#include <threepp/objects/mesh.hpp>
#include <threepp/renderers/TextRenderer.hpp>
#include <vector>

#include <threepp/cameras/OrthographicCamera.hpp>
#include <threepp/renderers/GLRenderer.hpp>
#include <threepp/scenes/Scene.hpp>

namespace tetris {

    class Visuals {
    public:
        Visuals();

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

        threepp::TextRenderer tr;

        threepp::TextHandle& renderText(const std::string& text, int x, int y, float size);

    private:
        float width_ = 0.9;
        float height_ = 0.9;

        threepp::WindowSize renderingSize{800, 800};
        threepp::WindowSize canvasSize{550, 780};
        threepp::GLRenderer renderingEngine;
        std::shared_ptr<threepp::Scene> scene;
        std::shared_ptr<threepp::OrthographicCamera> camera;
        std::shared_ptr<threepp::Group> boardGroup;
        std::shared_ptr<threepp::Group> blockGroup;
        std::shared_ptr<threepp::Group> nextBlockGroup;
        threepp::TextHandle& textScore;
        threepp::TextHandle& textGameOver;
        threepp::TextHandle& textContinue;

        std::shared_ptr<threepp::Mesh> createPlane(const threepp::Vector3& pos, const threepp::Color& color);//Adjusted the function from threepp example
        std::shared_ptr<threepp::Mesh> createBox(const threepp::Vector3& pos, const threepp::Color& color);  //Adjusted the function from threepp example
        std::shared_ptr<threepp::Group> createBoardGroup(tetris::Board gameBoard);
        std::shared_ptr<threepp::Group> createBlockGroup(tetris::Block block);
        std::shared_ptr<threepp::Group> createNextBlockGroup(tetris::Block block);
        //        threepp::TextRenderer textRenderer;
        //        threepp::TextRenderer::Handle value;
    };

}// namespace tetris

#endif//TETRIS_VISUALS_HPP
