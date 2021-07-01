#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"

using namespace ApprovalTests;

TEST_CASE( "ApprovalTest Sin" )
{
    TrigMath math;
    Approvals::verify(math.Sin(1.20));
}
