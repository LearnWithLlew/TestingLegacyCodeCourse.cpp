#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "../code/TrigMath.h"

#include <sstream>

using namespace ApprovalTests;

namespace
{
    std::string runEverything(double value)
    {
        TrigMath math;
        std::stringstream s;
        s << "input value: " << value << '\n';
        s << math.Sin(value) << '\n';
        s << math.Floor(value) << '\n';
        s << math.Cos(value) << '\n';
        s << math.Tan(value) << '\n';
        s << math.Csc(value) << '\n';
        s << math.Sec(value) << '\n';
        s << math.Cot(value) << '\n';
        s << math.Asin(value) << '\n';
        s << math.Acos(value) << '\n';
        s << math.Atan(value) << '\n';
        s << math.Atan2(value, value) << '\n';
        s << math.Acsc(value) << '\n';
        s << math.Asec(value) << '\n';
        s << math.Acot(value) << '\n';
        return s.str();
    }
}

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

TEST_CASE("Approve Sin")
{
    TrigMath math;
    Approvals::verify(math.Sin(3.2));
}

TEST_CASE("Approve Cos")
{
    TrigMath math;
    Approvals::verify(math.Cos(3.2));
}

TEST_CASE("Approve everything - for 1.0")
{
    Approvals::verify(runEverything(1.0));
}

