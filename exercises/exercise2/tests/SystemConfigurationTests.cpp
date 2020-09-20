#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "SystemConfiguration.h"

#include <iostream>
#define PRINT(x) #x" = " << x


using namespace ApprovalTests;

std::string getGlobalVariablesState()
{
	std::stringstream result;
	result << PRINT(rpm) << std::endl;
	result << PRINT(dt) << std::endl;
	result << PRINT(x) << std::endl;
	result << PRINT(y) << std::endl;
	result << PRINT(z) << std::endl;
	result << PRINT(x_mph) << std::endl;
	result << PRINT(y_mph) << std::endl;
	result << PRINT(z_mph) << std::endl;
	result << PRINT(gravity) << std::endl;
	result << PRINT(y_torque) << std::endl;
	return result.str();
	
}

std::string captureGlobalVariables()
{
	std::stringstream result;
	result << "setGlobalVars(" << rpm <<
		", " << dt << ", " << x << ", " << y << ", "
		<< z << ", " << x_mph << ", " << y_mph << ", " <<
		z_mph << ", " << gravity << ", " << y_torque << ");";
	return result.str();
}

void setGlobalVars(int newRpm, 
					double newDt, 
					double newX, 
					double newY, 
					double newZ,
					double newXMph,
					double newYMph,
					double newZMph,
					bool newGravity,
					double newYTorque)
{
	rpm = newRpm;
	dt = newDt;
	x = newX;
	y = newY;
	z = newZ;
	x_mph = newXMph;
	y_mph = newYMph;
	z_mph = newZMph;
	gravity = newGravity;
	y_torque = newYTorque;
}

std::string start(int rpm) {
    setGlobalVars(rpm, 0.01, 0, 0, 0, 1, 2, 3, true, 3.2);
    const auto before = getGlobalVariablesState();
    initialiseSystem();
    const std::string both = before + "\n" + getGlobalVariablesState();
    return both;
}

TEST_CASE("Test System Configuration 1")
{
    std::string both = start(4000);
    Approvals::verify(both);
}

TEST_CASE("Test System Configuration No Gravity")
{
	setGlobalVars(4000, 0.01, 0, 0, 0, 1, 2, 3, true, 3.2);
	gravity = false;
	const auto before = getGlobalVariablesState();
	initialiseSystem();
	Approvals::verify(before + "\n" + getGlobalVariablesState());
}

TEST_CASE("generate code")
{
	std::cout << captureGlobalVariables() << std::endl;
}
