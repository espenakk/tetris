
#include "Board.hpp"

namespace tetris {

    Board::Board() {
        amountOfRows = 21;
        amountOfColumns = 12;
        blockSize = 4;
        initGrid();
    }
    void Board::initGrid() {
        for (int row = 0; row < amountOfRows; row++) {
            for (int column = 0; column < amountOfColumns; column++) {
                if ((column == 0) || (column == amountOfColumns - 1) || (row == amountOfRows - 1)) {
                    grid[row][column] = 2;
                } else {
                    grid[row][column] = 0;
                }
            }
        }
    }
    void Board::printGrid() {
        for (int i = 0; i < amountOfRows; i++) {
            for (int j = 0; j < amountOfColumns; j++) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    /*void Board::saveBlock(int type, int rotation, int x, int y) {

        Blocks test;

        for (int i1 = 0, i2 = 0; i1 < x+blockSize; i1++, i2++) {
            for (int j1 = 0, j2 = 0; j1 < y+blockSize; j1++, j2++) {
                if(test.getTetronimo(type, rotation, j2, i2) != 0)
                    grid[i1][j1] = 1;
            }
        }
    }
     */
    void Board::saveBlock(int type, int rotation, int x, int y) {
        Blocks test;
        for (int i = 0; i < blockSize; i++) {
            for (int j = 0; j < blockSize; j++) {
                block[i][j] = test.getTetronimo(type, rotation, i, j);
            }
        }
        for (int i = 0; i < blockSize; i++) {
            for (int j = 0; j < blockSize; j++) {
                grid[i][j + 4] = grid[i][j + 4] + block[i][j];
            }
        }
    }
    int Board::whatIsGridValue(int x, int y) {
        int gridvalue = 0;
        if (grid[x][y] == 0)
            gridvalue = 0;
        else if (grid[x][y] == 1)
            gridvalue = 1;
        else if (grid[x][y] == 2)
            gridvalue = 2;
        return gridvalue;
    }

    void Board::testwhatisgrid(int x, int y) {
        int test = whatIsGridValue(x, y);
        std::cout << test << " ";
    }

    std::shared_ptr<threepp::Mesh> Board::create3dGrid(const threepp::Vector3& pos, const threepp::Color& color, float boxWidth, float boxHeight) {
        auto geometry = threepp::BoxGeometry::create(boxWidth, boxHeight);
        auto material = threepp::MeshBasicMaterial::create();
        material->color.copy(color);
        auto mesh = threepp::Mesh::create(geometry, material);
        mesh->position.copy(pos);
        return mesh;
    }
    std::shared_ptr<threepp::Group> Board::drawGrid() {
        std::shared_ptr<threepp::Group> gridGroup = threepp::Group::create();
        for (float i = 0; i < amountOfRows; i++) {
            for (float j = 0; j < amountOfColumns; j++) {
                if (whatIsGridValue(i, j) == 0) {
                    gridGroup->add(Board::create3dGrid({j, i, 0}, threepp::Color::gray, 0.9, 0.9));
                } else if (whatIsGridValue(i, j) == 1) {
                    gridGroup->add(Board::create3dGrid({j, i, 0}, threepp::Color::crimson, 0.9, 0.9));
                } else if (whatIsGridValue(i, j == 2)) {
                    gridGroup->add(Board::create3dGrid({j, i, 0}, threepp::Color::black, 0.9, 0.9));
                }
            }
        }
        return gridGroup;
    }
}// namespace tetris