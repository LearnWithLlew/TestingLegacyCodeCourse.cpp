#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#define TESTING 1

#include "Inconsistent.h"

using namespace ApprovalTests;

TEST_CASE("Scrub print")
{
	Inconsistent inc;
	
	Approvals::verify(inc.print("your name"),
		Options(Scrubbers::createRegexScrubber(R"([A-z]{3} [A-z]{3} \d{2} \d{2}:\d{2}:\d{2} \d{4})", 
			"[date_and_time]")));
}

TEST_CASE("Peel print")
{
	Inconsistent inc;

	auto example_time = ApprovalTests::DateUtils::createUtcDateTime(2222, 11, 1, 1, 2, 3);
	Approvals::verify(inc.print2("foo", example_time));
}

TEST_CASE("Poke GetID")
{
	Inconsistent inc;
	Approvals::verify(inc.get_id2(0));
}
