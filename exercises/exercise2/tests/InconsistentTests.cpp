#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "Inconsistent.h"

using namespace ApprovalTests;

TEST_CASE("Poke GetID")
{
}

TEST_CASE("Poke print")
{
	Inconsistent inconsistent;
	Approvals::verify(inconsistent.print("Andrzej"), 
		Options(Scrubbers::createRegexScrubber(R"([a-zA-Z]+ [a-zA-Z]+ \d\d \d\d:\d\d:\d\d \d\d\d\d)", "[replacement]")));
}

TEST_CASE("Scrub print")
{
}
