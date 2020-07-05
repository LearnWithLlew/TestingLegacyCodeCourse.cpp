#include <catch2/catch.hpp>
#include <ApprovalTests.hpp>
#include "TrigMath.h"

using namespace ApprovalTests;



TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(Approx(0.0) == math.Sin(3.4));
}
