#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "SystemConfiguration.h"

#include <iostream>
#include <sstream>

using namespace ApprovalTests;
#define PRINT(x) ss << #x " " << x << std::endl;


std::string printGlobals() {

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

void setAllGlobals(int _rpm = 4000,
double _dt = 0.01,
double _x = 0,
double _y = 0,
double _z = 0,
double _x_mph = 1,
double _y_mph = 2,
double _z_mph = 3,
bool _gravity = true,
double _y_torque = 3.2
) {
	rpm = _rpm;
	dt = _dt;
	x = _x;
	y = _y;
	z = _z;
	x_mph = _x_mph;
	y_mph = _y_mph;
	z_mph = _z_mph;
	gravity = _gravity;
	y_torque = _y_torque;
}

std::string GenerateCode()
{
	std::stringstream ss;
	ss << "setAllGlobals("
		<< rpm << ", "
		<< dt << ", "
		<< x << ", "
		<< y << ", "
		<< z << ", "
		<< x_mph << ", "
		<< y_mph << ", "
		<< z_mph << ", "
		<< gravity << ", "
		<< y_torque << ");";
	return ss.str();
}

TEST_CASE("Test System Configuration 1")
{
	std::stringstream ss;
	setAllGlobals(4000, 0.01);
	ss << "Initial State: " << std::endl;
	ss << printGlobals();
	initialiseSystem();

	ss << "Modified State: " << std::endl;
	ss << printGlobals();
	Approvals::verify(ss.str());
}


TEST_CASE("Test System Configuration 2")
{
	std::stringstream ss;
	setAllGlobals(4000, 0.01, 4.58333e-08,9.16667e-08,1.375e-07);
	ss << "Initial State: " << std::endl;
	ss << printGlobals();
	initialiseSystem();

	ss << "Modified State: " << std::endl;
	ss << printGlobals();
	Approvals::verify(ss.str());
}



TEST_CASE("generate code")
{
	setAllGlobals(4000, 0.01, 9.16666e-08, 1.83333e-07, 2.75e-07, 1, 2, 3, 1, 3.2);
	Approvals::verify(GenerateCode());
}
