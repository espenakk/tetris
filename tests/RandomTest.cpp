
#include "Random.hpp"
#include <catch2/catch_test_macros.hpp>

#include "Random.hpp"
#include <catch2/catch_test_macros.hpp>


TEST_CASE("Test getType method") {
    tetris::Random randomizer;
    int lastNumber = -1;
    int consecutiveCount = 0;
    for (int i = 0; i < 1000; i++) {
        int number = randomizer.getType();
        REQUIRE(number >= 0);
        REQUIRE(number <= 6);
        if (number == lastNumber) {
            consecutiveCount++;
        } else {
            consecutiveCount = 1;
            lastNumber = number;
        }
        REQUIRE(consecutiveCount <= 3);
    }
}
