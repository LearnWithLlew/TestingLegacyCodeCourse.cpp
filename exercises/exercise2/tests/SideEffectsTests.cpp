#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "SideEffects.h"

using namespace ApprovalTests;

TEST_CASE("Test SideEffects")
{
	SideEffects sideEffects;
	Approvals::verify(sideEffects.printName("name"));
}

TEST_CASE("Test SideEffects with stream")
{
	SideEffects se;
	std::stringstream s;
	se.printName22("Clare", s);
	Approvals::verify(s.str());

}

