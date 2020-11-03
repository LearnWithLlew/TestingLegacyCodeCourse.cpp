#include <catch2/catch.hpp>
#include "TrigMath.h"


TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(math.Sin(3.4) == Approx(0.8676642435));
}

TEST_CASE("Test ASin") {
    TrigMath math;
    REQUIRE(isnan(math.Asin(3.4)));
    REQUIRE(math.Asin(0.4) == Approx(0.4114936827));
    REQUIRE(math.Asin(-0.4) == Approx(-0.4114936827));
    REQUIRE(math.Asin(0.8) == Approx(0.9272720546));

    REQUIRE(math.Cos(3.4) == Approx(-0.8629102418));
}
