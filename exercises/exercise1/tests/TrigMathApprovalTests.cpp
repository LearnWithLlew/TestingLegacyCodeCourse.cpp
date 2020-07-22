#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"

using namespace ApprovalTests;

std::string runEverything(double val)
{
	TrigMath math;
	std::stringstream result;
	result << math.Sin(val) << std::endl;
	result << math.Asin(val) << std::endl;
	result << math.Cos(val) << std::endl;
	result << math.Tan(val) << std::endl;
	result << math.Csc(val) << std::endl;
	result << math.Sec(val) << std::endl;
	result << math.Cot(val) << std::endl;
	result << math.Acos(val) << std::endl;
	result << math.Atan(val) << std::endl;
	result << math.Atan2(val,0.4) << std::endl;
	result << math.Acsc(val) << std::endl;
	result << math.Asec(val) << std::endl;
	result << math.Acot(val) << std::endl;
	return result.str();
}

TEST_CASE("ApprovalTest everything") {
	Approvals::verify(runEverything(1.0));
}

TEST_CASE("ApprovalTest Sin") {
    TrigMath math;
	Approvals::verify(math.Sin(0.4));
}

TEST_CASE("ApprovalTest Cos") {
    TrigMath math;
	Approvals::verify(math.Cos(0.4));
}
