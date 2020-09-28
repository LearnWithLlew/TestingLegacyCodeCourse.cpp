#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "SideEffects.h"

using namespace ApprovalTests;

TEST_CASE("Test SideEffects")
{
	SideEffects side;
	Approvals::verify(side.printName2("Clare"));
}

TEST_CASE("Test SideEffects with stream")
{
	SideEffects side;
	std::stringstream ss;
	side.printName4("Clare", ss);
	Approvals::verify(ss.str());

}

