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

    std::string printName1a(const std::string& name)
    {
        std::stringstream stream;
        stream << "Hello " << name << '\n';
        auto output = stream.str();
        return output;
    }
	
    void printName1(const std::string& name)
    {
        std::cout << printName1a(name);
    }

    void printName2a(const std::string& name, std::ostream& stream)
    {
	    stream << "Hello " << name << '\n';
    }

    void printName2(const std::string& name)
    {
	    std::ostream& stream = std::cout;
        printName2a(name, stream);
    }
};
