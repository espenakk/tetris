
#include "Visuals.hpp"
#include <threepp/geometries/BoxGeometry.hpp>
#include <threepp/geometries/PlaneGeometry.hpp>
#include <threepp/materials/MeshBasicMaterial.hpp>
#include <threepp/math/Color.hpp>

namespace tetris {
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

    threepp::Color::ColorName getTileColour(TileType type) {
        switch (type) {
            case TileType::EmptyTile:
                return threepp::Color::gray;
            case TileType::SpawnZone:
                return threepp::Color::hotpink;
            case TileType::T:
                return threepp::Color::blueviolet;
            case TileType::S:
                return threepp::Color::limegreen;
            case TileType::Z:
                return threepp::Color::red;
            case TileType::L:
                return threepp::Color::darkorange;
            case TileType::J:
                return threepp::Color::deepskyblue;
            case TileType::I:
                return threepp::Color::cyan;
            case TileType::O:
                return threepp::Color::yellow;
        }
    };

    std::shared_ptr<threepp::Group> Visuals::createBoardGroup(tetris::Board gameBoard) {
        std::shared_ptr<threepp::Group> group;
        group = threepp::Group::create();
        for (int i = 0; i < gameBoard.boardHeight; i++) {
            for (int j = 0; j < gameBoard.boardWidth; j++) {
                auto value = gameBoard.getGridValue(j, i);
                group->add(createBox({(float) j, (float) i, 0}, getTileColour(static_cast<TileType>(value))));
            }
        }
        return group;
    }

    std::shared_ptr<threepp::Group> Visuals::createBlockGroup(tetris::Block block) {
        std::shared_ptr<threepp::Group> group;
        group = threepp::Group::create();
        for (const threepp::Vector2& pos : block.blockPositions()) {
            group->add(createBox({pos.x, pos.y, 0}, getTileColour(block.type)));
        }
        return group;
    }

    std::shared_ptr<threepp::Group> Visuals::createNextBlockGroup(tetris::Block block) {
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
        game.movedTilesY = 0;
        game.movedTilesX = 0;
        game.rotate = 0;
    }
}// namespace tetris