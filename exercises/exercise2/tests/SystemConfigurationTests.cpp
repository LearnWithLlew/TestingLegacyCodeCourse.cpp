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

TEST_CASE("Test System Configuration 1")
{
	const auto before = getGlobalVariablesState();
	initialiseSystem();
	Approvals::verify(before + "\n" + getGlobalVariablesState());
}

TEST_CASE("generate code")
{
}
