
#ifndef TETRIS_BLOCKS_HPP
#define TETRIS_BLOCKS_HPP

namespace tetris {

    class Blocks {
    public:
        Blocks() = default;

        void drawBlock(int type, int rotation, int x, int y);
        void moveBlock(int type, int rotation, int x, int y);
        void rotateBlock(int type, int rotation, int x, int y);

        bool getTetronimo(int type, int rotation, int x, int y);
    };
}// namespace tetris
#endif//TETRIS_BLOCKS_HPP
