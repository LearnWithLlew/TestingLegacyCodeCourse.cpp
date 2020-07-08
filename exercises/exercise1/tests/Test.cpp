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
    s << "TrigMath (" << value << ") \n";
    s << "Acos " << math.Acos(value) << "\n";
    s << "Acot " << math.Acot(value) << "\n";
    s << "Acsc " << math.Acsc(value) << "\n";
    s << "Asec " << math.Asec(value) << "\n";
    s << "Asin " << math.Asin(value) << "\n";
    s << "Atan " << math.Atan(value) << "\n";
    s << "Cos " << math.Cos(value) << "\n";
    s << "Cot " << math.Cot(value) << "\n";
    s << "Csc " << math.Csc(value) << "\n";
    s << "Floor " << math.Floor(value) << "\n";
    s << "Sec " << math.Sec(value) << "\n";
    s << "Sin " << math.Sin(value) << "\n";
    s << "Tan " << math.Tan(value) << "\n";


    return s.str();

}
TEST_CASE("Test Everything") {

    Approvals::verify(callEverything(1.0));
}