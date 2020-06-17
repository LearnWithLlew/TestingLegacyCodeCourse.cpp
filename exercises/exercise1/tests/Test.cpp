#include <catch2/catch.hpp>
#include "../code/TrigMath.h"

using namespace std;



TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(Approx(0.8676960543) == math.Sin(3.4));
}
