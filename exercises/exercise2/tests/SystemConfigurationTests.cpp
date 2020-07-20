#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "SystemConfiguration.h"

#include <iostream>

using namespace ApprovalTests;


void defineGlobalVariables(int arpm, double adt, double ax, double ay, double az, double ax_mph, double ay_mph, double az_mph, bool agravity, double ay_torque)
{
    rpm = arpm;
    dt = adt;
    x = ax;
    y = ay;
    z = az;
    x_mph = ax_mph;
    y_mph = ay_mph;
    z_mph = az_mph;
    gravity = agravity;
    y_torque = ay_torque;
}

#define PRINT(x) ss <<  #x" = " << x << "\n"

std::string printAllGlobals()
{
    std::stringstream ss;
    PRINT(rpm);
    PRINT(dt);
    PRINT(x);
    PRINT(y);
    PRINT(z);
    PRINT(x_mph);
    PRINT(y_mph);
    PRINT(z_mph);
    PRINT(gravity);
    PRINT(y_torque);

    return ss.str();
}

std::string captureAllGlobals()
{
    std::stringstream ss;
    ss << "defineGlobalVariables(" << rpm << ","
        << dt << ","
        << x << ","
        << y << ","
        << z << ","
        << x_mph << ","
        << y_mph << ","
        << z_mph << ","
        << gravity << ","
        << y_torque << ");";
    return ss.str();
}


TEST_CASE("Test System Configuration 1")
{
	defineGlobalVariables(
	4000,
	0.01,
	0,
	0,
	0,
	1,
	2,
	3,
	true,
	3.2
	);
	const auto before = printAllGlobals();
	initialiseSystem();
	const auto after = printAllGlobals();
	Approvals::verify("BEFORE:\n" + before + "\nAFTER:\n" + after);
}

TEST_CASE("Test System Configuration 2")
{
	defineGlobalVariables(4000, 0.01, 4.58333e-08, 9.16667e-08, 1.375e-07, 1, 2, 3, 1, 3.2);

	const auto before = printAllGlobals();
	initialiseSystem();
	const auto after = printAllGlobals();
	Approvals::verify("BEFORE:\n" + before + "\nAFTER:\n" + after);
}

TEST_CASE("generate code")
{
}

