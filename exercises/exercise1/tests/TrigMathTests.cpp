#include <catch2/catch.hpp>
#include "TrigMath.h"


TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(Approx(0.8676642435) == math.Sin(3.4));
}

TEST_CASE("Test ASin") {
    TrigMath math;
    REQUIRE(std::isnan(math.Asin(3.4)));
    REQUIRE(Approx(-1.57075) == math.Asin(-1.0));
    REQUIRE(Approx(0.304692654) == math.Asin(0.3));
}
