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


#endif //LEGACY_CODE_COURSE_SAMPLES_H
