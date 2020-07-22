#include <catch2/catch.hpp>
#include "TrigMath.h"


TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(Approx(0.8676642435) == math.Sin(3.4));
}
