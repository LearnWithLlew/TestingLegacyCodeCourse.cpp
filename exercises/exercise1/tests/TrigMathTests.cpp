#include <catch2/catch.hpp>
#include "TrigMath.h"


TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(Approx(0.8676642435) == math.Sin(3.4));
}

TEST_CASE("Test Asin") {
    TrigMath math;
    REQUIRE(Approx(0.5235756122) == math.Asin(0.5));
}

TEST_CASE("Test Asin Negative") {
    TrigMath math;
    REQUIRE(Approx(-0.5235756122) == math.Asin(-0.5));
}

TEST_CASE("Test Asin Out of bounds") {
    TrigMath math;
    REQUIRE(isnan(math.Asin(1.1)));
}

TEST_CASE("Test Asin Half Pi") {
    TrigMath math;
    REQUIRE(Approx(0.9272720546) == math.Asin(0.8));
}

TEST_CASE("Test Cos") {
    TrigMath math;
    REQUIRE(Approx(0.8676017647) == math.Cos(0.8));
}

TEST_CASE("Test Tan") {
    TrigMath math;
    REQUIRE(Approx(0.0112970299) == math.Tan(0.8));
}

TEST_CASE("Test Csc") {
    TrigMath math;
    REQUIRE(Approx(102.027042006) == math.Csc(0.8));
}