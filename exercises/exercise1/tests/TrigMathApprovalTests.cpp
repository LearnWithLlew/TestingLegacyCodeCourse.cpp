#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"

using namespace ApprovalTests;



TEST_CASE("ApprovalTest Sin") {
    TrigMath math;
    auto result = math.Sin(0.0);
    Approvals::verify(result);
}

TEST_CASE("ApprovalTest Cos") {
    TrigMath math;
    auto result = math.Cos(0.0);
    Approvals::verify(result);
}