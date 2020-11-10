#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"

using namespace ApprovalTests;
using namespace std;


//TEST_CASE("ApprovalTest Sin") {
//    TrigMath math;
//	Approvals::verify(math.Sin(0.5));
//}
//
//TEST_CASE("ApprovalTest Cos") {
//	TrigMath math;
//	Approvals::verify(math.Cos(0.5));
//}

std::string runEverything(double input) {
	TrigMath math;
	std::stringstream outputStream;
	outputStream << "Sin: " << math.Sin(input)<< "\n";
	outputStream << "Cos: " << math.Cos(input) << "\n";
	outputStream << "Acos: " << math.Acos(input) << "\n";
	outputStream << "Asin: "<< math.Asin(input) << "\n";
	outputStream << "Acot: " << math.Acot(input) << "\n";
	outputStream << "Acsc: " << math.Acsc(input) << "\n";
	outputStream << "Asec: " << math.Asec(input) << "\n";
	outputStream << "Atan: " << math.Atan(input) << "\n";
	outputStream << "Atan2: " << math.Atan2(input, input) << "\n";
	outputStream << "Cot: " << math.Cot(input) << "\n";
	outputStream << "Csc: " << math.Csc(input) << "\n";
	outputStream << "Sec: " << math.Sec(input) << "\n";
	outputStream << "Tan: " << math.Tan(input) << "\n";

	return outputStream.str();
}

//TEST_CASE("ApprovalTest run everything") {
//	Approvals::verify(runEverything(1.0));
//}
//
//TEST_CASE("ApprovalTest run everything with pi") {
//	Approvals::verify(runEverything(3.14));
//}

TEST_CASE("ApprovalTest run everything combined")
{
	std::vector<double> inputs{ 3.14, 1.0, -0.1, 0, 0.2, 0.8 };
	Approvals::verifyAll("Combination test", inputs, [](auto input, auto& stream) {
		stream << input << " =>\n" << runEverything(input);
			
		});
}

TEST_CASE("CombinationsStartingPoint")
{
	TrigMath math;
	std::vector<double> inputs1{ 3.14, 1.0, -0.1, 0, 0.2, 0.8 };
	std::vector<double> inputs2{ 3.14, 1.0, -0.1, 0, 0.2, 0.8 };
	
	CombinationApprovals::verifyAllCombinations(
		[&](auto input1, auto input2) { return math.Atan2(input1, input2); }, inputs1, inputs2);
}
