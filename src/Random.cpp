
#include "Random.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>

namespace tetris {
    Random::Random() {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        lastTenTypes.reserve(10);
        resetConsecutiveCount();
    }
    int Random::getType() {
        if (lastTenTypes.size() == 10) {
            lastTenTypes.erase(lastTenTypes.begin());
        }
        std::vector<int> available_numbers = {0, 1, 2, 3, 4, 5, 6};
        for (int num : lastTenTypes) {
            available_numbers.erase(std::remove(available_numbers.begin(), available_numbers.end(), num), available_numbers.end());
        }

        if (available_numbers.empty()) {
            available_numbers = {0, 1, 2, 3, 4, 5, 6};
        }

        int number;
        while (true) {
            number = available_numbers[rand() % available_numbers.size()];

            if (consecutive_count[number] < 3) {
                consecutive_count[number]++;
                resetConsecutiveCount();
                lastTenTypes.push_back(number);
                return number;
            } else {
                available_numbers.erase(std::remove(available_numbers.begin(), available_numbers.end(), number), available_numbers.end());
            }
        }
    }
    void Random::resetConsecutiveCount() {
        for (int i = 0; i < 7; i++) {
            consecutive_count[i] = 0;
        }
    }
}// namespace tetris