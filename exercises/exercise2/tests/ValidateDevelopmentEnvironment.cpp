#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

using namespace ApprovalTests;

TEST_CASE("Validate Development Environment")
{
  // When you run this test the first time, it should fail,
  // and open some sort of file-comparison tool.
  // After that, please change the message in the call below to
  // "it works" and re-run it to see it pass.
  Approvals::verify("it does not work");
}
