#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "Inconsistent.h"

using namespace ApprovalTests;

TEST_CASE("Scrub print")
{
	Inconsistent inc;
	// Tue Nov 24 16:09:57 2020
	Approvals::verify(inc.print("Oscar"), Options(Scrubbers::createRegexScrubber(R"([A-Z][a-z]{2} [A-Z][a-z]{2} \d{2} \d{2}:\d{2}:\d{2} \d{4})", "[time]")));
}

TEST_CASE("Peel print")
{
	Inconsistent inc;
	
	Approvals::verify(inc.print("Oskar", ApprovalTests::DateUtils::createUtcDateTime(2000, 2, 3, 4, 5, 6)));
}

TEST_CASE("Poke GetID")
{
	Inconsistent inc;
	Approvals::verify(inc.getID(0));
}

TEST_CASE("Poke GetID2")
{
	Inconsistent inc;
	Approvals::verify(inc.getID2(5));
}
