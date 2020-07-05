#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "../code/TrigMath.h"

#include <sstream>

using namespace ApprovalTests;

namespace
{
    void runOne(std::ostream& s, std::string function, double input, double result)
    {
        s << function << input << ": " << result << '\n';
    }
    std::string runEverything(double value)
    {
        TrigMath math;
        std::stringstream s;
        s << "input value: " << value << '\n';
        runOne(s, "Sin()  : ", value, math.Sin(value));
        runOne(s, "Floor(): ", value, math.Floor(value) );
        runOne(s, "Cos()  : ", value, math.Cos(value) );
        runOne(s, "Tan()  : ", value, math.Tan(value) );
        runOne(s, "Csc()  : ", value, math.Csc(value) );
        runOne(s, "Sec()  : ", value, math.Sec(value) );
        runOne(s, "Cot()  : ", value, math.Cot(value) );
        runOne(s, "Asin() : ", value, math.Asin(value) );
        runOne(s, "Acos() : ", value, math.Acos(value) );
        runOne(s, "Atan() : ", value, math.Atan(value) );
        runOne(s, "Atan2(): ", value, math.Atan2(value, value) );
        runOne(s, "Acsc() : ", value, math.Acsc(value) );
        runOne(s, "Asec() : ", value, math.Asec(value) );
        runOne(s, "Acot() : ", value, math.Acot(value) );
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

TEST_CASE("Approve everything - for 3.14")
{
    Approvals::verify(runEverything(3.14));
}

TEST_CASE("Approve everything - for 1.0 and 3.14")
{
    std::vector<double> values{ 1.0, 3.14 };
    Approvals::verifyAll("runEverything", values, [](double value, std::ostream& o) {
        o << runEverything(value);
        }
    );
}

TEST_CASE("Combination approvals - for one input")
{
    std::vector<double> values{ 1.0 };
    CombinationApprovals::verifyAllCombinations(
        [](double value) { return runEverything(value); }, values);
}

TEST_CASE("Approve Atan2 - all values")
{
    std::vector<double> values{ -0.5, 0, 0.5, 1.0 };
    TrigMath math;
    CombinationApprovals::verifyAllCombinations(
        [&math](double value1, double value2) { return math.Atan2(value1, value2); },
        values, values);
}

