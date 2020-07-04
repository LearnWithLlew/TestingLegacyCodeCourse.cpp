#include <catch2/catch.hpp>
#include "TrigMath.h"

using namespace std;



TEST_CASE("Test sin") {
    TrigMath math;
    REQUIRE(Approx(0.0) == math.sin(3.4));
}
