#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include <sstream>

#include "SystemConfiguration.h"

#include <iostream>

#define PRINT(x) #x" = " << x << std::endl

using namespace ApprovalTests;

std::string printState()
{
	std::stringstream out;

	out << PRINT(rpm);
	out << PRINT(dt);
	out << PRINT(x);
	out << PRINT(y);
	out << PRINT(z);
	out << PRINT(x_mph);
	out << PRINT(y_mph);
	out << PRINT(z_mph);
	out << PRINT(gravity);
	out << PRINT(y_torque);

	return out.str();
}

void setAllGlobals(int rpm_t, double dt_t, double x_t, double y_t, double z_t, double x_mph_t, double y_mph_t, double z_mph_t, bool gravity_t, double y_torque_t)
{
	rpm = rpm_t;
	dt = dt_t;
	x = x_t;
	y = y_t;
	z = z_t;
	x_mph = x_mph_t;
	y_mph = y_mph_t;
	z_mph = z_mph_t;
	gravity = gravity_t;
	y_torque = y_torque_t;
}

void initializeGlobals()
{
	setAllGlobals(4000, 0.01, 0, 0, 0, 1, 2, 3, true, 3.2);
}



TEST_CASE("Test System Configuration 1")
{
}

TEST_CASE("generate code")
{
	//Approvals::verify(generateCode());
}

void verifyInitialSystem()
{
	std::string init = "Initial state\n";


	init += printState();
	initialiseSystem();

	init += "\nState after initialization\n";
	init += printState();

	Approvals::verify(init);
}
TEST_CASE("Initialise system")
{
	setAllGlobals(4000, 0.01, 0, 0, 0, 1, 2, 3, false, 3.2);
	verifyInitialSystem();	
}

TEST_CASE("Second test")
{
	setAllGlobals(4000, 0.01, 0, 0, 0, 1, 2, 3, true, 3.2);
	verifyInitialSystem();
}
TEST_CASE("After Gravity") {
	setAllGlobals(4000, 0.01, 4.58333e-08, 9.16667e-08, 0, 1, 2, 3, 0, 3.2);
	verifyInitialSystem();
}
