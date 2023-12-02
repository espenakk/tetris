
#ifndef TETRIS_POSITION_HPP
#define TETRIS_POSITION_HPP

namespace tetris {

    class Position {
    public:
        Position(int row, int column);
        int row;
        int column;
    };

}// namespace tetris

#endif//TETRIS_POSITION_HPP
