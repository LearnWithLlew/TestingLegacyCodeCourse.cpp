#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"

using namespace ApprovalTests;



TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(Approx(0.8676960543) == math.Sin(3.4));
}


TEST_CASE("Test Asin") {
    TrigMath math;
    CHECK(isnan(math.Asin(3.4)));
    CHECK(Approx(-0.5235987756) == math.Asin(-0.5));
    CHECK(Approx(1.119769515) == math.Asin(0.9));
}
