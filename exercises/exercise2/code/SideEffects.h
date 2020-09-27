#pragma once

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

class SideEffects
{
public:
    // Not all outputs passed out
    void printName(const std::string& name)
    {
        std::cout << "Hello " << name << '\n';
    }
};
