#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "Services.h"

#include <iostream>

using namespace ApprovalTests;

TEST_CASE("Test initialiseServices")
{
	logger.clear();
	initialiseServices();
	Approvals::verify(logger.str());
}
