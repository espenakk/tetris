
#include "Position.hpp"

namespace tetris {
    Position::Position(int row, int column): row(row_), column(column_) {
        this->row = row;
        this->column = column;
    }
}// namespace tetris