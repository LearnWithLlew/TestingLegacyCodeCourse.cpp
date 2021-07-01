#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "TrigMath.h"
#include <sstream>
#include <cmath>

using namespace ApprovalTests;

TEST_CASE( "ApprovalTest Sin" )
{
    TrigMath math;
    Approvals::verify(math.Sin(1.20));
    Approvals::verify(math.Sin(1.20));
}

TEST_CASE( "ApprovalTest Cos" )
{
    TrigMath math;
    Approvals::verify(math.Cos(1.20));
}

std::string runEverything(double angle)
{
    std::stringstream Stream;
    TrigMath math;
    Stream << "math.Sin(angle)" << math.Sin(angle) << "\n";
    Stream << "math.Cos( angle ) " << math.Cos( angle ) << "\n";
    Stream << "math.Tan( angle ) " << math.Tan( angle )<< "\n";
    Stream << "math.Csc( angle ) " << math.Csc( angle )<< "\n";
    Stream << "math.Sec( angle ) " << math.Sec(  angle )<< "\n";
    Stream << "math.Cot( angle ) " << math.Cot( angle )<< "\n";
    Stream << "math.Asin( angle ) " << math.Asin( angle ) << '\n';
    Stream << "math.Acos( angle ) " << math.Acos( angle ) << '\n';
    Stream << "math.Atan( angle ) " << math.Atan( angle ) << '\n';
    Stream << "math.Atan2( angle, 0.4 ) " << math.Atan2( angle, 0.4 ) << '\n';
    Stream << "math.Acsc( angle ) " << math.Acsc( angle ) << '\n';
    Stream << "math.Asec( angle ) " << math.Asec( angle ) << '\n';
    Stream << "math.Acot( angle ) " << math.Acot( angle ) << '\n';

    return Stream.str();
}

TEST_CASE( "ApprovalTest runEverything" )
{
    Approvals::verify( runEverything(1.0));
}

TEST_CASE( "ApprovalTest runEverything(3.14)" )
{
    Approvals::verify( runEverything(3.14));
}



TEST_CASE("VerifyAllStartingPoint")
{
    std::vector<double> inputs{-0.1, 0, 0.2, 0.8, 1.0, 3.14};
    Approvals::verifyAll("TrigMath", inputs, [](auto input, auto& stream) {
      stream << "angle = " << input << " => \n"
             << runEverything(input);
    });
}

