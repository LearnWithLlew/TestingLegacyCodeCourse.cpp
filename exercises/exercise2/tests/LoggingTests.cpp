#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#define SECURE 1
#define ENABLE_FAKE_REST_CALL 1
#include "Services.h"

#include <iostream>

using namespace ApprovalTests;

TEST_CASE("Test initialiseServices2")
{
	logstream = std::stringstream{};
	initialiseServices();
	Approvals::verify(logstream.str());
}

TEST_CASE("Test initialiseServices")
{
	logstream = std::stringstream{};
	initialiseServices();
	Approvals::verify(logstream.str());
}
