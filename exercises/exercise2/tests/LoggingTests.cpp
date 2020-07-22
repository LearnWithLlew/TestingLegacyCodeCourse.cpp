#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#define SECURE 1
#define LOGGING_TEST
#include "Services.h"

#include <iostream>

using namespace ApprovalTests;

TEST_CASE("Test initialiseServices")
{
	logger.str("");
	logger.clear();
	initialiseServices();
	Approvals::verify(logger.str());
}

TEST_CASE("Test initialiseServices 2")
{
	logger.str("");
	logger.clear();
	initialiseServices();
	Approvals::verify(logger.str());
}
