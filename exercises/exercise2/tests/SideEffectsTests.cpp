#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "SideEffects.h"

using namespace ApprovalTests;

TEST_CASE("Test SideEffects")
{
	SideEffects side;
	Approvals::verify(side.printName1a("Oskar"));
}

TEST_CASE("Test SideEffects with stream")
{
	SideEffects side;
	std::stringstream os;
	side.printName2a("Oskar", os);
	Approvals::verify(os.str());
}

