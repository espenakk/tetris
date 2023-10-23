
#ifndef TETRIS_BOARD_HPP
#define TETRIS_BOARD_HPP

namespace tetris {

    class Board {
    public:
        void keyboardInput();
        void saveCurrentBoard();
        void gameLogic();

        void start();
        void reset();

        void drawBackDrop();
        void drawBoard();

        int randomBlockGenerator();
        void newBlock();
        void rotateBlock();
        void moveBlock(int x, int y);
        void clearLine();
        bool collisionCheck(int x, int y);
        bool gameOverCheck();
    };

}// namespace tetris

#endif//TETRIS_BOARD_HPP
