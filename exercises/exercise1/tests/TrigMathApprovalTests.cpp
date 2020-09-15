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

#define PRINT(Func) ss << #Func"(" <<num << ") " << math.Func(num) << '\n'
#define PRINT1(Func) PRINT(num)
#define PRINT2(Func) PRINT1(num,num2)

std::string runEverything(double num)
{
    TrigMath math;
    std::stringstream ss;

    /*const auto runOne = [&](std::string name, double(TrigMath::*func)(double)) {
        ss << name << "(" << num << ") " << answer << '\n';
    };*/

    PRINT(Cos);
    ss << "Sin(" << num << ") " << math.Sin(num) << '\n';
    ss << "Asin: (" << num << ") " << math.Asin(num) << '\n';
    ss << "Acos: (" << num << ") " << math.Acos(num) << '\n';
    ss << "Acot: (" << num << ") " << math.Acot(num) << '\n';
    ss << "Acsc: (" << num << ") " << math.Acsc(num) << '\n';
    ss << "Asec: (" << num << ") " << math.Asec(num) << '\n';
    ss << "Atan: (" << num << ") " << math.Atan(num) << '\n';
    ss << "Atan2: (" << num << ") " << math.Atan2(num,0.4) << '\n';
    ss << "Cot: (" << num << ") " << math.Cot(num) << '\n';
    ss << "Csc: (" << num << ") " << math.Csc(num) << '\n';
    ss << "Sec: (" << num << ") " << math.Sec(num) << '\n';
    ss << "Tan: (" << num << ") " << math.Tan(num) << '\n';

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
    std::vector<double> inputs{ 1.0, 3.14, -0.1, 0, 0.2, 0.8 };
    Approvals::verifyAll("TITLE", inputs, [](auto input, auto& stream) {
        stream << input << " => "
            << runEverything(input);
        });
}