#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace ApprovalTests;



TEST_CASE("ApprovalTest Sin") {
    TrigMath math;
    auto result = math.Sin(0.0);
    Approvals::verify(result);
}

TEST_CASE("ApprovalTest Cos") {
    TrigMath math;
    auto result = math.Cos(0.0);
    Approvals::verify(result);
}

std::string runEverything(double num)
{
    TrigMath math;
    std::stringstream ss;
    ss << "Cos: " << math.Cos(num) << '\n';
    ss << "Sin: " << math.Sin(num) << '\n';
    ss << "Asin: " << math.Asin(num) << '\n';
    ss << "Acos: " << math.Acos(num) << '\n';
    ss << "Acot: " << math.Acot(num) << '\n';
    ss << "Acsc: " << math.Acsc(num) << '\n';
    ss << "Asec: " << math.Asec(num) << '\n';
    ss << "Atan: " << math.Atan(num) << '\n';
    ss << "Atan2: " << math.Atan2(num,0.4) << '\n';
    ss << "Cot: " << math.Cot(num) << '\n';
    ss << "Csc: " << math.Csc(num) << '\n';
    ss << "Sec: " << math.Sec(num) << '\n';
    ss << "Tan: " << math.Tan(num) << '\n';

    return ss.str();
}

TEST_CASE("ApprovalTest Everything 1.0") 
{
    Approvals::verify(runEverything(1.0));
}

TEST_CASE("ApprovalTest Everything 3.14")
{
    Approvals::verify(runEverything(3.14));
}

TEST_CASE("ApprovalTest All")
{
    std::vector<double> inputs{ 1.0, 3.14 , -0.1, 0, 0.2, 0.8 };
    Approvals::verifyAll("TITLE", inputs, [](auto input, auto& stream) {
        stream << input << " => "
            << runEverything(input);
        });
}