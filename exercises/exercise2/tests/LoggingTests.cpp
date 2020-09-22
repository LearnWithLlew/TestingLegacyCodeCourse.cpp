#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#define SECURE 1
#define TESTING
#include "Services.h"

#include <iostream>

using namespace ApprovalTests;

TEST_CASE("Test initialiseServices")
{
    initialiseServices();
    Approvals::verify(logger.str());
}
