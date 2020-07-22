#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"

using namespace ApprovalTests;

std::string runEverything(double val)
{
	TrigMath math;
	std::stringstream result;
	result << "Sin( " << val << " ) = " << math.Sin(val) << std::endl;
	result << "Asin( " << val << " ) = " << math.Asin(val) << std::endl;
	result << "Cos( " << val << " ) = " << math.Cos(val) << std::endl;
	result << "Tan( " << val << " ) = " << math.Tan(val) << std::endl;
	result << "Csc( " << val << " ) = " << math.Csc(val) << std::endl;
	result << "Sec( " << val << " ) = " << math.Sec(val) << std::endl;
	result << "Cot( " << val << " ) = " << math.Cot(val) << std::endl;
	result << "Acos( " << val << " ) = " << math.Acos(val) << std::endl;
	result << "Atan( " << val << " ) = " << math.Atan(val) << std::endl;
	result << "Atan2( "<< val << ", 0.4 ) = " << math.Atan2(val,0.4) << std::endl;
	result << "Acsc( " << val << " ) = " << math.Acsc(val) << std::endl;
	result << "Asec( " << val << " ) = " << math.Asec(val) << std::endl;
	result << "Acot( " << val << " ) = " << math.Acot(val) << std::endl;
	return result.str();
}

TEST_CASE("ApprovalTest everything") {
	Approvals::verify(runEverything(1.0));
}
TEST_CASE("ApprovalTest everything PI") {
	Approvals::verify(runEverything(3.14));
}

TEST_CASE("ApprovalTest Sin") {
    TrigMath math;
	Approvals::verify(math.Sin(0.4));
}

TEST_CASE("ApprovalTest Cos") {
    TrigMath math;
	Approvals::verify(math.Cos(0.4));
}
