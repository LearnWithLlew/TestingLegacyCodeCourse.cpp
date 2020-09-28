#pragma once

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

class SideEffects
{
public:
    // Not all outputs passed out
    void printName0(const std::string& name)
    {
        std::cout << "Hello " << name << '\n';
    }

    void printName1(const std::string& name)
    {
        std::cout << "Hello " << name << '\n';
    }

    void printName2(const std::string& name)
    {
        std::cout << "Hello " << name << '\n';
    }
};
