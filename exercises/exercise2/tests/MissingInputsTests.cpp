#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "MissingInputs.h"

TEST_CASE("Test MissingInputs")
{
	MissingInputs mi;
	ApprovalTests::Approvals::verify(mi.getCategory());
}

TEST_CASE("Test MissingInputs2")
{
	MissingInputs mi;
	ApprovalTests::Approvals::verify(mi.getCategory(5));
}
