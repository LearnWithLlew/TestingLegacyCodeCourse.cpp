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
    s << "Acot  (" << value << ") = " <<  math.Acot(value) << "\n";
    s << "Acsc (" << value << ") = " <<  math.Acsc(value) << "\n";
    s << "Asec (" << value << ") = " <<  math.Asec(value) << "\n";
    s << "Asin (" << value << ") = " <<  math.Asin(value) << "\n";
    s << "Atan (" << value << ") = " <<  math.Atan(value) << "\n";
    s << "Atan2 (" << value << ",0.4) = " <<  math.Atan2(value,0.4) << "\n";
    s << "Cos (" << value << ") = "<< math.Cos(value) << "\n";
    s << "Cot (" << value << ") = " <<  math.Cot(value) << "\n";
    s << "Csc (" << value << ") = " <<  math.Csc(value) << "\n";
    s << "Floor (" << value << ") = " <<  math.Floor(value) << "\n";
    s << "Sec (" << value << ") = " <<  math.Sec(value) << "\n";
    s << "Sin  (" << value << ") = " <<  math.Sin(value) << "\n";
    s << "Tan  (" << value << ") = " <<  math.Tan(value) << "\n";


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
    std::vector < double> inputs1 = {-0.1,0.0, 1.0, 3.14 };

    CombinationApprovals::verifyAllCombinations(
        [](auto input1, auto input2) { return TrigMath ().Atan2(input1, input2); }, inputs1, inputs1);

   
}