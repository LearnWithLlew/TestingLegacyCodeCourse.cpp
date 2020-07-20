#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
//#include "Samples.h"

#include "Inconsistent.h"

using namespace ApprovalTests;

TEST_CASE("Poke GetID")
{
}

TEST_CASE("Poke print")
{
    Inconsistent inconsistent;
    Approvals::verify(inconsistent.print2("fred", DateUtils::createDateTime(2000, 01, 02, 3, 4, 5)));
}

TEST_CASE("Scrub print")
{
    Inconsistent inconsistent;
    Approvals::verify(inconsistent.print1("fred"), Options().withScrubber(Scrubbers::createRegexScrubber("fixme", "[date]")));
}
