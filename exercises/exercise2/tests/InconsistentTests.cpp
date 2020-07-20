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
    CHECK(inconsistent.print("fred") == "started at Sun Jul 19 22:51:46 2020 by fred");
}
