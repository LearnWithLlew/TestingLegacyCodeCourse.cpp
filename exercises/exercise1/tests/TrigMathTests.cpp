#include <catch2/catch.hpp>
#include "TrigMath.h"


TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(Approx(0.8676642435) == math.Sin(3.4));
}


TEST_CASE("Test Asin") {
    TrigMath math;
    CHECK(isnan(math.Asin(3.4)));
    CHECK(Approx(-0.5235756122) == math.Asin(-0.5));
    CHECK(Approx(1.1197463516) == math.Asin(0.9));
}


TEST_CASE("Test Cos") {
    TrigMath math;
    CHECK(Approx(-0.8629090771) == math.Cos(3.4));
}

TEST_CASE("Test Tan") {
    TrigMath math;
    CHECK(Approx(-1.0055092655) == math.Tan(3.4));
}

TEST_CASE("Test Csc") {
    TrigMath math;
    CHECK(Approx(1.152519546) == math.Csc(3.4));
}

TEST_CASE("Test Sec") {
    TrigMath math;
    CHECK(Approx(-1.1588706464) == math.Sec(3.4));
}

TEST_CASE("Test Cot") {
    TrigMath math;
    CHECK(Approx(-0.9945209202) == math.Cot(3.4));
}

TEST_CASE("Test Acos") {
    TrigMath math;
    CHECK(Approx(1.0471743878) == math.Acos(0.5));
    CHECK(isnan(math.Acos(2)));
}

TEST_CASE("Test Atan") {
    TrigMath math;
    CHECK(Approx(0.4636244456) == math.Atan(0.5));
}

TEST_CASE("Test Atan2") {
    TrigMath math;
    CHECK(Approx(0.785375) == math.Atan2(0.5, 0.5));
}


TEST_CASE("Test Acsc") {
    TrigMath math;
    CHECK(Approx(0.5235756122) == math.Acsc(2));
    CHECK(isnan(math.Acsc(0.)));
}
