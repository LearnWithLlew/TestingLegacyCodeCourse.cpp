#ifndef LEGACY_CODE_COURSE_SAMPLES_H
#define LEGACY_CODE_COURSE_SAMPLES_H

#include <catch2/catch.hpp>

TEST_CASE("Test Setup") {
    TrigMath math; // Arrange
    REQUIRE(math.DEG_TO_RAD == Approx(0.0174532925)); // Assert
}

TEST_CASE("Test Function") {
    auto result = pow(2, 3); // Act
    REQUIRE(result == Approx(8)); // Assert
}

TEST_CASE("Graphing")
{
    std::stringstream s;
    TrigMath math;
    for ( double i = 0; i <= 6.28; i += 0.01)
    {
        s << i << ',' << math.Sin(i) << '\n';
    }
    Approvals::verify(s.str(), Options().fileOptions().withFileExtension(".csv"));
}


#endif //LEGACY_CODE_COURSE_SAMPLES_H
