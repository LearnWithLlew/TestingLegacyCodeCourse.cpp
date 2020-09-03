#include <catch2/catch.hpp>

TEST_CASE("Validate Development Environment")
{
  // When you run this test the first time, it should fail.
  // After that, please change the strings to match.
  // It should then pass.
  std::string input = "it does not work";
  REQUIRE(input == "it works");
}
