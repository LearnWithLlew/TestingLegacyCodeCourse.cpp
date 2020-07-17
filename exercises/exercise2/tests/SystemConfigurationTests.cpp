#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"

#include "SystemConfiguration.h"
//#include "Samples.h"

#include <iostream>

using namespace ApprovalTests;


// Delete before using
std::string printConfig() {
    std::stringstream output;
    output << "rpm = " << rpm << '\n';
    output << "dt = " << dt << '\n';
    output << "x = " << x << '\n';
    output << "y = " << y << '\n';
    output << "z = " << z << '\n';
    output << "x_mph = " << x_mph << '\n';
    output << "y_mph = " << y_mph << '\n';
    output << "z_mph = " << z_mph << '\n';
    output << "gravity = " << gravity << '\n';
    output << "y_torque = " << y_torque << '\n';
    return output.str();
}

void initialiseConfig(
        int rpm_,
        double dt_,
        double x_,
        double y_,
        double z_,
        double x_mph_,
        double y_mph_,
        double z_mph_,
        bool gravity_,
        double y_torque_) {
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

std::string captureConfig() {
    std::stringstream output;
    output << "initialiseConfig("
           << rpm << ','
           << dt << ','
           << x << ','
           << y << ','
           << z << ','
           << x_mph << ','
           << y_mph << ','
           << z_mph << ','
           << gravity << ','
           << y_torque << ')'
           << ';';
    return output.str();
}

TEST_CASE("Test System Configuration 1") {
    initialiseConfig(4000, 0.01, 0, 0, 0, 1, 2, 3, 1, 3.2);
    std::stringstream output;
    output << "Starting Config\n" << printConfig();
    initialiseSystem();
    output << '\n';
    output << "Ending Config\n" << printConfig();
    Approvals::verify(output.str());
}

TEST_CASE("Test System Configuration 2") {
    initialiseConfig(4000, 0.01, 0, 0, 0, 1, 2, 3, 1, 3.2);
    std::stringstream output;
    output << "Starting Config\n" << printConfig();
    initialiseSystem();
    output << '\n';
    output << "Ending Config\n" << printConfig();
    Approvals::verify(output.str());
}

/*
 * Ideas
 * - Make multiple functions that touch different pieces of the config to show re-use
 * - Make tests that have to call different combinations of those functions
 * - Make ability to capture and re-load, by generating code
 */

TEST_CASE("generate code") {
    //std::cout << captureConfig() ;
    initialiseConfig(4000, 0.01, 0, 0, 0, 1, 2, 3, 1, 3.2);
}
