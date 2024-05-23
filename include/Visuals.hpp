
#ifndef TETRIS_VISUALS_HPP
#define TETRIS_VISUALS_HPP

#include "Game.hpp"

#include <threepp/cameras/OrthographicCamera.hpp>
#include <threepp/objects/Group.hpp>
#include <threepp/objects/Mesh.hpp>
#include <threepp/renderers/GLRenderer.hpp>
#include <threepp/renderers/TextRenderer.hpp>
#include <threepp/scenes/Scene.hpp>

namespace tetris {

    class Visuals {
    public:
        Visuals();

        void setupScene(Game& game);
        void renderGame(Game& game);
        void renderTetromino(Game& game);
        void render(Game& game);

        threepp::WindowSize getCanvasSize();
        threepp::TextRenderer textRenderer;
        threepp::TextHandle& renderText(const std::string& text, int x, int y, float size);

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
        threepp::TextHandle& textScore;
        threepp::TextHandle& textGameOver;
        threepp::TextHandle& textContinue;

        std::shared_ptr<threepp::Mesh> createBox(const threepp::Vector3& pos, const threepp::Color& color) const;//Adjusted the function from threepp example
        std::shared_ptr<threepp::Group> createBoardGroup(tetris::Board& gameBoard);
        std::shared_ptr<threepp::Group> createBlockGroup(tetris::Block& block);
        std::shared_ptr<threepp::Group> createNextBlockGroup(tetris::Block& block);
    };

}// namespace tetris

#endif//TETRIS_VISUALS_HPP
