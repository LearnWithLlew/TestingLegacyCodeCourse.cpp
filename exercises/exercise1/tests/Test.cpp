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
    s << math.Acos(value) << "\n";
    s << math.Cos(value) << "\n";
    s << math.Acot(value) << "\n";
    s << math.Acsc(value) << "\n";
    s << math.Asec(value) << "\n";
    s << math.Asin(value) << "\n";
    s << math.Atan(value) << "\n";
    s << math.Cos(value) << "\n";
    s << math.Cot(value) << "\n";
    s << math.Csc(value) << "\n";
    s << math.Floor(value) << "\n";
    s << math.Sec(value) << "\n";
    s << math.Sin(value) << "\n";
    s << math.Tan(value) << "\n";


    return s.str();

}
TEST_CASE("Test Everything") {

    Approvals::verify(callEverything(3.4));
}