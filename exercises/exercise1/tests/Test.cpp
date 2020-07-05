#include <catch2/catch.hpp>
#include "../code/TrigMath.h"


TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(Approx(0.8676960543) == math.Sin(3.4));
}

TEST_CASE("Test Asin") {
    TrigMath math;
    REQUIRE(Approx(-0.7753974966) == math.Asin(-0.7));
    REQUIRE(Approx(0.304692654) == math.Asin(0.3));
    REQUIRE(Approx(1.119769515) == math.Asin(0.9));
    REQUIRE(isnan(math.Asin(1.2)));
}
