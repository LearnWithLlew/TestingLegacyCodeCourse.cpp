#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include <sstream>

#include "SystemConfiguration.h"

#include <iostream>

using namespace ApprovalTests;

#define PRINT(x) #x" = " << x << std::endl;
void printGlobals(std::stringstream& ss){
    ss << PRINT(rpm);
    ss << PRINT(dt);
    ss << PRINT(x);
    ss << PRINT(y);
    ss << PRINT(z);
    ss << PRINT(x_mph);
    ss << PRINT(y_mph);
    ss << PRINT(z_mph);
    ss << PRINT(gravity);
    ss << PRINT(y_torque);
}

void setAllGlobals(
    int rpm_ = 4000,
    double dt_ = 0.01,
    double x_ = 0,
    double y_ = 0,
    double z_ = 0,
    double x_mph_ = 1,
    double y_mph_ = 2,
    double z_mph_ = 3,
    bool gravity_ = true,
    double y_torque_ = 3.2)
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

TEST_CASE( "Test System Configuration 1" )
{
    std::stringstream ss;
    ss << "Before initialiseSystem\n";
    setAllGlobals();
    printGlobals(ss);
    initialiseSystem();
    ss << "After initialiseSystem\n";
    printGlobals(ss);

    Approvals::verify(ss.str());
}

TEST_CASE( "hgfhgfhgTest System Configuration 2" )
{
    std::stringstream ss;
    ss << "Before initialiseSystem\n";

    setAllGlobals();
    printGlobals(ss);

    initialiseSystem();
    ss << "After initialiseSystem\n";
    printGlobals(ss);

    Approvals::verify(ss.str());
}

std::string generateCodeToSetGlobals()
{
    std::stringstream ss;
    ss << "setAllGlobals(";
    ss << rpm << ", ";
    ss << dt << ", ";
    ss << x << ", ";
    ss << y << ", ";
    ss << z << ", ";
    ss << x_mph << ", ";
    ss << y_mph << ", ";
    ss << z_mph << ", ";
    ss << std::boolalpha << gravity << ", ";
    ss << y_torque << ");";
    return ss.str();
}

TEST_CASE( "generate code" )
{
    setAllGlobals();
    Approvals::verify(generateCodeToSetGlobals());
}

TEST_CASE( "gravity off" )
{
    setAllGlobals(6000, 0.01, 0, 0, 0, 1, 2, 3, false, 3.2);
    Approvals::verify(generateCodeToSetGlobals());
}
