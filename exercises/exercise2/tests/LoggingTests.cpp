#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#define TESTING

#include "Services.h"

#include <iostream>

using namespace ApprovalTests;

TEST_CASE("Test initialiseServices")
{
	logger.str("");
	initialiseServices();
	Approvals::verify(logger.str());
}
