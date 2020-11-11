#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"

#include <utility>

using namespace ApprovalTests;

// See https://approvaltestscpp.readthedocs.io/en/latest/
typedef double (TrigMath::*TrigMathMemFn)(double value);
#define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))

using Name = const char*;
using NameAndFunction = std::pair<Name, TrigMathMemFn>;
using NamesAndFunctions = std::vector<NameAndFunction>;

std::ostream &operator<<(std::ostream &out,
                         const NameAndFunction &name_and_function) {
  out << "&TrigMath::" + std::string(name_and_function.first);
  return out;
}

TEST_CASE("Demo combinations with pointer to member functions")
{
    TrigMath math;
    // Functions given in the same order as in the TrigMath.h header
    // (and copied in via column selection)
    const NamesAndFunctions functions{
        {"Sin", &TrigMath::Sin},
        {"Cos", &TrigMath::Cos},
        {"Tan", &TrigMath::Tan},
        {"Csc", &TrigMath::Csc},
        {"Sec", &TrigMath::Sec},
        {"Cot", &TrigMath::Cot},
        {"Asin", &TrigMath::Asin},
        {"Acos", &TrigMath::Acos},
        {"Atan", &TrigMath::Atan},
        // We can't test Atan2 this way as it takes 2 arguments
        //{"Atan2", &TrigMath::Atan2},
        {"Acsc", &TrigMath::Acsc},
        {"Asec", &TrigMath::Asec},
        {"Acot", &TrigMath::Acot}
    };

    const std::vector<double> values{1.0, 3.14, -0.1, 0, 0.2, 0.8};

    CombinationApprovals::verifyAllCombinations(
        [&math](auto &name_and_function, auto &value) {
          return CALL_MEMBER_FN(math, name_and_function.second)(value);
        },
        functions, values);
}
