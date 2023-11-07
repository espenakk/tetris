
#ifndef TETRIS_BLOCKS_HPP
#define TETRIS_BLOCKS_HPP

#include <threepp/threepp.hpp>

namespace tetris {

    class Blocks {
    public:
        //        int getTetronimo(int type, int rotation, int x, int y);
        //        Blocks() = default;

        //        void drawBlock(int type, int rotation, char group) {
        //            std::shared_ptr<threepp::Group> group = threepp::Group::create();
        //            for (int i = 0; i < 4; i++) {
        //                for (int j = 0; j < 4; j++) {
        //                    if (getTetronimo(type, rotation, i, j)) {
        //                        group->add(createBox({(float)(i),(float) (j), 0}, threepp::Color::crimson));
        //                    }
        //                }
        //            }
        //        };
        void moveBlock(int direction);
        void rotateBlock();
        void dropBlock();
    };
}// namespace tetris
#endif//TETRIS_BLOCKS_HPP
