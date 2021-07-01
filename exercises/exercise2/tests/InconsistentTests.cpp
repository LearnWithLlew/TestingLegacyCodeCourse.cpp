#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#define TESTING
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
    Inconsistent inconsistent;

   auto const res = inconsistent.printWithDate(
        "name", DateUtils::createUtcDateTime( 2000, 2, 1, 3, 4, 5 ) );
   Approvals::verify(res);

}

TEST_CASE( "Poke GetID" )
{
    Inconsistent inconsistent;
    Approvals::verify(inconsistent.getIDWithSeed(0));

}
