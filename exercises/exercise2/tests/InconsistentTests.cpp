#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "Inconsistent.h"

using namespace ApprovalTests;

TEST_CASE("Poke GetID")
{
	Inconsistent subject;
	
	Approvals::verify(subject.getID(0));
}

TEST_CASE("Poke print")
{
}

TEST_CASE("Scrub print")
{
}
