#pragma once

#include <string>
#include <sstream>

int rpm = 4000;
double dt = 0.01;
double x = 0;
double y = 0;
double z = 0;
double x_mph = 1;
double y_mph = 2;
double z_mph = 3;
bool gravity = true;
double y_torque = 3.2;

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

void initialiseSystem()
{
    if ( gravity )
    {
        double dx = x_mph / (60 * 60 * rpm);
        double dy = y_mph / (60 * 60 * rpm);
        for ( int i = 1; i <= rpm / 60; ++i)
        {
            x += dt * dx;
            y += dt * dy;
            z += dt * z_mph / (60 * 60 * rpm);
        }
    }
    else
    {
        double dx = x_mph / (60 * 60 * rpm);
        double dy = y_mph / (60 * 60 * rpm);
        for ( int i = 1; i <= rpm / 60; ++i)
        {
            x += dt * dx;
            y += dt * dy;
        }
    }
}
