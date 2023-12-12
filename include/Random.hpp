
#ifndef TETRIS_RANDOM_HPP
#define TETRIS_RANDOM_HPP

#include <vector>

namespace tetris {

    class Random {// This class was made with assistance from AI
    public:
        Random();
        int getType();

    private:
        std::vector<int> lastTenTypes;
        int consecutive_count[7];
        void resetConsecutiveCount();
    };

}// namespace tetris

#endif//TETRIS_RANDOM_HPP
