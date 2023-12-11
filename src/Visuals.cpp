
#include "Visuals.hpp"
#include <threepp/geometries/BoxGeometry.hpp>
#include <threepp/materials/MeshBasicMaterial.hpp>
#include <threepp/math/Color.hpp>

namespace tetris {

    Visuals::Visuals(): renderingEngine(renderingSize), scene(threepp::Scene::create()), camera(threepp::OrthographicCamera::create()), textScore(renderText("", 400, 500, 2)), textGameOver(renderText("", 39, 350, 4)), textContinue(renderText("", 39, 420, 1.5)) {
        renderingEngine.setClearColor(threepp::Color::black);
        camera->position.z = 1;
        camera->position.x = -2;
        camera->position.y = 11.5;
        camera->rotateZ(3.1415);
        camera->zoom = 0.08;
        camera->updateProjectionMatrix();
        renderText("Next Block", 370, 220, 2);
        renderText("Score", 400, 450, 2);
    }

    std::shared_ptr<threepp::Mesh> Visuals::createBox(const threepp::Vector3& pos, const threepp::Color& color) const {//Adjusted the function from threepp example
        auto geometry = threepp::BoxGeometry::create(width_, height_);
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);
        return mesh;
    }

    threepp::Color::ColorName getTileColour(TileType type) {
        threepp::Color::ColorName colour;
        switch (type) {
            case EmptyTile:
                colour = threepp::Color::gray;
                break;
            case SpawnZone:
                colour = threepp::Color::hotpink;
                break;
            case T:
                colour = threepp::Color::blueviolet;
                break;
            case S:
                colour = threepp::Color::limegreen;
                break;
            case Z:
                colour = threepp::Color::red;
                break;
            case L:
                colour = threepp::Color::darkorange;
                break;
            case J:
                colour = threepp::Color::deepskyblue;
                break;
            case I:
                colour = threepp::Color::cyan;
                break;
            case O:
                colour = threepp::Color::yellow;
                break;
        }
        return colour;
    }

    std::shared_ptr<threepp::Group> Visuals::createBoardGroup(Board& gameBoard) {
        std::shared_ptr<threepp::Group> group;
        group = threepp::Group::create();
        for (int i = 0; i < gameBoard.boardHeight; i++) {
            for (int j = 0; j < gameBoard.boardWidth; j++) {
                auto value = gameBoard.getGridTileType(j, i);
                group->add(createBox({(float) j, (float) i, 0}, getTileColour(static_cast<TileType>(value))));
            }
        }
        return group;
    }

    std::shared_ptr<threepp::Group> Visuals::createBlockGroup(Block& block) {
        std::shared_ptr<threepp::Group> group;
        group = threepp::Group::create();
        for (const threepp::Vector2& pos : block.tilePositions()) {
            group->add(createBox({pos.x, pos.y, 0}, getTileColour(block.type)));
        }
        return group;
    }

    std::shared_ptr<threepp::Group> Visuals::createNextBlockGroup(Block& block) {
        auto group = createBlockGroup(block);
        group->translateX(-8.0f);
        group->translateY(8.0f);
        return group;
    }

    void Visuals::setupScene(Game& game) {
        boardGroup = createBoardGroup(game.board);
        scene->add(boardGroup);
        blockGroup = createBlockGroup(game.currentBlock);
        scene->add(blockGroup);
        nextBlockGroup = createNextBlockGroup(game.nextBlock);
        scene->add(nextBlockGroup);
    }

    void Visuals::renderGame(Game& game) {
        if (game.renderGame) {
            blockGroup->clear();
            boardGroup->clear();
            nextBlockGroup->clear();
            blockGroup = createBlockGroup(game.currentBlock);
            scene->add(blockGroup);
            boardGroup = createBoardGroup(game.board);
            scene->add(boardGroup);
            nextBlockGroup = createNextBlockGroup(game.nextBlock);
            scene->add(nextBlockGroup);
            game.renderGame = false;
        }
    }
    void Visuals::renderTetromino(Game& game) {
        if (game.renderTetromino) {
            blockGroup->clear();
            blockGroup = createBlockGroup(game.currentBlock);
            scene->add(blockGroup);
            game.renderTetromino = false;
        }
    }
    void Visuals::render(Game& game) {
        renderingEngine.render(*scene, *camera);
        renderingEngine.resetState();
        renderTetromino(game);
        renderGame(game);
    }

    threepp::TextHandle& Visuals::renderText(const std::string& text, int x, int y, float size) {
        threepp::TextHandle& handle = tr.createHandle();
        handle.setText(text);
        handle.setPosition(x, y);
        handle.scale = size;
        return handle;
    }
}// namespace tetris