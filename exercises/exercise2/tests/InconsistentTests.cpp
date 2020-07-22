#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "Inconsistent.h"

using namespace ApprovalTests;

TEST_CASE("Poke GetID")
{
	Inconsistent inconsistent;
	REQUIRE(9 == inconsistent.getID(6));
}

TEST_CASE("Poke GetID with understanding")
{
	Inconsistent inconsistent;
	REQUIRE(6 == inconsistent.getID2(5));
	REQUIRE(6 == inconsistent.getID2(15));
}

TEST_CASE("Poke GetID with slice")
{
	Inconsistent inconsistent;
	int i = 3;
	auto count = [&]() {return i--; };
	// (3 -> [3 + 3 + 3] + 1)
	REQUIRE(10 == inconsistent.getID3([&]() {return 3; }));
	// (3 -> [2 + 1 + 0] + 1)
	REQUIRE(4 == inconsistent.getID3(count));
}

TEST_CASE("Scrub print")
{
	Inconsistent inconsistent;
	auto date = DateUtils::createDateTime(2000, 1, 2, 3, 4, 5);
	Approvals::verify(inconsistent.print("Clare", date));
}
