#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"

using namespace ApprovalTests;



TEST_CASE("Test Sin") {
	TrigMath math;
	Approvals::verify(math.Sin(3.4));
}
TEST_CASE("Test Cos") {
	TrigMath math;
	Approvals::verify(math.Cos(3.4));
}
std::string callEverything(double value) {
	std::stringstream s;
	TrigMath math;
	s << "Acos (" << value << ") = " << math.Acos(value) << "\n";
	s << "Acot  (" << value << ") = " << math.Acot(value) << "\n";
	s << "Acsc (" << value << ") = " << math.Acsc(value) << "\n";
	s << "Asec (" << value << ") = " << math.Asec(value) << "\n";
	s << "Asin (" << value << ") = " << math.Asin(value) << "\n";
	s << "Atan (" << value << ") = " << math.Atan(value) << "\n";
	s << "Atan2 (" << value << ",0.4) = " << math.Atan2(value, 0.4) << "\n";
	s << "Cos (" << value << ") = " << math.Cos(value) << "\n";
	s << "Cot (" << value << ") = " << math.Cot(value) << "\n";
	s << "Csc (" << value << ") = " << math.Csc(value) << "\n";
	s << "Sec (" << value << ") = " << math.Sec(value) << "\n";
	s << "Sin  (" << value << ") = " << math.Sin(value) << "\n";
	s << "Tan  (" << value << ") = " << math.Tan(value) << "\n";


	return s.str();

}
TEST_CASE("Test Everything") {

	Approvals::verify(callEverything(1.0));
}
TEST_CASE("Test Everything 3.14") {

	Approvals::verify(callEverything(3.14));
}
TEST_CASE("Test Everything For both values") {
	std::vector < double> values = { 1.0, 3.14 };
	Approvals::verifyAll("TITLE", values, [](auto input, auto& stream) {
		stream << callEverything(input);
		});
}
TEST_CASE("Test Everything With Combinations") {
	std::vector < double> inputs1 = { -0.1,0.0, 1.0, 3.14 };
	CombinationApprovals::verifyAllCombinations(
		[](auto input1) { return callEverything(input1); }, inputs1);


}
TEST_CASE("Test Everything With Combinations for Atan2") {
	std::vector < double> inputs1 = { -0.1,0.0, 1.0, 3.14 };

	CombinationApprovals::verifyAllCombinations(
		[](auto input1, auto input2) { return TrigMath().Atan2(input1, input2); }, inputs1, inputs1);


}
TEST_CASE("Test Method Pointers") {
	typedef  double (TrigMath::* TrigMathMemFn)(double x);
#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))
	TrigMath math;
	TrigMathMemFn method = &TrigMath::Acos;
	REQUIRE(Approx(1.0471975512) == CALL_MEMBER_FN(math, method)(0.5));
}

typedef  double (TrigMath::* TrigMathMemFn)(double x);

template <>
std::string ApprovalTests::StringMaker::toString(const std::pair<const std::string, TrigMathMemFn>& printable)
{
	return "TrigMath::" + printable.first;
}

TEST_CASE("Test Everything With Combinations and Method Pointers") {
#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))
	TrigMath math;
	std::vector < double> inputs2 = { -0.1,0.0, 1.0, 3.14 };
	std::map <std::string, TrigMathMemFn> inputs1{ {"Sin",&TrigMath::Sin},
	{"Acos", &TrigMath::Acos},
	{ "Acot", &TrigMath::Acot },
	{ "Acsc", &TrigMath::Acsc },
	{ "Asec", &TrigMath::Asec },
	{ "Asin", &TrigMath::Asin },
	{ "Atan", &TrigMath::Atan },
	{ "Cos", &TrigMath::Cos },
	{ "Cot", &TrigMath::Cot },
	{ "Csc", &TrigMath::Csc },
	{"Sec",     &TrigMath::Sec},
	{"Sin",     &TrigMath::Sin},
	{"Tan",     &TrigMath::Tan}
	};

	CombinationApprovals::verifyAllCombinations(
		[&](auto input1, auto input2) { return  CALL_MEMBER_FN(math, input1.second)(input2); }, inputs1, inputs2);


}