#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#define TESTING

#include "Inconsistent.h"


using namespace ApprovalTests;

TEST_CASE("Scrub print")
{
	Inconsistent i;
	std::string s=i.print("somthing");
	// started at Tue Sep 29 15:30:12 2020 by somthing
	Approvals::verify(s, Options(Scrubbers::createRegexScrubber(R"(\w{3} \w{3} \d{2} \d{2}:\d{2}:\d{2} \d{4})", "[date and time]")));
}

TEST_CASE("Peel print")
{
	Inconsistent i;
	std::string s = i.print("somthing", ApprovalTests::DateUtils::createUtcDateTime(2020, 1, 2, 3, 4, 5));
	Approvals::verify(s);
}

TEST_CASE("Poke GetID")
{
	Inconsistent i;
	int x = i.getID();
	Approvals::verify(x);
}

TEST_CASE("GetID2")
{
	Inconsistent i;
	int x = i.getID2(0);
	Approvals::verify(x);
}

TEST_CASE("GetID3")
{
	Inconsistent i;
	int x = i.getID3(10);
	Approvals::verify(x);
}