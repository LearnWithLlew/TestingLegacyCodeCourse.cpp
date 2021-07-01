#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "MissingInputs.h"

using namespace ApprovalTests;

TEST_CASE( "Test MissingInputs" )
{
    MissingInputs missingInputs;
    Approvals::verify(missingInputs.getCategory());
    CHECK(missingInputs.GetCategory2(5) == 2);
}
