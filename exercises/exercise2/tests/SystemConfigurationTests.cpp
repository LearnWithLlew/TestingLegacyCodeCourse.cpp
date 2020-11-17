#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "SystemConfiguration.h"

#include <iostream>

#define PRINT(x) #x" = " << x << "\n"


using namespace ApprovalTests;

std::string captureCurrentState()
{
	std::stringstream output;
	output << PRINT(rpm);
	output << PRINT(dt);
	output << PRINT(x);
	output << PRINT(y);
	output << PRINT(z);
	output << PRINT(x_mph);
	output << PRINT(y_mph);
	output << PRINT(z_mph);
	output << PRINT(gravity);
	output << PRINT(y_torque);
	return output.str();
}

void setAllGlobals(int rpm_ = 4000, double dt_ = 0.01, double x_ = 0, double y_ = 0, double z_ = 0, double x_mph_ = 1,
					double y_mph_ = 2, double z_mph_ = 3, bool gravity_ = true, double y_torque_ = 3.2)
{
	rpm = rpm_;
	dt = dt_;
	x = x_;
	y = y_;
	z = z_;
	x_mph = x_mph_;
	y_mph = y_mph_;
	z_mph = z_mph_;
	gravity = gravity_;
	y_torque = y_torque_;
}

std::string generateCodeToSetGlobals()
{
	std::stringstream output;
	output << "setAllGlobals(";
	output << rpm << ", ";
	output << dt << ", ";
	output << x << ", ";
	output << y << ", ";
	output << z << ", ";
	output << x_mph << ", ";
	output << y_mph << ", ";
	output << z_mph << ", ";
	output << gravity << ", ";
	output << y_torque;
	output << ");";
	return output.str();
}

TEST_CASE("Test System Configuration 1")
{
	setAllGlobals();
	std::stringstream output;
	output << "Global State Before:\n";
	output << captureCurrentState();
	initialiseSystem();
	std::cout << generateCodeToSetGlobals();
	
	output << "\nGlobal State After:\n";
	output << captureCurrentState();
	Approvals::verify (output.str());
}

TEST_CASE("Test System Configuration 2")
{
	setAllGlobals();
	std::stringstream output;
	output << "Global State Before:\n";
	output << captureCurrentState();
	initialiseSystem();
	output << "\nGlobal State After:\n";
	output << captureCurrentState();
	Approvals::verify(output.str());
}

TEST_CASE("generate code")
{
}
