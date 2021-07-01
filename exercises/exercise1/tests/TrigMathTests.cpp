#include <catch2/catch.hpp>
#include "TrigMath.h"
#include <cmath>

TEST_CASE( "Test Sin" )
{
    TrigMath math;
    CHECK(math.Sin(3.4) == Approx(0.8676642435));
}

//TEST_CASE( "Test all" )
//{
//    TrigMath math;
//    CHECK(math.Sin(3.4) == Approx(0.0));
//    CHECK(math.Sin(3.4) == Approx(0.0));
//    CHECK(math.Cos(3.4) == Approx(0.0));
//    CHECK(math.Tan(3.4) == Approx(0.0));
//    CHECK(math.Csc(3.4) == Approx(0.0));
//    CHECK(math.Sec(3.4) == Approx(0.0));
//    CHECK(math.Cot(3.4) == Approx(0.0));
//    CHECK(math.Asin(3.4) == Approx(0.0));
//    CHECK(math.Acos(3.4) == Approx(0.0));
//    CHECK(math.Atan(3.4) == Approx(0.0));
//    CHECK(math.Atan2(3.4, .4) == Approx(0.0));
//    CHECK(math.Acsc(3.4) == Approx(0.0));
//    CHECK(math.Asec(3.4) == Approx(0.0));
//    std:cout << "CHECK(math.Asec(3.4) == Approx(0.0));\n";
//}

TEST_CASE( "Test ASin" )
{
    TrigMath math;
    CHECK(math.Asin(0.0) == Approx(0.0));
    CHECK(std::isnan(math.Asin(1.1)));
    CHECK(math.Asin(-0.5) == Approx(-0.5235756122));
    CHECK(math.Asin(0.8) == Approx(0.9272720546));
}

