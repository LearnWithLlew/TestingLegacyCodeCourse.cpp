#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#define SECURE 1
#define TESTING
#include "Services.h"

#include <iostream>

using namespace ApprovalTests;

TEST_CASE( "Test initialiseServices" )
{
    logger.str("");
    initialiseServices();
    Approvals::verify(logger.str());
}

TEST_CASE("Test 2")
{
    logger.str("");
    initialiseServices();
    Approvals::verify(logger.str());
}