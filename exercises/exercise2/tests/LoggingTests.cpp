#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#define RUNNING_TESTS
#include "InitialiseSystem.h"
//#include "Samples.h"

#include <iostream>

using namespace ApprovalTests;

TEST_CASE("Test initialiseServices")
{
    log_stream.clear();
    initialiseServices();
    Approvals::verify(log_stream.str());
}
