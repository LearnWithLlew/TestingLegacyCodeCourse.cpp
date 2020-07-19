#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
//#include "Samples.h"

#include "Inconsistent.h"

using namespace ApprovalTests;

TEST_CASE("Poke GetID")
{
//    randomSeed = 500;
    randSeedStatic() = 500;
    CHECK(500 == randSeedStatic());

    Inconsistent inconsistent;
    CHECK(inconsistent.getIdForRandom(502) == 3);

//    srand(500);
    CHECK(inconsistent.getID0() == 2);
    CHECK(inconsistent.getID0() == 1);
    CHECK(inconsistent.getID(500) == 2);
}

TEST_CASE("Poke print")
{
    Inconsistent inconsistent;
    CHECK(inconsistent.print() == "started at Sun Jul 19 22:51:46 2020\n");
}
