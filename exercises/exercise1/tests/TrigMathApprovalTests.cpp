#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"

using namespace ApprovalTests;


std::string runEverything(double value) {
    std::stringstream ss;
    TrigMath math;

    const auto toString = [&](double result_value, const char* method) {
        ss << method  <<"(" << value << ") == " << result_value << std::endl;
    };
    toString(math.Sin(value), "Sin");
    toString(math.Cos(value), "Cos");

    toString(math.Tan(value), "Tan");
    toString(math.Csc(value), "Csc");

    toString(math.Sec(value), "Sec");
    toString(math.Cot(value), "Cot");

    toString(math.Asin(value), "Asin");
    toString(math.Acos(value), "Acos");

    toString(math.Atan(value), "Atan");
    toString(math.Acsc(value), "Acsc");

    toString(math.Asec(value), "Asec");
    toString(math.Acot(value), "Acot");

    toString(math.Atan2(value, 0.4), "Atan2");
    return ss.str();
}


TEST_CASE("ApprovalTest Sin") {
    TrigMath math;
    Approvals::verify(math.Sin(0.0));
}


TEST_CASE("ApprovalTest Cos") {
    TrigMath math;
    Approvals::verify(math.Cos(0.0));
}


TEST_CASE("ApprovalTest RunEverything") {
    Approvals::verify(runEverything(1.0));
}


TEST_CASE("ApprovalTest RunEverything3.14") {
    Approvals::verify(runEverything(3.14));
}

TEST_CASE("ApprovalTest all maths")
{
    const std::vector<double> inputs{ 1.0, 3.14, 0.1, 0.9, -0.5, 0 };
    Approvals::verifyAll("TrigMath", inputs, [](auto input, auto& stream) {
        stream << input << " =>\n"
            << runEverything(input);
        });
}