#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"

using namespace ApprovalTests;



TEST_CASE("ApprovalTest Sin") {
    TrigMath math;
    Approvals::verify(math.Sin(0.0));
}


TEST_CASE("ApprovalTest Cos") {
    TrigMath math;
    Approvals::verify(math.Cos(0.0));
}
