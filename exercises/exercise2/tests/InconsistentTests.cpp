#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "Inconsistent.h"

using namespace ApprovalTests;

TEST_CASE( "Scrub print" )
{
    Inconsistent incosistent;
    //started at Thu Jul  1 15:28:44 2021 by inconsistent
    auto result = incosistent.print("inconsistent");
    Approvals::verify(result,
                       Options(Scrubbers::createRegexScrubber(
                           R"(Thu Jul  1 \d{2}:\d{2}:\d{2} 2021)",
                                                                "[date_time_stamp]")));
}

TEST_CASE( "Peel print" )
{
}

TEST_CASE( "Poke GetID" )
{
}
